#ifndef GUARD_LUNETTE_REGISTRY_VALUE_HPP_INCLUDED
#define GUARD_LUNETTE_REGISTRY_VALUE_HPP_INCLUDED

#include <lunette/registry/detail/value_storage.hpp>
#include <lunette/registry/detail/value_type2type.hpp>
#include <lunette/registry/registry_value_error.hpp>
#include <lunette/registry/value_type.hpp>

namespace lunette {
    namespace registry {

        class value {
            value_type value_;
            detail::value_storage_type storage_;
        public:
            value();
            ~value();
            value(value const & other);
            value(value && other);
            value & operator=(value &&);
            value & operator=(value);

            value_type type() const;
            void swap(value & value);
            void swap(value && value);

            template< value_type type >
            typename detail::value_type2type<type>::type & get() {
                typedef typename detail::value_type2type<type>::type target_t;
                if(value_ != type) {
                    throw registry_value_error("Invalid conversion");
                }
                return *reinterpret_cast<target_t *>(&storage_);
            }

            template< value_type type >
            typename detail::value_type2type<type>::type get() const {
                typedef typename detail::value_type2type<type>::type target_t;
                if(value_ != type) {
                    throw registry_value_error("Invalid conversion");
                }
                return *reinterpret_cast<target_t const *>(&storage_);
            }

            template< value_type type >
            void set(typename detail::value_type2type<type>::type const & value) {
                typedef typename detail::value_type2type<type>::type target_t;
                *reinterpret_cast<target_t *>(&storage_) = value;
                value_ = type;
            }
        };

    }
}

#endif //GUARD_LUNETTE_REGISTRY_VALUE_HPP_INCLUDED
