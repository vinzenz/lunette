#include <vector>

#include <lunette/registry/get_string.hpp>
#include "internal.inl"

namespace lunette {
    namespace registry {
        std::string get_string(handle const & handle) {
            return std::move(get_string(handle, std::string()));
        }

        std::string get_string(handle const & handle, std::string const & name) {
            return std::move(get_string(handle, name.empty() ? 0 : name.c_str()));
        }

        std::string get_string(handle const & handle, char const * name) {
            std::string result;
            DWORD valueType = 0, valueSize = 0;
            LSTATUS status = RegQueryValueExA(key(handle), name, 0, &valueType, 0, &valueSize);
            if( status == ERROR_SUCCESS ) {
                valueSize += 1;
                std::vector<char> buffer(valueSize, 0);
                status = RegQueryValueExA(key(handle), name, 0, &valueType, reinterpret_cast<LPBYTE>(buffer.data()), &valueSize);
                if( status == ERROR_SUCCESS ) {
                    if(valueType == REG_SZ || valueType == REG_EXPAND_SZ || valueType == REG_MULTI_SZ ) {
                        result.assign(buffer.data());
                    }
                }
            }
            return result;
        }
    }
}
