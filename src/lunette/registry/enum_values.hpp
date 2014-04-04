#ifndef GUARD_LUNETTE_REGISTRY_ENUM_VALUES_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_ENUM_VALUES_HPP_INCLUDED

#include <string>
#include <functional>

#include <lunette/registry/enum_result.hpp>
#include <lunette/registry/handle.hpp>
#include <lunette/registry/root.hpp>
#include <lunette/registry/value.hpp>

namespace lunette {
    namespace registry {
        typedef std::function<
            enum_result(std::string const & name, value const & value)
        > enum_values_callback;

        // Callback based versions
        std::vector<std::string> enum_values(handle const &,
                                             enum_values_callback callback);
        std::vector<std::string> enum_values(registry::root root,
                                             std::string const & path,
                                             enum_values_callback callback);

        // Non-callback based versions
        std::vector<value> enum_values(handle const &);
        std::vector<value> enum_values(registry::root root,
                                       std::string const & path);
    }
}

#endif //GUARD_LUNETTE_REGISTRY_ENUM_VALUES_HPP_INCLUDED

