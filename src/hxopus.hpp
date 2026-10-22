#pragma once

#include "hxcpp.h"

namespace hxopus{
    typedef Array_obj<unsigned char> *ByteArray;
    
    ByteArray decodeBytes(Array<unsigned char> data_buffer_value);
}