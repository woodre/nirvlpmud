/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";
inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A grove of sequoya trees that tower over the rest of the forest.";
  long_desc = 
   "A large grove of ancient sequoya trees which extend all around.\n"+
   "Unfortunately brambles make it hard to move at all in almost any\n"+
   "direction.\n";
  dest_dir = ({"players/zone/rooms/circle.c", "south",
               "players/zone/rooms/path4.c", "west",
               "players/zone/rooms/base.c", "southeast"});
  }
  set_realm_name("Forest");
  set_lot_size(2);
  set_cost(230000);
  setup_land();
}
