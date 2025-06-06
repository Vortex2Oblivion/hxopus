package;

import sys.io.File;
import openfl.media.Sound;
import hxopus.Opus;
import openfl.utils.Assets;
import openfl.utils.ByteArray;
import flixel.FlxGame;
import openfl.display.Sprite;

class Main extends Sprite {
	public function new() {
		super();
		trace('Opus version: ' + Opus.getVersionString());
		addChild(new FlxGame(0, 0, PlayState));
	}
}
