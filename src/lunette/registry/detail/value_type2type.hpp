#ifndef GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_TYPE2TYPE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_TYPE2TYPE_HPP_INCLUDED

#include <cstdint>
#include <string>
#include <vector>

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
            LUNETTE_REGISTRY_VALUETYPE(string, std::string);
            LUNETTE_REGISTRY_VALUETYPE(multi_string, std::string);
            LUNETTE_REGISTRY_VALUETYPE(expand_string, std::string);
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
