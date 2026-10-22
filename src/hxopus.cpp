#include "hxopus.hpp"

#include "opusfile.h"

namespace hxopus
{

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

	ByteArray decodeBytes(::Array<unsigned char> _d)
	{
		ByteArray data_buffer_value = _d.GetPtr();
		if (!is_buffer(data_buffer_value))
		{
			throw "Expected to be a buffer";
			return null();
		}

		ByteArray input = data_buffer_value;
		OggOpusFile *opus = op_open_memory((unsigned char *)get_buffer_data(input), get_buffer_size(input), NULL);
		int channels = op_channel_count(opus, -1);
		ogg_int64_t sample_count = op_pcm_total(opus, -1);

		ogg_int64_t file_size = sample_count * channels;
		void *data = malloc(file_size * sizeof(short));

		// decoding
		auto frames = 0;
		while (frames < sample_count)
		{
			auto frame_offset = frames * channels;
			frames += op_read(opus, (short *)data + frame_offset, file_size - frame_offset, NULL);
		}

		op_free(opus);

		ByteArray b = (ByteArray)alloc_buffer_length(file_size * sizeof(short));
		memcpy(b->GetBase(), data, b->length);
		free(data);
		return b;
	}
}