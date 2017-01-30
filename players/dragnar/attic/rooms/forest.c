#define shit ninja=clone_object("/players/dragnar/mons/ninja2.c");
#define fuck move_object(ninja, this_object());

inherit "room/room";
object ninja;
init() {
	::init();
	this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area(); }
reset(arg) {
/* shit fuck shit fuck  removed -Snow */
  shit 
  fuck
  shit
  fuck
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"As you get deeper into the forest you feel more and more like you are being\n"+
"watched.   You wonder if maybe something doesn't want you to venture\n"+
"here and find the secret of the forest.\n",
items=
({"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/rooms/room3.c","south",
"players/dragnar/rooms/forest2.c","north",
"players/dragnar/rooms/forest3.c","east",
});
}
