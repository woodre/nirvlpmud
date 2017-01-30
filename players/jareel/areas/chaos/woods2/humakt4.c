/*
===================================================================
=Chaos Wood add on started 5/10/06
=Creator Jareel
=
=This area will House Some tuff monsters 
=in the theme I have created in my area.
=
=A Humakti Temple will be located in 
=the woods where I may have Mondar 
=teleport too so he is tuffer to kill
=and not farmed as much as he is now
=
=As with most of the stuff I have created
=it will not be a cake walk and is designed
=to be entertaining for players of a high
=level.
===================================================================
*/

inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
  if(arg) return;
     
  set_light(1);
  short_desc=(HIK+"Temple of Humakt"+NORM);
  long_desc=
    "Columns stand forbodding the element of chaos that surrounds the\n"+
    "small, stout temple.  Runes of Truth and Death are prominant within\n"+
    "the protective walls.  A small row of bedding lines the wall.\n"+
    "\n";
  items = ({
    "entrance","The entrance leads back into the Chaos Wood",
    "outside","The trees outside are very colorful",
    "ruins","The outside of this building looks like the temple is run down, but it is far from being that way",
    "columns","Fine marble pillars holding the building up",
    "column","This column is well constructed",
    "hallway","The hall leads off into the temple",
    "floor","A very clean surface",
    "runes","The Death and Truth runes adorn the walls",
    "death","The rune of death embodies all",
    "truth","The rune of truth keeps the Humakti strong",
    "alter","The alter is erected to supply a tithe to Lord Humakt",
    "walls","The walls keep out the crazed forest",
    "mirror","Reflections of a troubled soul look back at you",
  });

  dest_dir = ({
    "/players/jareel/areas/chaos/woods2/humakt2","north",
  });
}

Search(str) {
  if(!str) { write("Search what?\n"); return 1; }
    write("You search the "+str+" but find nothing special.\n");
    say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}