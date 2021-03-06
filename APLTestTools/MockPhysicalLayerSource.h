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

#ifndef __MOCK_PHYSICAL_LAYER_SOURCE_H_
#define __MOCK_PHYSICAL_LAYER_SOURCE_H_

#include <APL/IPhysicalLayerSource.h>
#include <APL/PhysicalLayerInstance.h>

#include <map>

namespace apl
{
class MockPhysicalLayerAsync;
class ITimerSource;

class MockPhysicalLayerSource : public IPhysicalLayerSource
{
public:

	MockPhysicalLayerSource(Logger* apLogger, ITimerSource* apTimerSrc = NULL);

	~MockPhysicalLayerSource();

	MockPhysicalLayerAsync* GetMock(const std::string& arName);

	IPhysicalLayerAsync* AcquireLayer(const std::string& arName);
	void ReleaseLayer(const std::string& arName);

private:

	Logger* mpLogger;
	ITimerSource* mpTimerSrc;

	typedef std::map<std::string, PhysLayerInstance> InstanceMap;
	typedef std::map<std::string, MockPhysicalLayerAsync*> MockMap;

	InstanceMap mInstanceMap;
	MockMap mMockMap;

};
}

#endif
