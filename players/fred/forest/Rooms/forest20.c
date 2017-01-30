#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  You have entered a small clearing hidden to the outside world.\n"+
      "It is just an open area with several large boulders and a couple\n"+ 
      "of trees. Birds fly around the area looking for food.\n");
   add_item("area","A large open area");
   add_item("boulders","Large boulders that have been here for years");
   add_item("trees","Huge trees that have been growing over the centuries");
   add_item("birds","Small birds that chirp softly");
   add_touch("trees","The trees bark is rough...Ouch!");
   add_listen("main","You hear the sounds of birds chirping away.");
   add_exit("/players/fred/forest/Rooms/forest19.c","leave");
   add_object("/players/fred/forest/Mon/vinni.c");
   add_property("NF");	
}

