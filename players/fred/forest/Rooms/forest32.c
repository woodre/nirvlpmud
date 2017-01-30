#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(0);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  As you look around the cave you realize that this isn't a\n"+
      "cave at all. It is actually a large den. Leaves and other brush\n"+ 
      "are scattered across the floor. What could possibly be in here?\n");
   add_item("cave","It's not actually a cave it's a den");
   add_item("den","A large den of unknown origin");
   add_item("leaves","Leaves are scattered on the floor making a soft cushion like setting");
   add_item("brush","Small twigs and other things from the forest");
   add_item("floor","The floor is covered with brush from the forest");
   add_listen("main","Strange rustling noises fill the den.");
   add_exit("/players/fred/forest/Rooms/forest31.c","out");
   add_exit("/players/fred/forest/Rooms/forest33.c","west");
   add_exit("/players/fred/forest/Rooms/forest34.c","east");
   add_exit("/players/fred/forest/Rooms/forest37.c","south");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
}

