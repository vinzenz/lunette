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
#ifndef GUARD_LUNETTE_REGISTRY_ENUM_VALUES_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_ENUM_VALUES_HPP_INCLUDED

#include <map>
#include <functional>

#include <lunette/string.hpp>
#include <lunette/registry/enum_result.hpp>
#include <lunette/registry/handle.hpp>
#include <lunette/registry/root.hpp>
#include <lunette/registry/value.hpp>

namespace lunette {
    namespace registry {
        typedef std::function<
            enum_result(lunette::string const & name, value const & value)
        > enum_values_callback;

        // Callback based versions
        bool enum_values(handle const &,
                         enum_values_callback callback);
        bool enum_values(registry::root root,
                         lunette::string const & path,
                         enum_values_callback callback);

        // Non-callback based versions
        std::map<lunette::string, value> enum_values(handle const &);
        std::map<lunette::string, value> enum_values(registry::root root,
                                                     lunette::string const & path);
    }
}

#endif //GUARD_LUNETTE_REGISTRY_ENUM_VALUES_HPP_INCLUDED

