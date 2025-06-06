package;

import flixel.FlxG;
import flixel.FlxState;
import flixel.sound.FlxSound;
import sys.io.File;
import hxopus.Opus;

class PlayState extends FlxState {
	override public function create() {
		super.create();

		var time:Float = Sys.time();
		Opus.toFlxSound("assets/music/shockwaveshuffle.opus").play();
		trace(Sys.time() - time);
	}

	override public function update(elapsed:Float) {
		super.update(elapsed);
	}
}
