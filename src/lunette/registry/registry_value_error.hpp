#ifndef GUARD_LUNETTE_REGISTRY_REGISTRY_VALUE_ERROR_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_REGISTRY_VALUE_ERROR_HPP_INCLUDED

#include <stdexcept>

namespace lunette {
    namespace registry {
        class registry_value_error : public std::runtime_error {
            registry_value_error(char const * what_arg)
            : std::runtime_error(what_arg)
            {}
        };
    }
}

#endif // GUARD_LUNETTE_REGISTRY_REGISTRY_VALUE_ERROR_HPP_INCLUDED

