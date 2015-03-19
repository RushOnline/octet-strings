#ifndef __OCTET_STRING_H__
#define __OCTET_STRING_H__

#include <string>

#include <stdio.h>

namespace std {

class octet_string : public basic_string<unsigned char> {
public:
	typedef	basic_string<unsigned char> base_type;

	octet_string() : base_type() {};
    octet_string(base_type _i) : base_type(_i) {};

};


}//namespace std
#endif//__OCTET_STRING_H__
