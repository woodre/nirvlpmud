inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("town road");
long_desc=
	"As you walk closer to the bridge you can see it doesn't look very stable.\n" +
"It has huge holes in it and it looks like it would be difficult to\n" +
"cross.  To the north is a graveyard which looks like it has recently\n" +
"been used.  However you still don't see anyone around.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/room_road2.c","east",
"players/dragnar/WasteLands/rooms/room_road.c","west",
"players/dragnar/WasteLands/rooms/graveenter.c","north",
});
}
