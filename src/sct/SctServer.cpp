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
}

/*
SctServer::SctServer( utility::string_t url ) : m_listener( url )
{
    m_listener.support(
        methods::GET,
        std::bind( &SctServer::handle_get, this, std::placeholders::_1 ) );
    m_listener.support(
        methods::PUT,
        std::bind( &SctServer::handle_put, this, std::placeholders::_1 ) );
    m_listener.support(
        methods::POST,
        std::bind( &SctServer::handle_post, this, std::placeholders::_1 ) );
    m_listener.support(
        methods::DEL,
        std::bind( &SctServer::handle_delete, this, std::placeholders::_1 ) );
}

void SctServer::handle_get( http_request message )
{
    ucout << message.to_string() << endl;
    message.reply( status_codes::OK );
};

void SctServer::handle_post( http_request message )
{
    ucout << message.to_string() << endl;
    message.reply( status_codes::OK );
};

void SctServer::handle_delete( http_request message )
{
    ucout << message.to_string() << endl;
    message.reply( status_codes::OK );
}

void SctServer::handle_put( http_request message )
{
    ucout << message.to_string() << endl;

    auto paths =
        uri::split_path( uri::decode( message.relative_uri().path() ) );
    auto query =
        uri::split_query( uri::decode( message.relative_uri().query() ) );
    auto queryItr = query.find( U( "request" ) );
    utility::string_t request = queryItr->second;
    ucout << request << endl;

    if ( request == U( "leave" ) )
    {
        Data data;
        data.job = U( "Devs" );
        People p1;
        p1.age = 10;
        p1.name = U( "Franck" );
        data.peoples.push_back( p1 );
        People p2;
        p2.age = 20;
        p2.name = U( "Joe" );
        data.peoples.push_back( p2 );

        utility::string_t response = data.AsJSON().serialize();
        ucout << response << endl;

        message.reply( status_codes::OK, data.AsJSON() );
        return;
    }

    message.reply( status_codes::OK );
};*/
