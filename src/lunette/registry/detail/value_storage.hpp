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

