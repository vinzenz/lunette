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
#ifndef GUARD_LUNETTE_REGISTRY_REGISTRY_VALUE_ERROR_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_REGISTRY_VALUE_ERROR_HPP_INCLUDED

#include <stdexcept>

namespace lunette {
    namespace registry {
        class registry_value_error : public std::runtime_error {
        public:
            registry_value_error(char const * what_arg)
            : std::runtime_error(what_arg)
            {}
        };
    }
}

#endif // GUARD_LUNETTE_REGISTRY_REGISTRY_VALUE_ERROR_HPP_INCLUDED

