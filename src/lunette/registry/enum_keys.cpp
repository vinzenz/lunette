//
//   Copyright 2014 Vinzenz Feenstra, Red Hat Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
#include <cassert>
#include "internal.inl"
#include <lunette/registry/enum_keys.hpp>

namespace lunette {
    namespace registry {
        bool enum_keys(handle const & h, enum_key_callback callback) {
            assert(callback);
            DWORD numKeys = 0, maxSubKeyLength = 0;
            bool result = false;
            if( RegQueryInfoKeyA(key(h), 0, 0, 0, &numKeys, &maxSubKeyLength, 0, 0, 0, 0, 0, 0) == ERROR_SUCCESS ) {
                result = true;
                std::vector<char_type> keyBuffer;
                ++maxSubKeyLength; // Increase for terminating character (required by API)
                for( DWORD i = 0; i < numKeys; ++i ) {
                    keyBuffer.clear();
                    keyBuffer.resize(maxSubKeyLength, 0);
                    if( RegEnumKey(key(h), i, keyBuffer.data(), maxSubKeyLength) == ERROR_SUCCESS ) {
                        if( callback(keyBuffer.empty() ? LUNETTE_TEXT("") : &keyBuffer[0]) == enum_result::exit ) {
                            break;
                        }
                    }
                }
            }
            return result;
        }

        bool enum_keys(registry::root root, lunette::string const & path,  enum_key_callback callback) {
            return enum_keys(handle(root, path), callback);
        }

        std::vector<lunette::string> enum_keys(handle const & h) {
            std::vector<lunette::string> result;
            enum_keys(h, [&result](lunette::string const & key) {
                result.emplace_back(key);
                return enum_result::cont;
            });
            return std::move(result);
        }

        std::vector<lunette::string> enum_keys(registry::root root, lunette::string const & path) {
            return std::move(enum_keys(registry::handle(root, path)));
        }
    }
}
