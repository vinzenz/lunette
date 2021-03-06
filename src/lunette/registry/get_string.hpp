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
#ifndef GUARD_LUNETTE_REGISTRY_GET_STRING_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_GET_STRING_HPP_INCLUDED

#include <lunette/string.hpp>
#include <lunette/registry/handle.hpp>

namespace lunette {
    namespace registry {
        lunette::string get_string(registry::root root, lunette::string const & path, lunette::string const & name);
        lunette::string get_string(registry::root root, lunette::string const & path, char_type const * name);
        lunette::string get_string(registry::root root, lunette::string const & path);

        lunette::string get_string(handle const & handle);
        lunette::string get_string(handle const & handle, lunette::string const & name);
        lunette::string get_string(handle const & handle, char_type const * name);
    }
}

#endif //GUARD_LUNETTE_REGISTRY_GET_STRING_HPP_INCLUDED

