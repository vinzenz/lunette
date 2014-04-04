#include <cassert>
#include "internal.inl"
#include <lunette/registry/enum_keys.hpp>

namespace lunette {
    namespace registry {
        bool enum_keys(handle const & h, enum_key_callback callback) {
            assert(callback);
            DWORD numKeys = 0, maxSubKeyLength = 0;
            bool result = false;
            if( RegQueryInfoKeyA(key(h), 0, 0, 0, &numKeys, &maxSubKeyLength, 0, 0, 0, 0, 0, 0) == ERROR_SUCCESS ) {
                result = true;
                std::vector<char> keyBuffer;
                ++maxSubKeyLength; // Increase for terminating character (required by API)
                for( DWORD i = 0; i < numKeys; ++i ) {
                    keyBuffer.clear();
                    keyBuffer.resize(maxSubKeyLength, 0);
                    if( RegEnumKeyA(key(h), i, keyBuffer.data(), maxSubKeyLength) == ERROR_SUCCESS ) {
                        if( callback(keyBuffer.empty() ? "" : &keyBuffer[0]) == enum_result::exit ) {
                            break;
                        }
                    }
                }
            }
            return result;
        }

        bool enum_keys(registry::root root, std::string const & path,  enum_key_callback callback) {
            return enum_keys(handle(root, path), callback);
        }

        std::vector<std::string> enum_keys(handle const & h) {
            std::vector<std::string> result;
            enum_keys(h, [&result](std::string const & key) {
                result.emplace_back(key);
                return enum_result::cont;
            });
            return result;
        }

        std::vector<std::string> enum_keys(registry::root root, std::string const & path) {
            return std::move(enum_keys(registry::handle(root, path)));
        }
    }
}
