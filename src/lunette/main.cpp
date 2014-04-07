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

#include <lunette/registry/enum_keys.hpp>
#include <lunette/registry/enum_values.hpp>

int main() {

    lunette::registry::handle h(lunette::registry::root::local_machine, LUNETTE_TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"));
    enum_keys(h, [&h](lunette::string const & s) {
        printf("Key: %s\n", s.c_str());
        lunette::registry::handle h2(h);
        if(h2.open(s)) {
            enum_values(h2, [](lunette::string const & name, lunette::registry::value const & v) {
                printf("\tValue(string) %s -> Type: %d\n", name.c_str(), uint32_t(v.type()));
                return lunette::registry::enum_result::cont;
            });
        }
        return lunette::registry::enum_result::cont;
    });
}


