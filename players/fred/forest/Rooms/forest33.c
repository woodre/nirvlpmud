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
      "  A small room within the den. The entire room is formed\n"+ 
      "out of solid rock. Small droplets of water fall from the\n"+
      "ceiling and splash into a small pool on the floor.\n");
   add_item("den","A large den of unknown origin");
   add_item("droplets","Small droplets of water from all the moisture in the den");
   add_item("ceiling","The ceiling has moisture forming on it");
   add_item("floor","The stone floor is cold and barren");
   add_item("pool","A small pool of water formed by the falling water"); 
   add_listen("main","The room is quiet except for the water falling into the pool");
   add_exit("/players/fred/forest/Rooms/forest32.c","east");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/ferret.c");
}

