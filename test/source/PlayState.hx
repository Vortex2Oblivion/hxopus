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
		FlxG.sound.list.add(Opus.toFlxSound("assets/music/shockwaveshuffle.opus")).play();
		trace("Loaded in " + (Sys.time() - time) + " seconds");
	}

	override public function update(elapsed:Float) {
		super.update(elapsed);
	}
}
