#ifndef GUARD_LUNETTE_REGISTRY_ROOT_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_ROOT_HPP_INCLUDED

namespace lunette {
    namespace registry {
        enum class root {
            invalid,
            local_machine,
            current_user,
            current_config,
            classes_root,
            user_local_settings,
            dyn_data,
            users,
            performance_data,
            performance_nlstext,
            performance_text,
        };
    }
}

#endif //GUARD_LUNETTE_REGISTRY_ROOT_HPP_INCLUDED

