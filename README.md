# offcenter_oanda

The offcenter_oanda project is a C++ library that provides access to the [OANDA v20 REST API](https://developer.oanda.com/rest-live-v20/introduction/).

## Installation
This project is hosted on github under user [CodeRancher](https://github.com/CodeRancher).

### Clone
To clone this repository use the git command:
```shell
git clone https://github.com/CodeRancher/offcenter_oanda.git
```
### Build
The most simple build, if dependencies are installed globally.
```shell
cd offcenter_oanda
mkdir build
cd build
cmake ..
make
```

A more complicated build if the libraries are in non-standard locations.
```shell
cd offcenter_oanda
mkdir build
cd build
cmake \
    -DCMAKE_INSTALL_PREFIX=<installation path> \
    -DBUILD_DOC=<ON|OFF> \
    -DCMAKE_PREFIX_PATH="<nlohmann json path>;<cpprestsdk path>" \
    -DBOOST_ROOT=<boost root> \
    -DEASYLOGGINGPP_ROOT=<easyloggingpp root> \
    -DEASYLOGGINGPP_USE_STATIC_LIBS=<ON|OFF> \
    -DGTEST_ROOT=<googletest root> \
    ..
make install
```

Important make commands.

| Command | Action |
| ------- | ------ |
| make | Build library. Build documentation if ${BUILD_DOC}=ON |
| make install | Build library and install to ${CMAKE_INSTALL_PREFIX}. Build documentation if ${BUILD_DOC}=ON |
| make doc_doxyten | Build library. Build documentation if ${BUILD_DOC}=ON |


Important cmake build variables.

| Variable | Description | Examples |
| -------- | ----------- | --------------- |
| [CMAKE_INSTALL_PREFIX](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html) | Install directory for `make install`. | e.g. ${HOME}/libs |
| [CMAKE_PREFIX_PATH](https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html) | Directories to search during `make`. | ${HOME}/libs/cmake/nlohmann_json;${HOME}/libs/cmake/cpprestsdk |
| BUILD_DOC | Build Doxygen documentation during `make doc_doxygen`. Can be 'ON' or 'OFF'. | ON |
| LOG_V20_ACCESS | Build with logging to EasyLogging++. Can be 'ON' or 'OFF'. | ON |
| [BOOST_ROOT](https://cmake.org/cmake/help/latest/module/FindBoost.html) | Boost library location. | e.g. ${HOME}/libs |
| [EASYLOGGINGPP_ROOT](https://github.com/amrayn/easyloggingpp/blob/master/cmake/FindEASYLOGGINGPP.cmake) | Easylogging++ library location. | e.g. ${HOME}/libs |
| [EASYLOGGINGPP_USE_STATIC_LIBS](https://github.com/amrayn/easyloggingpp/blob/master/cmake/FindEASYLOGGINGPP.cmake) | If ${EASYLOGGINGPP_USE_STATIC_LIBS} is ON then static libs are searched. | ON |
| [GTEST_ROOT](https://cmake.org/cmake/help/latest/module/FindGTest.html) | The root directory of the Google Test installation. | e.g. ${HOME}/libs |

## Dependencies

| Library | Minimum Version | License |
| ------- | --------------- | ------- |
| [nlohmann json](https://github.com/nlohmann/json) | 3.9.1 | [MIT](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT) |
| [C++ REST SDK](https://github.com/microsoft/cpprestsdk) ] | 2.10.16 | [MIT](https://github.com/microsoft/cpprestsdk/blob/master/license.txt) |
| [Boost](https://www.boost.org/) | 1.74 | [Boost Software License 1.0](https://www.boost.org/users/license.html) |
| [Easylogging++](https://github.com/amrayn/easyloggingpp) | 9.97.0 | [MIT](https://github.com/amrayn/easyloggingpp/blob/master/LICENSE) |
| [GoogleTest](https://github.com/google/googletest) | 1.10.0 | [BSD 3-Clause "New" or "Revised" License (modified)](https://github.com/google/googletest/blob/master/LICENSE) |
| [OpenSSL](https://www.openssl.org) | 1.1.1 | [](https://www.openssl.org/source/license-openssl-ssleay.txt) |

| Tools |
| ----- |
| [Doxygen](https://www.doxygen.nl) |

## Usage
The offcenter_oanda C++ library has been designed to mimic the [OANDA v20 REST API](https://developer.oanda.com/rest-live-v20/introduction/) as much as possible. 

Accessing the [OANDA v20 REST API](https://developer.oanda.com/rest-live-v20/introduction/) will follow a simple pattern of:
1. Connect to Oanda endpoint
2. Initialize the Request data needed by the endpoint
3. Initialize the Parameter data needed by the endpoint
4. Call the endpoint (Synchronous or Asynchronous) with the Request and Parameter data and callback lambda
5. The callback lambda will have the Response data returned from the [OANDA v20 REST API](https://developer.oanda.com/rest-live-v20/introduction/).

### Example Application
Here is a simple application that will retrieve the last 1000 Daily Mid candlesticks for the EUR/USD and print them out in a csv format.

<strong>Command Line</strong>

The Oanda Access Token and User Acount number are needed for this example.
```shell
Expected command line:

	eur_usd_to_csv <access_token> <account>

access_token: Oanda supplied access token
account:      User Account
```

<strong>Header Files</strong>

The `iostream` and `OandaEndpints.hpp` header files are required for this example. Typically the `OandaEndpints.hpp` header is all you will need to access this library.
```{.cpp}
#include <iostream>
#include "oanda/v20/endpoint/OandaEndpoints.hpp"
using namespace oanda::v20;
```
<strong>Validate Command Line</strong>

This is a simple way to validate the expected command line.
```{.cpp}
    if(argc != 3) {
        std::cerr << "Incorrect Number Of Arguments: " << argc << std::endl;
        std::cerr << "Expected command line:" << std::endl << std::endl;
        std::cerr << "	eur_usd_to_csv <access_token> <account>" << std::endl << std::endl;
        std::cerr << "access_token: Oanda supplied access token" << std::endl;
        std::cerr << "account:      User Account" << std::endl;
        return 1;
    }
```
<strong>Connect to the Oanda Server</strong>

Connecting to the Oanda server requires the type of server to connect to (practice or trade) and the Oanda Access Token.

```{.cpp}
    endpoint::OandaPracticeServer server;
    endpoint::OandaAuthorization authorization(argv[1]);
    endpoint::OandaEndpoints oandaEndpoints(server, authorization);
```
<strong>Request and Parameters</strong>

Each call to the [OANDA v20 REST API](https://developer.oanda.com/rest-live-v20/introduction/) may have a set of parameters (header, path, or query) or a request body (in json). These are set by using the Request and Parameters classes required by each endpoint call.

```{.cpp}
    endpoint::pricing::candles::Request request;
    endpoint::pricing::candles::Parameters parameters;
    parameters.accountID = argv[2];
    parameters.instrument = "EUR_USD";
    parameters.granularity = "D";
    parameters.price = "M";
    parameters.smooth = "True";
    parameters.count = "1000";
```
<strong>Call Endpoint</strong>

Call the endpoint with the request and parameters values. The endpoint can be called synchronously (sync) or asynchronously (async). The callback lambda will receive the data returned from the call.

The `to_string(candles.granularity, granularity)` helper will convert the granularity enum into a string.

```{.cpp}
    oandaEndpoints.pricing.candles(request, parameters)->sync([](endpoint::pricing::candles::Response candles) -> void {
        std::string granularity;
        to_string(candles.granularity, granularity);

        // Output headers
        std::cout <<
            candles.instrument << " - " << granularity << "," <<
            "Open," << "Low," << "High," << "Close" << std::endl;

        // Output candlestick values
        for (oanda::v20::instrument::Candlestick& candlestick : candles.candles) {
			std::cout <<
            candlestick.time << "," << candlestick.mid.o << "," << candlestick.mid.l << "," <<
            candlestick.mid.h << "," << candlestick.mid.c << std::endl;
        }
    });
```
<strong>Complete Example</strong>

Here is the complete example (with logging).

```{.cpp}
#include <iostream>

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#include "oanda/v20/endpoint/OandaEndpoints.hpp"
using namespace oanda::v20;

/**
 * Query Oanda for a 1000 daily mid candles for EUR/USD that are smoothed.
 */
int main(int argc, char* argv[])
{
    START_EASYLOGGINGPP(argc, argv);

    // Move logging to a file so stdout is not flooded
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "true");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime:%thread [%level] %msg");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "eur_usd_to_csv.log");

    // Verify correct number of command line arguments
    if(argc != 3) {
        std::cerr << "Incorrect Number Of Arguments: " << argc << std::endl;
        std::cerr << "Expected command line:" << std::endl << std::endl;
        std::cerr << "    eur_usd_to_csv <access_token> <account>" << std::endl << std::endl;
        std::cerr << "access_token: Oanda supplied access token" << std::endl;
        std::cerr << "account:      User Account" << std::endl;
        return 1;
    }

    // Connect to the Oanda server
    endpoint::OandaPracticeServer server;
    endpoint::OandaAuthorization authorization(argv[1]);
    std::string accountID = argv[2];
    endpoint::OandaEndpoints oandaEndpoints(server, authorization);

    // Initialize Request and Parameter values
    endpoint::pricing::candles::Request request;
    endpoint::pricing::candles::Parameters parameters;
    parameters.accountID = accountID;
    parameters.instrument = "EUR_USD";
    parameters.granularity = "D";
    parameters.price = "M";
    parameters.smooth = "True";
    parameters.count = "1000";

    // Synchronously retrieve the candle values
    oandaEndpoints.pricing.candles(request, parameters)->sync([](endpoint::pricing::candles::Response candles) -> void {
        std::string granularity;
        to_string(candles.granularity, granularity);

        // Output headers
        std::cout <<
                candles.instrument << " - " << granularity << "," <<
                "Open," <<
                "Low," <<
                "High," <<
                "Close" << std::endl;

        // Output candlestick values
        for (oanda::v20::instrument::Candlestick& candlestick : candles.candles) {
            std::cout <<
                    candlestick.time << "," <<
                    candlestick.mid.o << "," <<
                    candlestick.mid.l << "," <<
                    candlestick.mid.h << "," <<
                    candlestick.mid.c << std::endl;
        }
    });

    return 0;
}
```

## Roadmap
<strong>Testing</strong>

The library needs testing from end-to-end. There are basic tests and examples for some of the most used calls but the rest of the system needs validation.

One problem with testing much of the system is that the repeated calls to Oanda can trigger a violation of their policies and get the account cancelled. Testing needs to be performed carefully.

<strong>Documentation</strong>
1. Create the missing documenation.
2. Add examples.

## License
[MIT](https://github.com/CodeRancher/offcenter_oanda/blob/main/LICENSE)