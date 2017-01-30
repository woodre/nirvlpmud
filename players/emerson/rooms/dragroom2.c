inherit "room/room";
object ninja;
init() {
	::init();
}
reset(arg) {
	ninja=clone_object("/players/dragnar/mons/ninja2.c");
	move_object(ninja, this_object());
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"As you enter the ruined forest, you notice all of the burnt trees\n"+
"and torn up ground.  The lighting is still dim from the dust cloud\n"+
"that seems to hang in the sky.  You feel like you are being watched\n"+
"and wonder what could be hiding in the shadows.\n",
items=
({"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/rooms/room2.c","south",
"players/dragnar/rooms/forest.c","north",
});
}
