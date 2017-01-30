#include "/obj/ansi.h"
inherit "/players/earwax/housing/land.c";
inherit "room/room";
reset(arg)  {
  if(arg) return;

short_desc = BLU+"Namekian Suburbs"+NORM;
long_desc = 
"Flat area of land with mountains to the north, and south.  A road heads\n"+
"west to the temple, and the flat area continues to the east and south.\n";
items = ({
"temple","The Namekian temple is to the west",
"mountains","There are mountains to the north and far to the south",
"road","The road leads to the temple",
});
set_light(1);
dest_dir = ({
"players/mosobp/areas/HOUSING/rooms/h2.c","east",
"players/mosobp/areas/HOUSING/rooms/h5.c","south",
"players/mosobp/areas/TEMPLE/rooms/temple10.c","enter",
});
set_realm_name("Namekian Suburbs");
set_lot_size(3);
set_cost(30000);
setup_land();
}
init()
{
  ::init();
  add_action("cmd_pick", "pick");
}

cmd_pick(str)
{
  if(!str)
  {
    notify_fail("You can pick the berries.\n");
    return 0;
  }
  if(str != "berries")
  {
    notify_fail("You can only pick the berries.\n");
    return 0;
  }
  move_object(clone_object("/players/shinshi/closed/rogue/objects/berry1.c"), this_object());
  return 1;
}
