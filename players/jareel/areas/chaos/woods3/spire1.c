inherit "room/room";
#include "/players/jareel/define.h"

#define LINE1 "Giant crimson columns stand foreboding the elements of chaos"
#define LINE2 "that surrounds the small lunar spire.  The open air lets the" 
#define LINE3 "light from the Red Goddess flood over the alabaster alter in"  
#define LINE4 "the open air chamber.  Crimson light radiates out from the powerful"
#define LINE5 "powerful ruby crystals encrusted around the chamber."

reset(arg) {

if (random(2) == 0)
  if(!present("jilios"))  {
    MOCO("/players/jareel/monsters/LUNAR/CrimsonBat/Jillios.c"),this_object());
#if 0 /* Added for a bit of tracking for now - Rump */
    if (!present("logit"))
    MOCO("/players/rumplemintz/obj/logit.c"), this_object());
#endif
  }

  if(arg) return;
      
  set_light(1);
  short_desc=(RED+"Spire of the Crater Maker"+NORM);
  
  long_desc=
    "\n"+HBWHT+"     "+NORM+"  "+LINE1+"\n"+
    HBWHT+"  "+NORM+"X"+HBWHT+"  "+NORM+"  "+LINE2+"\n"+
    HBWHT+" "+NORM+"   "+HBWHT+" "+NORM+"  "+LINE3+"\n"+
    HBWHT+"  "+NORM+" "+HBWHT+"  "+NORM+"  "+LINE4+"\n"+
    HBWHT+"     "+NORM+""+NORM+"  "+LINE5+"\n";
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
    "/players/jareel/areas/chaos/woods3/spire","south",

		
  });
}


Search(str) {
  if(!str) { write("Search what?\n"); return 1; }
    write("You search the "+str+" but find nothing special.\n");
    say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
