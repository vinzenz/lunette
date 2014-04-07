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
#include "internal.inl"

#ifndef HKEY_PERFORMANCE_DATA
#   define HKEY_PERFORMANCE_DATA               (( HKEY ) (ULONG_PTR)((LONG)0x80000004) )
#endif
#ifndef HKEY_PERFORMANCE_TEXT
#   define HKEY_PERFORMANCE_TEXT               (( HKEY ) (ULONG_PTR)((LONG)0x80000050) )
#endif
#ifndef HKEY_PERFORMANCE_NLSTEXT
#   define HKEY_PERFORMANCE_NLSTEXT            (( HKEY ) (ULONG_PTR)((LONG)0x80000060) )
#endif
#ifndef HKEY_CURRENT_CONFIG
#   define HKEY_CURRENT_CONFIG                 (( HKEY ) (ULONG_PTR)((LONG)0x80000005) )
#endif
#ifndef HKEY_DYN_DATA
#   define HKEY_DYN_DATA                       (( HKEY ) (ULONG_PTR)((LONG)0x80000006) )
#endif
#ifndef HKEY_CURRENT_USER_LOCAL_SETTINGS
#   define HKEY_CURRENT_USER_LOCAL_SETTINGS    (( HKEY ) (ULONG_PTR)((LONG)0x80000007) )
#endif

namespace lunette {
    namespace registry {
        namespace {
            inline handle::handle_t root2handle(root r) {
                switch(r) {
                case root::classes_root:
                    return HKEY_CLASSES_ROOT;
                case root::current_config:
                    return HKEY_CURRENT_CONFIG;
                case root::local_machine:
                    return HKEY_LOCAL_MACHINE;
                case root::current_user:
                    return HKEY_CURRENT_CONFIG;
                case root::user_local_settings:
                    return HKEY_CURRENT_USER_LOCAL_SETTINGS;
                case root::users:
                    return HKEY_USERS;
                case root::dyn_data:
                    return HKEY_DYN_DATA;
                case root::performance_data:
                    return HKEY_PERFORMANCE_DATA;
                case root::performance_nlstext:
                    return HKEY_PERFORMANCE_NLSTEXT;
                case root::performance_text:
                    return HKEY_PERFORMANCE_TEXT;
                default:
                    break;
                }
                return 0;
            }

#define MyPtrToLong(p) ((long) (LONG_PTR) p )

            inline registry::root handle2root(handle::handle_t h) {
                switch(MyPtrToLong(h)) {
                case MyPtrToLong(HKEY_CLASSES_ROOT):
                    return root::classes_root;
                case MyPtrToLong(HKEY_CURRENT_CONFIG):
                    return root::current_config;
                case MyPtrToLong(HKEY_LOCAL_MACHINE):
                    return root::local_machine;
                case MyPtrToLong(HKEY_CURRENT_USER):
                    return root::current_user;
                case MyPtrToLong(HKEY_CURRENT_USER_LOCAL_SETTINGS):
                    return root::user_local_settings;
                case MyPtrToLong(HKEY_USERS):
                    return root::users;
                case MyPtrToLong(HKEY_DYN_DATA):
                    return root::dyn_data;
                case MyPtrToLong(HKEY_PERFORMANCE_DATA):
                    return root::performance_data;
                case MyPtrToLong(HKEY_PERFORMANCE_NLSTEXT):
                    return root::performance_nlstext;
                case MyPtrToLong(HKEY_PERFORMANCE_TEXT):
                    return root::performance_text;
                default:
                    break;
                }
                return root::invalid;
            }
        }
        inline handle::handle_t duplicate(handle::handle_t h) {
            if( handle2root(h) != root::invalid ) {
                return h;
            }

            handle::handle_t new_handle = 0;
            if( DuplicateHandle( GetCurrentProcess(), h, GetCurrentProcess(), &new_handle, 0, 0, DUPLICATE_SAME_ACCESS ) ) {
                return new_handle;
            }
            return 0;
        }

        handle::handle()
        : handle_()
        {}

        handle::handle(registry::root root)
        : handle_(root2handle(root))
        {}

        handle::handle(registry::root root, char_type const * path)
        : handle_(root2handle(root))
        {
            if( !open(path) ) {
                close();
            }
        }

        handle::handle(registry::root root, lunette::string const & path)
            : handle_(root2handle(root))
        {
            if( !open(path) ) {
                close();
            }
        }

        handle::handle(handle_t handle)
        : handle_(duplicate(handle))
        {}

        handle::handle(handle const & h)
        : handle_(duplicate(h.handle_))
        {}

        handle::handle(handle && h)
        : handle_(h.handle_)
        {}

        handle::~handle()
        {}

        handle & handle::operator=(handle h)
        {
            swap(h);
            return *this;
        }

        handle & handle::operator=(handle && h)
        {
            swap(h);
            return *this;
        }

        void handle::close() {
            if(handle2root(handle_) == root::invalid) {
                RegCloseKey(HKEY(handle_));
            }
            handle_ = 0;
        }

        bool handle::open(char_type const * path) {
            handle tmp(handle_);
            LSTATUS status = RegOpenKey(key(tmp), path, ref(tmp));
            if( status == ERROR_SUCCESS ) {
                swap(tmp);
                return true;
            }
            return false;
        }

        bool handle::open(lunette::string const & path) {
            return open(path.c_str());
        }

        bool handle::is_open() const {
            return handle_ != 0;
        }

        void handle::swap(handle & other) {
            handle_t handle = handle_;
            handle_ = other.handle_;
            other.handle_ = handle;
        }

        handle_t const & handle::native() const {
            return handle_;
        }
    }
}
