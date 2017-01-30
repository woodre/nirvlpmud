#include "/players/ccatacomb/misc/ansi.h"
inherit "room/room";

reset(arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc ="Kami's Lookout" ;
   long_desc =(
      " The fine snow white marble reflects the sun so bright that\n"+
      "it is almost blinding.  Along the outskirts of the lookout,\n"+
      "palm trees are placed.  Somehow the lookout is balanced \n"+
      "several miles above Nirvana by a column only a couple of \n"+
      "feet around.  A large bell-shaped building stands on the\n"+
      "back side of the lookout\n"); 
   
   items = ({
         "marble",
         "The marble under your feet shine bright under the sun",
         "outskirts",
         "A couple of palm trees are at the edge of the lookout",
         "trees",
         "Somehow the trees still seem to live up here",
         "tree",
         "A regular palm tree, nothing special",
         "edge",
         "Looking over the edge you can see a thin layer of clouds underneath",
         "column",
         "A thin intricately-carved marble column disappears beneath the clouds",
         "cloud",
         "Thin wispy clouds are all that can be seen under the lookout",
         "clouds",
         "Thin wispy clouds are all that can be seen under the lookout",
         "building",
         "The building is actually the hyperbolic time chamber where you can test your powers"
         
         
   
   dest_dir = ({
         "/players/catacomb/saiyan/Tchamber.c","chamber",
         "/players/catacomb/saiyan/lookout2.c","west",
         "/players/catacomb/saiyan/lookout3.c","east",
         "/players/catacomb/cave.c","exit", 
         "/play});
   
}

