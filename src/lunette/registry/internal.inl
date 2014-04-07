#include <windows.h>
#include <lunette/registry/handle.hpp>
#include <lunette/registry/value.hpp>

namespace lunette {
    namespace registry {
        namespace {
            inline HKEY key(handle const & h) {
                return HKEY(h.native());
           }

            inline PHKEY ref(handle const & h) {
                return PHKEY(&h.native());
            }

            inline value_type to_value_type(DWORD id) {
                switch(id) {
                    case REG_BINARY:
                        return value_type::binary;
                    case REG_DWORD_LITTLE_ENDIAN:
                        return value_type::dword_le;
                    case REG_DWORD_BIG_ENDIAN:
                        return value_type::dword_be;
                    case REG_EXPAND_SZ:
                        return value_type::expand_string;
                    case REG_LINK:
                        return value_type::link;
                    case REG_MULTI_SZ:
                        return value_type::multi_string;
                    case REG_NONE:
                        return value_type::none;
                    case REG_QWORD_LITTLE_ENDIAN:
                        return value_type::qword_le;
                    case REG_SZ:
                        return value_type::string;
                    case REG_RESOURCE_REQUIREMENTS_LIST:
                        return value_type::resource_requirements_list;
                    case REG_FULL_RESOURCE_DESCRIPTOR:
                        return value_type::full_resource_descriptor;
                    case REG_RESOURCE_LIST:
                        return value_type::resource_list;
                    default:
                        break;
                }
                return value_type::none;
            }

            inline DWORD to_registry_type(value_type type) {
                switch(type) {
                    case value_type::binary:
                        return REG_BINARY;
                    case value_type::dword_le:
                        return REG_DWORD_LITTLE_ENDIAN;
                    case value_type::dword_be:
                        return REG_DWORD_BIG_ENDIAN;
                    case value_type::expand_string:
                        return REG_EXPAND_SZ;
                    case value_type::link:
                        return REG_LINK;
                    case value_type::multi_string:
                        return REG_MULTI_SZ;
                    case value_type::none:
                        return REG_NONE;
                    case value_type::qword_le:
                        return REG_QWORD_LITTLE_ENDIAN;
                    case value_type::string:
                        return REG_SZ;
                    case value_type::resource_requirements_list:
                        return REG_RESOURCE_REQUIREMENTS_LIST;
                    case value_type::full_resource_descriptor:
                        return REG_FULL_RESOURCE_DESCRIPTOR;
                    case value_type::resource_list:
                        return REG_RESOURCE_LIST;
                    default:
                        break;
                }
                return REG_NONE;
            }

            inline void convert(uint32_t & stored, uint8_t const * data, size_t) {
                stored = *reinterpret_cast<uint32_t const *>(data);
            }

            inline void convert(uint64_t & stored, uint8_t const * data, size_t) {
                stored = *reinterpret_cast<uint64_t const *>(data);
            }

            inline void convert(std::vector<uint8_t> & stored, uint8_t const * data, size_t data_len) {
                stored.assign(data, data + data_len);
            }

            inline void convert(lunette::string & stored, uint8_t const * data, size_t data_len) {
                char_type const * ptr = reinterpret_cast<char_type const *>(data);
                stored.assign(ptr, ptr + (data_len / sizeof(char_type)));
            }

            template<value_type type>
            inline void convert_value(value & val, uint8_t const * data, size_t data_len) {
                typename detail::value_type2type<type>::type stored;
                val.set<type>(stored);
                convert(val.get<type>(), data, data_len);
            }

            inline void convert_value(value & val, uint8_t const * data, size_t data_len, DWORD reg_type) {
                switch(to_value_type(reg_type)) {
                case value_type::binary:
                    convert_value<value_type::binary>(val, data, data_len);
                case value_type::dword_le:
                    convert_value<value_type::dword_le>(val, data, data_len);
                case value_type::dword_be:
                    convert_value<value_type::dword_be>(val, data, data_len);
                case value_type::qword_le:
                    convert_value<value_type::qword_le>(val, data, data_len);
                case value_type::string:
                    convert_value<value_type::string>(val, data, data_len);
                case value_type::expand_string:
                    convert_value<value_type::expand_string>(val, data, data_len);
                case value_type::multi_string:
                    convert_value<value_type::multi_string>(val, data, data_len);
                case value_type::link:
                    convert_value<value_type::link>(val, data, data_len);
                case value_type::resource_requirements_list:
                    convert_value<value_type::resource_requirements_list>(val, data, data_len);
                case value_type::full_resource_descriptor:
                    convert_value<value_type::full_resource_descriptor>(val, data, data_len);
                case value_type::resource_list:
                    convert_value<value_type::resource_list>(val, data, data_len);
                default:
                case value_type::none:
                    break;
                }
            }
        }
    }
}
