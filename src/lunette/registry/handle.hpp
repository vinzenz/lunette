#ifndef GUARD_LUNETTE_REGISTRY_HANDLE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_HANDLE_HPP_INCLUDED

#include <string>

#include <lunette/registry/root.hpp>
#include <lunette/registry/view_mode.hpp>

namespace lunette {
    namespace registry {
        class handle {
        public:
            typedef void * handle_t;

            handle();
            handle(registry::root root);
            handle(registry::root root, char const * path);
            handle(registry::root root, std::string const &);
            handle(handle_t handle);
            handle(handle const & h);
            handle(handle && h);
            virtual ~handle();

            handle & operator=(handle);
            handle & operator=(handle &&);

            void close();

            bool open(registry::root root);
            bool open(char const * path);
            bool open(std::string const &);


            bool is_open() const;

            handle_t const & native() const;

            void swap(handle & other);
        protected:
            handle_t handle_;
        };
    }
}

#endif //GUARD_LUNETTE_REGISTRY_HANDLE_HPP_INCLUDED

