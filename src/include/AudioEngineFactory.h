// Copyright (c) 2009-2018 LG Electronics, Inc.
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

#ifndef SRC_CORE_AUDIOENGINEFACTORY_H_
#define SRC_CORE_AUDIOENGINEFACTORY_H_

#include <map>
#include <memory>
#include <AudioEngine.h>

class AudioEngineFactory
{
    public:
        virtual ~AudioEngineFactory() {}

        virtual void create(std::shared_ptr<AudioEngine> &engine) const = 0;
        virtual const char* getName() const = 0;

        static void createAudioEngine(const std::string& name, std::shared_ptr<AudioEngine>& engine);
        typedef std::shared_ptr<AudioEngineFactory> Factory;
        typedef std::map<std::string, Factory> Factories;

        template <typename T>
        struct Registrator
        {
            Registrator()
            {
                Factory factory { new T() };
                std::string key(factory->getName());
                mFactories.insert(std::pair<std::string, Factory>(key, factory));
            }
        };

    private:
        static Factories mFactories;
};

#endif
