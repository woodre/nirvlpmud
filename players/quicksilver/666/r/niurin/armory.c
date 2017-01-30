#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("Yn Shapp Eilley");
   set_long("   As you walk in the room, stifiling heat from the forge hits your flesh.\n"+
   "   Lining the shop's walls are well-crafted armors created from a vast variety\n"+
   "of materials.  Each suit seems to have a distinct personality to it.  You can\n"+
   "tell that the proprietor of this armory takes great pride in his work.");
   add_item("armor", "The many different suits of armor line the walls, waiting to be filled by noble\nwarriors.");
   add_item("suits of armor", "The many different suits of armor line the walls, waiting to be filled by noble\nwarriors.");
   add_item("walls", "The many different suits of armor line the walls, waiting to be filled by noble\nwarriors.");
   add_item("forge", "The forge by which these sheets of metal become armor blazes quietly.");
   add_exit(ROOM_DIR+"niurin/main1", "west");
}

init() {
   ::init();
}
