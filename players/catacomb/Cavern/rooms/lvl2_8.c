#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  Several torches line the walls of the cavern.  The light makes\n"+
  "creepy shadows on the rock walls.  The shadows almost seem to take\n"+
  "the form of humanoids, but then disappear into nothing. The \n"+
  "crackling of the torches give an uneasy feeling to all who \n"+
  "tread within the caverns of the Durkor\n"); 

  items = ({
    "torch",
    "One of the several torches lining the wall",
    "torches",
    "The amount of torches on the wall seem strange for where you are", 
    "walls",
    "The walls are lined with torches",
    "wall",
    "The wall is lined with several torches", 
    "shadow",
    "The shadows seem to take on a life of their own", 
    "shadows",
    "The shadows seem to take on a life of their own", 
 });
     
  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_6.c","northeast",
    "/players/catacomb/Cavern/rooms/lvl2_9.c","west"
  });
}
