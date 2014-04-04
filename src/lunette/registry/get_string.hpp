#ifndef GUARD_LUNETTE_REGISTRY_GET_STRING_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_GET_STRING_HPP_INCLUDED

#include <string>

#include <lunette/registry/handle.hpp>

namespace lunette {
    namespace registry {
        std::string get_string(handle const & handle);
        std::string get_string(handle const & handle, std::string const & name);
        std::string get_string(handle const & handle, char const * name);
    }
}

#endif //GUARD_LUNETTE_REGISTRY_GET_STRING_HPP_INCLUDED

