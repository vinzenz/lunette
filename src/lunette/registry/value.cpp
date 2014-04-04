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
#include <lunette/registry/value.hpp>

namespace lunette {
    namespace registry {
        namespace {
            template< typename T >
            void typed_clone_to(detail::value_storage_type & destination,
                                detail::value_storage_type const & source) {
                T const & tsrc = reinterpret_cast<T const &>(source);
                new (&destination) T(tsrc);
            }

            void clone_to(detail::value_storage_type & destination,
                          value_type type,
                          detail::value_storage_type const & source) {
                switch(type) {
                    case value_type::binary:
                        typed_clone_to<std::vector<std::uint8_t>>(destination, source);
                        break;
                    case value_type::string:
                    case value_type::multi_string:
                    case value_type::expand_string:
                        typed_clone_to<std::string>(destination, source);
                        break;
                    default:
                    case value_type::qword_le:
                    case value_type::dword_le:
                    case value_type::dword_be:
                        memcpy(&destination, &source, sizeof(detail::value_storage_type));
                        break;
                        break;
               }
            }

            void swap_storage(detail::value_storage_type & a, detail::value_storage_type & b) {
                detail::value_storage_type c{};
                memcpy(&c, &a, sizeof(detail::value_storage_type));
                memcpy(&a, &b, sizeof(detail::value_storage_type));
                memcpy(&b, &c, sizeof(detail::value_storage_type));
            }
        }
        value::value()
        : value_(value_type::none)
        , storage_()
        {
        }

        value::value(value const & other)
        : value_(other.value_)
        , storage_()
        {
            clone_to(storage_, value_, other.storage_);
        }

        value::value(value && other)
        : value_(std::move(other.value_))
        , storage_() {
            swap_storage(other.storage_, other.storage_);
        }

        value & value::operator=(value && other) {
            swap(other);
            return *this;
        }

        value & value::operator=(value other) {
            swap(other);
            return *this;
        }

        value_type value::type() const {
            return value_;
        }

        void value::swap(value & other) {
            value_type v = value_;
            value_ = other.value_;
            other.value_ = v;
            swap_storage(storage_, other.storage_);
        }

        void value::swap(value && other) {
            value v(other);
            swap(v);
        }
    }
}

