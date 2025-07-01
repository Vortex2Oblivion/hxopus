#include "hxopus.hpp"

#include "cherryaudio.h"

#include <hx/CFFIPrime.h>
#include <hxcpp.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "opus_defines.h"


typedef Array_obj<unsigned char> *ByteArray;

const char * hxopus_get_version_string(){
	return opus_get_version_string();
}

inline bool is_buffer(ByteArray object)
{
	return object != 0;
}

inline ByteArray alloc_buffer_length(int inLen)
{
	return new Array_obj<unsigned char>(inLen, inLen);
}

inline char *get_buffer_data(ByteArray inBuffer)
{
	return inBuffer->GetBase();
}

inline int get_buffer_size(ByteArray inBuffer)
{
	return inBuffer->length;
}

ByteArray hxopus_to_bytes(::Array< unsigned char > _d)
{
	ByteArray data_buffer_value = _d.GetPtr();
	if (!is_buffer(data_buffer_value))
	{
		throw "Expected to be a buffer";
		return null();
	}
	

	ByteArray input = data_buffer_value;
	cherry_file file = cherry_load_file_from_memory(get_buffer_data(input), get_buffer_size(input));

	ByteArray buf = alloc_buffer_length(file.pcm.size);
	ByteArray b = (ByteArray)buf;
	memcpy(b->GetBase(), file.pcm.data, b->length);
	free(file.pcm.data);
	return buf;
}