#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include "cherryaudio.h"
#include <opus.h>

#include <hx/CFFIPrime.h>
#include <hx/CFFI.h>
#include <hxcpp.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <opus_defines.h>

typedef Array_obj<unsigned char> *ByteArray;

static const char * hxopus_get_version_string() {
	return opus_get_version_string();
}
DEFINE_PRIME0(hxopus_get_version_string);

static buffer hxopus_to_bytes(value data_buffer_value) {
	if (!val_is_buffer(data_buffer_value)) {
		val_throw(alloc_string("Expected to be a buffer"));
		return null();
	}

	buffer input = val_to_buffer(data_buffer_value);
	cherry_file file = cherry_load_file_from_memory(buffer_data(input), buffer_size(input));

	buffer buf = alloc_buffer_len(file.pcm.size);
	ByteArray b = (ByteArray) buf;
	memcpy(b->GetBase(), file.pcm.data, b->length);
	free(file.pcm.data);
	return buf;
}