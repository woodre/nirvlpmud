#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(!present("large water spirit") && !present("small water spirit"))
    add_object(ROOT+"monster/water_spirit2.c");  
    for(x = 0; x < 3; x++) 
      add_object(ROOT+"monster/water_spirit1.c");
  }   
  if(arg) return;
  short_desc = "Inside the fountain";
  long_desc = 
    "The water inside the fountain swirls violently.  With such an\n"+
    "ongoing disturbance, its difficult to make out any details of\n"+
    "the fountain itself.\n";
  set_light(1);
  items = ({ });
  add_item(({"fountain","water","detail","details"}),
    "With all the churning water, you can barely see anything");             
  add_exit(ROOT+"castle/fountain","out");
}

status stop_churn() {
  long_desc = 
    "The water inside the fountain is calm and clear.  Slight movement\n"+
    "in the water causes the red-streaked marble to appear to bend and\n"+
    "wave.  Bright light from above filters down to the bottom of the
    "fountain.\n";
  items = ({ });
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");
  add_item(,
    "");          
  add_item(,
    "");     
}