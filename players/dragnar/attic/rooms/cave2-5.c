inherit "room/room";
realm() { return "NT"; }
object rock;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	rock=clone_object("/players/dragnar/items/quest/rock.c");
	move_object(rock, this_object());
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"It is pitch black here.  Anything could be hiding in the darkness.\n"+
"It seems as if it could be easy to get lost in here.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/cave2-6.c","north",
});
}
