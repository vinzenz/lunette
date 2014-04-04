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
#ifndef GUARD_LUNETTE_REGISTRY_DETAIL_MAX_SIZE_ALIGN_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_DETAIL_MAX_SIZE_ALIGN_HPP_INCLUDED

#include <cstddef>
#include <type_traits>

namespace lunette {
    namespace registry {
        namespace detail {
            template< typename T, typename U >
            struct max_size_align;

            template< typename T>
            struct max_size_align<T, void> {
                typedef T biggest_type;
                static std::size_t const size_value = sizeof(T);
            };

            template< typename T, typename U >
            struct max_size_align {
                typedef typename std::conditional<
                    sizeof(T) < U::size_value,
                    T,
                    typename U::biggest_type
                >::type biggest_type;
                static std::size_t const size_value =
                    (sizeof(T) < U::size_value) ? U::size_value : sizeof(T);
            };
        }
    }
}

#endif //GUARD_LUNETTE_REGISTRY_DETAIL_MAX_SIZE_ALIGN_HPP_INCLUDED

