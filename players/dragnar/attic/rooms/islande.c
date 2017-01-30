/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(5);
short_desc=("Island of the temple");
long_desc=
 "As you look back toward the gorge you can sense where the bridge is but\n"+
"it is swallowed by the day's darkness.  Looking around you realize that\n"+
"further travel is impossible except the way that you came.\n",
dest_dir=
({
"players/dragnar/rooms/island.c","west",
});
  set_realm_name("Wastelands");
  set_lot_size(6);
  set_cost(250000);
  setup_land();
}
