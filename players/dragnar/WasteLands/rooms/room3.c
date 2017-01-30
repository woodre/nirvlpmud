#define shit ninja=clone_object("/players/dragnar/WasteLands/mons/ninja2.c");
#define fuck move_object(ninja, this_object());
inherit "room/room";
object ninja;
init() {
	::init();
	this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area();
}
reset(arg) {
	ninja=clone_object("/players/dragnar/WasteLands/mons/ninja2.c");
	move_object(ninja, this_object());
	shit
	fuck
	shit
	fuck
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
"players/dragnar/WasteLands/rooms/room2.c","south",
"players/dragnar/WasteLands/rooms/forest.c","north",
});
}
