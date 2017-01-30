inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
object invis;
reset(arg) {
invis=clone_object("players/dragnar/rooms/sign.c");
move_object(invis, this_object ());
	if(arg) return;
set_light(10);
short_desc=("Gate to town");
long_desc=
"You begin to cross the bridge picking your way carefully. The going is\n" +
"hard and although the bridge isn't that high you don't want\n" +
"to chance falling.  As you reach about half way across you notice a\n" +
"sign on the side of the bridge that is hanging unevenly.\n",
items=
({"sign","With the huge dust cloud over the sun you have to strain to read it...\n\n" +
"ABSOLUTELY NO JUMPING OFF BRIDGE! DO SO AT YOUR OWN RISK",
});
dest_dir=
({
"players/dragnar/rooms/bridge2.c","east",
"players/dragnar/rooms/room_road2.c","west",
});
}
