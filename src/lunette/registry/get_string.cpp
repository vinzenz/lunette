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
#include <vector>

#include <lunette/registry/get_string.hpp>
#include "internal.inl"

namespace lunette {
    namespace registry {
        lunette::string get_string(registry::root root, lunette::string const & path, lunette::string const & name) {
            return get_string(root, path, name.empty() ? 0 : name.c_str());
        }
        
        lunette::string get_string(registry::root root, lunette::string const & path, char_type const * name) {
            return get_string(handle(root, path), name);
        }

        lunette::string get_string(registry::root root, lunette::string const & path) {
            return get_string(root, path, 0);
        }

        lunette::string get_string(handle const & handle) {
            return std::move(get_string(handle, lunette::string()));
        }

        lunette::string get_string(handle const & handle, lunette::string const & name) {
            return std::move(get_string(handle, name.empty() ? 0 : name.c_str()));
        }

        lunette::string get_string(handle const & handle, char_type const * name) {
            lunette::string result;
            DWORD valueType = 0, valueSize = 0;
            LSTATUS status = RegQueryValueEx(key(handle), name, 0, &valueType, 0, &valueSize);
            if( status == ERROR_SUCCESS ) {
                valueSize += 1;
                if (valueType == REG_MULTI_SZ) {
                    valueSize += 1;
                }
                std::vector<char_type> buffer(valueSize, 0);
                status = RegQueryValueEx(key(handle), name, 0, &valueType, reinterpret_cast<LPBYTE>(buffer.data()), &valueSize);
                if( status == ERROR_SUCCESS ) {
                    if(valueType == REG_SZ || valueType == REG_EXPAND_SZ || valueType == REG_MULTI_SZ ) {
                        result.assign(buffer.data());
                    }
                }
            }
            return result;
        }
    }
}
