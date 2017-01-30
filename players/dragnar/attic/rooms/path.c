#define shit ninja=clone_object("/players/dragnar/mons/ninja.c");
#define fuck move_object(ninja, this_object());
#define change ninja=clone_object("/players/dragnar/mons/ninja2.c");
#define pain move_object(ninja, this_object());
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
	change
	pain
	shit
	fuck
	shit
	fuck
	shit
	fuck
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"Here the clearing of the path gets narrower.  All around you lies what is\n"+
"left of a great forest.  You get a chill as you look up at the blacked\n"+
"out sky.  The path continues on, and you can't see any other way to go.\n",
items=
({
"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/rooms/path1.c","south",
"players/dragnar/rooms/forest2.c","east",
});
}
