#define shit ninja=clone_object("/players/dragnar/WasteLands/mons/ninja.c");
#define fuck move_object(ninja, this_object());
#define change ninja=clone_object("/players/dragnar/WasteLands/mons/ninja2.c");
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
	shit
	fuck
	shit
	fuck
	shit
	fuck
	change
	pain
	change
	pain
	change
	pain
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"This is the narrowest part of the path.  Off to the west it seems to widen out\n"+
"into a clearing. The only other way to go is back the way you came on\n"+
"the path.\n",
items=
({
"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"/players/dragnar/WasteLands/rooms/path","north",
"/players/dragnar/WasteLands/rooms/path2","west",
});
}
