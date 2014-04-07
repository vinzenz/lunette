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
#ifndef GUARD_LUNETTE_REGISTRY_ENUM_KEYS_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_ENUM_KEYS_HPP_INCLUDED

#include <functional>
#include <vector>

#include <lunette/string.hpp>
#include <lunette/registry/enum_result.hpp>
#include <lunette/registry/handle.hpp>
#include <lunette/registry/root.hpp>

namespace lunette {
    namespace registry {

        typedef std::function<
            enum_result(lunette::string const &)
        > enum_key_callback;

        // Callback based versions
        bool enum_keys(handle const &, enum_key_callback callback);

        bool enum_keys(registry::root root,
                       lunette::string const & path,
                       enum_key_callback callback);

        // Non callback based versions
        std::vector<lunette::string> enum_keys(handle const &);

        std::vector<lunette::string> enum_keys(registry::root root,
                                               lunette::string const & path);

    }
}

#endif //GUARD_LUNETTE_REGISTRY_ENUM_KEYS_HPP_INCLUDED

