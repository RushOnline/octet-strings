#include <openssl/des.h>
#include <assert.h>
#include <exception>
#include <iostream>


#include "octet_string.h"

namespace std {

template<typename T>
T* cast_ptr(octet_string& bytes) {
    assert(bytes.size() >= sizeof(T));
    return reinterpret_cast<T*>( const_cast<unsigned char*>(bytes.data()) );
}

} //namespace std

using namespace std;

octet_string xrandom_key() {
    octet_string result;
    result.resize(sizeof(DES_cblock));
    DES_random_key(cast_ptr<DES_cblock>(result));
    return result;
}

int main(int argc, char* argv[]) {

    try {
        octet_string k( xrandom_key() + xrandom_key() );
    } catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

