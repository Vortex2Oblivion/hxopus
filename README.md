<p align="center">
    <img src="logo.png" width="256" />
</p>
<p align="center">  
    <img src="https://img.shields.io/github/repo-size/Vortex2Oblivion/hxopus" />
    <img src="https://badgen.net/github/open-issues/Vortex2Oblivion/hxopus" />
    <img src="https://badgen.net/badge/license/MIT/green" />
</p>

Haxe support for the [Opus Audio Codec](https://opus-codec.org/)

This library works on the C++ target only!

### Installation

```bash
haxelib install hxopus
```

Or through git.

```bash
haxelib git hxopus https://github.com/Vortex2Oblivion/hxopus.git
```

### Usage

Hxopus provides helper functions for easy playback on some popular game frameworks

### OpenFL

```hx
// Passing the filename in directly.
var sound:Sound = Opus.toOpenFL("path/to/your/sound.opus");
sound.play();

// Or with the raw bytes
var sound:Sound = Opus.toOpenFL(Assets.getBytes("path/to/your/sound.opus"));
sound.play();
```

### Flixel

```hx

// Passing the filename in directly.
var sound:FlxSound = Opus.toFlxSound("path/to/your/sound.opus");
sound.play();

// Or with the raw bytes
var sound:FlxSound = Opus.toFlxSound(Assets.getBytes("path/to/your/sound.opus"));
sound.play();
```

### Other

If you are using another framework you will have to support it yourself. However Hxopus provides helper functions for decoding the audio file and getting the bytes,

```hx
Bytes.ofData(Opus.getDecodedBytes(bytes:Bytes));
```

### Credits

[Xiph.org Foundation](https://xiph.org/) - [Libopus](https://github.com/xiph/opus) and [Opusfile](https://github.com/xiph/opusfile) libraries.

[Gian-Carlo Pascutto](https://github.com/gcp) - [Libogg](https://github.com/gcp/libogg).

[Cherry](https://git.gay/cherry) - [CherryAudio](https://git.gay/cherry/cherryaudio) used for decoding the opus files and helping me optimize the opus loader.

[Carlos Ballesteros Velasco](https://github.com/soywiz) - [OpenFL-Opus](https://lib.haxe.org/p/openfl-opus/) Referenced a lot when making hxopus.

[Prio](https://www.youtube.com/channel/UChNtItn8z2v51fjNhwiDQHQ) - [Shockwave Shuffle](https://www.youtube.com/watch?v=q4TIa9ZIQPU) Song used for testing playback.
