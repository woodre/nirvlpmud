/* 10/11/05 Earwax: Made this room land, so players can 'buy' it. */

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
"Looking up at the bridge you realize that there is no way to get back.\n" +
"The sides of the gorge are steep here and the surface is so glass\n" +
"like there is no way you are able to climb up them.  It looks as if\n" +
"the only way you can go is north where the river used to flow.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/gorge2.c","north",
});

  set_lot_size(2);
  set_realm_name("Wastelands");
  set_cost(100000);
  setup_land();

}
