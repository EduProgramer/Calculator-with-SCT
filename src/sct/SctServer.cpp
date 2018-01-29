/**
 * @Author: jakub
 * @Date:   2018-01-26T13:23:22+01:00
 * @Project: Calculator with SCT
 * @Last modified by:   jakub
 * @Last modified time: 2018-01-26T13:23:46+01:00
 * @License: MIT
 */

#include "SctServer.hpp"
#include "../CalculatorWindow.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

SctServer::SctServer( CalculatorWindow& calculatorWindow )
    : calculatorWindow{ calculatorWindow }
{
    utility::string_t port = U( "34568" );
    utility::string_t address = U( "http://localhost:" );
    address.append( port );

    uri_builder uri( address );
    uri.append_path( U( "SctServer/Action/" ) );

    auto addr = uri.to_uri().to_string();
    m_listener = http_listener( addr );

    m_listener.support(
        methods::POST,
        std::bind( &SctServer::handle_post, this, std::placeholders::_1 ) );

    m_listener.open().wait();

    ucout << utility::string_t( U( "Listening for requests at: " ) ) << addr
          << std::endl;
}

SctServer::~SctServer()
{
    m_listener.close().wait();
    return;
}

void SctServer::handle_post( http_request message )
{
    ucout << message.to_string() << endl;

    // TODO add event handling

    utility::string_t screenState = calculatorWindow.getScreenState();

    message.reply( status_codes::OK, web::json::value::parse( screenState ) );
};

    return;
}

{

void SctServer::handle_post( http_request message )
{
}

{

