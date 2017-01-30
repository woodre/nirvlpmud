#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  A small clearing on the outskirts of the forest.  The trees\n"+ 
      "are thinner here allowing sunlight to penetrate this usually\n"+
      "gloomy area.  Tall grass and patches of colorful wild flowers\n"+
      "sway gently in the breeze.\n");

   add_item("clearing","A small clearing on the outer edge of the forest.\n"+
            "It might be nice location to build a little cottage");
   add_item("forest","A thriving forest filled with strange creatures");
   add_item("trees","Large oak trees provide shade to this area");
   add_item("grass","Thick green grass");
   add_item("flowers","Wild flowers of all kinds surround the clearing");
   add_item("wild flowers","Wild flowers of all kinds surround the clearing");
   add_smell("main","The scent of wild flowers invades your senses");
   add_listen("main","You hear some birds chirping off in the distance.");
   add_exit("/players/fred/forest/Rooms/forest12.c","southwest");
   
   
   /* For Waxy's Land Development */
   
   set_cost(225000);
   set_realm_name("CRaZed FoReSt");
   set_lot_size("6"); /* house, cottage */
   setup_land();
}
