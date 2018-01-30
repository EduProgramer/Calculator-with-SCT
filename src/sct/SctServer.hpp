/**
 * @Author: jakub
 * @Project: Calculator with SCT
 * @License: MIT
 */

#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "cpprest/asyncrt_utils.h"
#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "cpprest/uri.h"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#else
#include <sys/time.h>
#endif

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class CalculatorWindow;

class SctServer
{
public:
    SctServer( CalculatorWindow& );
    ~SctServer();

private:
    CalculatorWindow& calculatorWindow;
    http_listener m_listener;

    std::string current_input;
    bool badServerInput = false;
    bool unknownInput = false;

    void handle_input();
    void resetInputErrorFlags();
    void handle_post( http_request message );
    json::value getStateAsJson();
};
