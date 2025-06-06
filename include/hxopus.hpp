#ifndef HXOPIS_H
#define HXOPIS_H
#include <hx/CFFIPrime.h>

static const char * hxopus_get_version_string();

typedef Array_obj<unsigned char> *ByteArray;


static ByteArray hxopus_to_bytes(ByteArray data_buffer_value);
#endif // HXOPIS_H