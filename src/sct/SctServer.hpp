/**
 * @Author: jakub
 * @Date:   2018-01-26T13:23:22+01:00
 * @Project: Calculator with SCT
 * @Last modified by:   jakub
 * @Last modified time: 2018-01-26T13:23:46+01:00
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

    void handle_post( http_request message );
    void initializeListener();
    void shutdownListener();
};
};
