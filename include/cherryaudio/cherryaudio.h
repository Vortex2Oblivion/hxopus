#ifndef CHERRYAUDIO_H
#define CHERRYAUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

typedef long long unsigned int cherry_size;

typedef struct {
    unsigned int channels;
    unsigned int sample_rate;
    cherry_size sample_count;
} cherry_metadata;

typedef struct {
    void *data;
    cherry_size size;
} cherry_pcm;

typedef struct {
    cherry_pcm pcm;
    cherry_metadata meta;
} cherry_file;

cherry_file cherry_load_file_from_memory(void *memory, cherry_size size);

#ifdef __cplusplus
}
#endif // extern "C" {

#endif // !CHERRYAUDIO_H
