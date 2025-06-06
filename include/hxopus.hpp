#ifndef HXOPUS_H
#define HXOPUS_H

#include <hxcpp.h>

static const char * hxopus_get_version_string();

typedef Array_obj<unsigned char> *ByteArray;


static ByteArray hxopus_to_bytes(::Array< unsigned char >  data_buffer_value);
#endif // HXOPUS_H