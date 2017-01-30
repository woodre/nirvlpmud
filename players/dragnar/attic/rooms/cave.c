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
"It is even darker inside the cave.  Ice lines every wall and the floor.\n"+
"The exit out is small but it is larger inside.  In front of you are\n"+
"three passagways.  They all look the same.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/cave1-1.c","northeast",
"players/dragnar/rooms/cave2-1.c","north",
"players/dragnar/rooms/cave3-1.c","northwest",
"players/dragnar/rooms/path2.c","out",
});
}
