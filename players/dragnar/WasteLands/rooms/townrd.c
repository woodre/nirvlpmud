/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wastelands town");
long_desc=
"Farther off to the east the ruins of the town are drawing very close.\n"+
"You can see only one building that is still standing.  It's too dark to\n"+
"see if anyone has noticed you.  To the west is a deadly looking bridge.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/townrd2.c","east",
"players/dragnar/WasteLands/rooms/bridge2.c","west",
});

  set_realm_name("Wastelands");
  set_lot_size(2);
  set_cost(100000);
  setup_land();

}
