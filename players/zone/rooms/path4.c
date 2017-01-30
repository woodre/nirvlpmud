/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";
inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Forest";
  long_desc = 
   "You loose the blaze, but notice that the forest turns into brambles to the\n"+
   "west and north.  To the east there are large trees, towering over all the\n"+
   "others.\n";
  dest_dir = ({"players/zone/rooms/path3.c", "south",
	       "players/zone/rooms/tree.c", "east"});
  }
  set_realm_name("Forest");
  set_lot_size(1);
  set_cost(200000);
  setup_land();
}
