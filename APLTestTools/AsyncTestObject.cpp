//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//

#include "AsyncTestObject.h"

#include <APL/TimingTools.h>

#include <boost/bind.hpp>

using namespace std;

namespace apl
{

bool AsyncTestObject::ProceedUntil(const EvalFunc& arFunc, millis_t aTimeout)
{
	Timeout t(aTimeout);

	do {
		if(arFunc()) return true;
		else this->Next();
	}
	while(!t.IsExpired());

	return false;
}

void AsyncTestObject::ProceedForTime(millis_t aTimeout)
{
	ProceedUntil(boost::bind(&AsyncTestObject::AlwaysBoolean, false), aTimeout);
}

bool AsyncTestObject::ProceedUntilFalse(const EvalFunc& arFunc, millis_t aTimeout)
{
	return ProceedUntil(boost::bind(&AsyncTestObject::Negate, arFunc), aTimeout);
}

}
