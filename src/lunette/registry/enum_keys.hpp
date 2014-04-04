#ifndef GUARD_LUNETTE_REGISTRY_ENUM_KEYS_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_ENUM_KEYS_HPP_INCLUDED

#include <functional>
#include <string>
#include <vector>

#include <lunette/registry/enum_result.hpp>
#include <lunette/registry/handle.hpp>
#include <lunette/registry/root.hpp>

namespace lunette {
    namespace registry {

        typedef std::function<
            enum_result(std::string const &)
        > enum_key_callback;

        // Callback based versions
        bool enum_keys(handle const &, enum_key_callback callback);

        bool enum_keys(registry::root root,
                       std::string const & path,
                       enum_key_callback callback);

        // Non callback based versions
        std::vector<std::string> enum_keys(handle const &);

        std::vector<std::string> enum_keys(registry::root root,
                                           std::string const & path);

    }
}

#endif //GUARD_LUNETTE_REGISTRY_ENUM_KEYS_HPP_INCLUDED

