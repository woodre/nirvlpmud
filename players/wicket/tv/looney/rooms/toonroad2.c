inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("melody", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/melody.c"), this_object());
if(!present("barky", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/barky.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "On a "+HIK+"Road "+NORM+"in "+HIC+"Tiny"+HIW+" Toon"+HIC+" Town"+NORM+"";
  long_desc = " A small simple road leading into tiny toon town. Off to the west of\n\
  is a small alley way. Clutter of all kinds fills the little alley making\n\
  it nasty. To the East of the road a small pond can be seen. Wildlife flies\n\
  and wanders all about the pond. Back to the south is more road and to the\n\
  north goes deeper into Tiny Toon Land.\n";
  items = 
  ({
    "pond",
    "A very good size pond that had all kinds of animals and wildlife living there",
    "alley",
    "A small trashy alleyway",
    "wildlife",
    "All kinds of animals like birds, bees and butterflies can be seen all about the area",
    "clutter",
    "Old trash and papers of all kinds are in a piles of clutter all over the place in the alley",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/toonroad1.c","south",
  "/players/wicket/tv/looney/rooms/alleyway.c","west",
  "/players/wicket/tv/looney/rooms/pond.c","east",
  "/players/wicket/tv/looney/rooms/toonroad3.c","north",
  });
  } 