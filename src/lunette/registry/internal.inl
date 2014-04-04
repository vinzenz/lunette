#include <windows.h>
#include <lunette/registry/handle.hpp>

namespace lunette {
    namespace registry {
        namespace {
            inline HKEY key(handle const & h) {
                return HKEY(h.native());
            }

            inline PHKEY ref(handle const & h) {
                return PHKEY(&h.native());
            }
        }
    }
}
