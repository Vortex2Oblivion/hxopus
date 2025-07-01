#include "cherryaudio.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <opusfile.h>

cherry_file cherry_load_file_from_memory(void *memory, cherry_size size) {
    cherry_file file = (cherry_file){0};
    OggOpusFile *opus = op_open_memory(memory, size, NULL);
    file.meta.channels = op_channel_count(opus, -1);
    file.meta.sample_rate = 48000;
    file.meta.sample_count = op_pcm_total(opus, -1);

    cherry_size file_size = file.meta.sample_count * file.meta.channels;
    file.pcm.data = malloc(file_size * sizeof(short));

    // decoding
    cherry_size frames = 0;
    short *buf = file.pcm.data;
    while (frames < file.meta.sample_count) {
        cherry_size frame_offset = frames * file.meta.channels;
        frames += op_read(opus, buf + frame_offset, file_size - frame_offset, NULL);
    }

    file.pcm.size = file_size * sizeof(short);
    op_free(opus);
    return file;
}

#ifdef __cplusplus
}
#endif // extern "C" {
