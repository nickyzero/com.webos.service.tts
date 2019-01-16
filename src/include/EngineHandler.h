// Copyright (c) 2018-2019 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef SRC_CORE_ENGINEHANDLER_H_
#define SRC_CORE_ENGINEHANDLER_H_

#include <luna-service2/lunaservice.hpp>
#include <AudioEngine.h>
#include <TTSConfig.h>
#include <TTSEngine.h>
#include <TTSParameters.h>

class TTSRequest;
class EngineHandler
{
public:
    EngineHandler();
    virtual ~EngineHandler();

    bool handleRequest(TTSRequest* request);
    void loadEngine();
    void unloadEngine();

    bool setConfig(bool status_flag);

    TTSRequest* getRunningSpeakRequest();
    void getStatusInfo(TTSRequest* pTTSRequest);
    void getLanguages(TTSRequest* pTTSRequest);
private:
    std::shared_ptr<TTSEngine> mTTSEngine;
    std::shared_ptr<AudioEngine> mAudioEngine;
    TTSConfig* mConfigHandler;
    pbnjson::JValue mTTSEngineName;
    pbnjson::JValue mAudioEngineName;
    TTSRequest* mRunningTTSRequest;
    Task_Status_t meTTSTaskStatus;
    std::string mCurrentLanguage;
};

#endif /* SRC_CORE_ENGINEHANDLER_H_ */
