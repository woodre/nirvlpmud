inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"You are now in a huge cavern.  It is very dark and difficult to see.  There\n"+
"are bones scattered about the cave.  It seems to be getting a great deal\n"+
"warmer also.  There isn't any ice in this part of the caves.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/cave1-10.c","north",
"players/dragnar/WasteLands/rooms/past/cave1-8.c","south",
});
}
