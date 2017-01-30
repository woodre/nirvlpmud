/* 10/11/05 Earwax: Made room land. */

inherit "room/room";
inherit "/players/earwax/housing/land.c";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Gorge");
long_desc=
"Ahead of you now you can see what used to be an island in the middle of\n" +
"the gorge.  You notice that the ground is begining to look more normal\n" +
"and less like glass.  You wonder what could have made so much heat\n" +
"that it melted sand into glass.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/gorge3.c","north",
"players/dragnar/WasteLands/rooms/gorge.c","south",
});

  set_lot_size(2);
  set_realm_name("Wastelands");
  set_cost(100000);
  setup_land();

}
