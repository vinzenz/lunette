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

