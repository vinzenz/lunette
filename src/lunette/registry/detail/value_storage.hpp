#ifndef GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_STORAGE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_STORAGE_HPP_INCLUDED

#include <cstdint>
#include <string>
#include <vector>

#include <lunette/registry/detail/max_size_align.hpp>

namespace lunette {
    namespace registry {
        namespace detail {

            typedef max_size_align<
                std::string,
                max_size_align<
                   std::vector<std::uint8_t>,
                   max_size_align<
                       std::uint32_t,
                       max_size_align<
                           std::uint64_t, void
                       >
                   >
                >
            > value_max_size_align;

            typedef std::aligned_storage<
                value_max_size_align::size_value
            >::type value_storage_type;

        }
    }
}

#endif //GUARD_LUNETTE_REGISTRY_DETAIL_VALUE_STORAGE_HPP_INCLUDED

