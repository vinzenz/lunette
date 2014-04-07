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
#ifndef GUARD_LUNETTE_REGISTRY_HANDLE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_HANDLE_HPP_INCLUDED

#include <lunette/string.hpp>
#include <lunette/registry/root.hpp>
#include <lunette/registry/view_mode.hpp>

namespace lunette {
    namespace registry {
        class handle {
        public:
            typedef void * handle_t;

            handle();
            handle(registry::root root);
            handle(registry::root root, char_type const * path);
            handle(registry::root root, lunette::string const &);
            handle(handle_t handle);
            handle(handle const & h);
            handle(handle && h);
            virtual ~handle();

            handle & operator=(handle);
            handle & operator=(handle &&);

            void close();

            bool open(registry::root root);
            bool open(char_type const * path);
            bool open(lunette::string const &);


            bool is_open() const;

            handle_t const & native() const;

            void swap(handle & other);
        protected:
            handle_t handle_;
        };
    }
}

#endif //GUARD_LUNETTE_REGISTRY_HANDLE_HPP_INCLUDED

