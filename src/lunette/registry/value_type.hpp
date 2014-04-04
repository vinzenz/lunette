#ifndef GUARD_LUNETTE_REGISTRY_VALUE_TYPE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_VALUE_TYPE_HPP_INCLUDED

namespace lunette {
    namespace registry {
        enum value_type : uint32_t {
            none,
            string,
            expand_string,
            binary,
            dword_le,
            dword_be,
            link,
            multi_string,
            resource_list,
            full_resource_descriptor,
            resource_requirements_list,
            qword_le,
        };
    }
}

#endif //GUARD_LUNETTE_REGISTRY_VALUE_TYPE_HPP_INCLUDED
