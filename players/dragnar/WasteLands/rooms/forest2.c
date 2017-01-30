/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
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
/* shit fuck shit fuck  removed -Snow */
	shit
	fuck
	change
	pain
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"The farther you get into the ruined forest the more dense the ruins\n"+
"get.  Looking back the way you came it seems like you have been walking on\n"+
"a cleared path.  To the north is the gorge and the path continues west.\n",
items=
({
"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/forest.c","south",
"players/dragnar/WasteLands/rooms/forest4.c","north",
"players/dragnar/WasteLands/rooms/path.c","west",
});

  set_realm_name("Wastelands");
  set_cost(120000);
  set_lot_size(3);
  setup_land();

}
