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

void SctServer::handle_input( std::string input )
{
    resetInputErrorFlags();
    // TODO Refactoring
    if ( not( input.size() == 1 ) )
    {
        badServerInput = true;
    }

    char keySymbol = input.front();

    // TODO add library for logging input, and errors localy

    switch ( keySymbol )
    {
        case '+':
            calculatorWindow.on_inputOperPlus_clicked();
            break;
        case '-':
            calculatorWindow.on_inputOperMinus_clicked();
            break;
        case '*':
            calculatorWindow.on_inputOperMulti_clicked();
            break;
        case '/':
            calculatorWindow.on_inputOperDivis_clicked();
            break;
        case '0':
            // TODO add support for 0
            break;
        case '1':
            calculatorWindow.on_inputNum1_clicked();
            break;
        case '2':
            calculatorWindow.on_inputNum2_clicked();
            break;
        case '3':
            calculatorWindow.on_inputNum3_clicked();
            break;
        case '4':
            calculatorWindow.on_inputNum4_clicked();
            break;
        case '5':
            calculatorWindow.on_inputNum5_clicked();
            break;
        case '6':
            calculatorWindow.on_inputNum6_clicked();
            break;
        case '7':
            calculatorWindow.on_inputNum7_clicked();
            break;
        case '8':
            calculatorWindow.on_inputNum8_clicked();
            break;
        case '9':
            calculatorWindow.on_inputNum9_clicked();
            break;
        default:
            unknownInput = true;
            break;
    }

    return;
}

void SctServer::resetInputErrorFlags()
{
    badServerInput = false;
    unknownInput = false;
}

void SctServer::handle_post( http_request message )
{
    handle_input( message.extract_utf8string().get() );
    message.reply( status_codes::OK, getStateAsJson() );
}

json::value SctServer::getStateAsJson()
{
    utility::string_t screenState = calculatorWindow.getScreenState();
    auto state = json::value::object();
    state["screenState"] = json::value::string( screenState );
    state["badServerInput"] = json::value::boolean( badServerInput );
    state["unknownInput"] = json::value::boolean( unknownInput );

    // TODO chck if relase is made with SCT server
    return state;
}
