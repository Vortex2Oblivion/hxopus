#include "hxopus.hpp"

#include "cherryaudio.h"

#include <hx/CFFIPrime.h>
#include <hxcpp.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef Array_obj<unsigned char> *ByteArray;


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