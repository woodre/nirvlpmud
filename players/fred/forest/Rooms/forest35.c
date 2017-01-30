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
      "  A small dark room in the den with leaves and other brush\n"+ 
      "covering the floor. The walls and ceiling are solid rock.\n");
   add_item("den","A large den of unknown origin");
   add_item("leaves","Leaves are scattered on the floor making a soft cushion like floor");
   add_item("brush","Small twigs and other things from the forest");
   add_item("walls","The thick walls are solid rock");
   add_item("ceiling","The ceiling has moisture forming on it");
   add_listen("main","Strange rustling noises fill the room.");
   add_exit("/players/fred/forest/Rooms/forest34.c","west");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/ferret.c");
}

