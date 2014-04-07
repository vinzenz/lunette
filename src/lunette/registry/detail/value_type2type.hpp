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
#ifndef GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_TYPE2TYPE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_TYPE2TYPE_HPP_INCLUDED

#include <cstdint>
#include <vector>

#include <lunette/string.hpp>
#include <lunette/registry/value_type.hpp>

namespace lunette {
    namespace registry {
        namespace detail {
            template< value_type >
            struct value_type2type;

#define LUNETTE_REGISTRY_VALUETYPE(ENUM_TYPE, TYPE) \
            template<> \
            struct value_type2type<ENUM_TYPE> { \
                typedef TYPE type; \
            }

            LUNETTE_REGISTRY_VALUETYPE(binary, std::vector<std::uint8_t>);
            LUNETTE_REGISTRY_VALUETYPE(string, lunette::string);
            LUNETTE_REGISTRY_VALUETYPE(multi_string, lunette::string);
            LUNETTE_REGISTRY_VALUETYPE(expand_string, lunette::string);
            LUNETTE_REGISTRY_VALUETYPE(dword_le, std::uint32_t);
            LUNETTE_REGISTRY_VALUETYPE(dword_be, std::uint32_t);
            LUNETTE_REGISTRY_VALUETYPE(qword_le, std::uint64_t);
            LUNETTE_REGISTRY_VALUETYPE(link, std::vector<uint8_t>);
            LUNETTE_REGISTRY_VALUETYPE(resource_list, std::vector<uint8_t>);
            LUNETTE_REGISTRY_VALUETYPE(full_resource_descriptor, std::vector<uint8_t>);
            LUNETTE_REGISTRY_VALUETYPE(resource_requirements_list, std::vector<uint8_t>);

#undef LUNETTE_REGISTRY_VALUETYPE
        }
    }
}
#endif //GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_TYPE2TYPE_HPP_INCLUDED
