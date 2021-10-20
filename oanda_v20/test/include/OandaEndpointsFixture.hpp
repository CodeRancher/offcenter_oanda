/**
 * Copyright 2020 Scott Brauer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an  BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file   OandaEndpointsFixture.hpp
 * @author Scott Brauer
 * @date   12-09-2020
 */

#ifndef OANDAENDPOINTSFIXTURE_HPP_
#define OANDAENDPOINTSFIXTURE_HPP_

#include <gtest/gtest.h>

#include "oanda/v20/endpoint/OandaEndpoints.hpp"
#include "GlobalVariables.hpp"


class OandaEndpointsFixture : public ::testing::Test {
public:
	OandaEndpointsFixture();
	virtual ~OandaEndpointsFixture();

	oanda::v20::endpoint::OandaEndpoints& oandaEndpoints() {
		oanda::v20::endpoint::OandaPracticeServer server;
		oanda::v20::endpoint::OandaAuthorization authorization(g_oandaPersonalAccessToken);
		return *oanda::v20::endpoint::OandaEndpoints::instance(server, authorization);
	}

protected:
	void SetUp() override;
	void TearDown() override;
	static void SetUpTestCase();
	static void TearDownTestCase();

private:
};

#endif /* OANDAENDPOINTSFIXTURE_HPP_ */
