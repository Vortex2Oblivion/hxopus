#ifndef HXOPUS_H
#define HXOPUS_H

#include <hx/CFFIPrime.h>
#include <hxcpp.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

const char * hxopus_get_version_string();

typedef Array_obj<unsigned char> *ByteArray;


ByteArray hxopus_to_bytes(::Array< unsigned char >  data_buffer_value);
#endif // HXOPUS_H