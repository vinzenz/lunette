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
#ifndef GUARD_LUNETTE_REGISTRY_VALUE_TYPE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_VALUE_TYPE_HPP_INCLUDED

namespace lunette {
    namespace registry {
        enum value_type : uint32_t {
            none,
            string,
            expand_string,
            binary,
            dword_le,
            dword_be,
            link,
            multi_string,
            resource_list,
            full_resource_descriptor,
            resource_requirements_list,
            qword_le,
        };
    }
}

#endif //GUARD_LUNETTE_REGISTRY_VALUE_TYPE_HPP_INCLUDED
