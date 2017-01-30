#include "../def.h"
inherit MYROOM;
reset(arg) {
  if(!present("azure portal")) {
    object gate;
    gate=clone_object("/players/feldegast/obj/azure_portal");
    gate->set_destination("/players/feldegast/shrine");
    move_object(gate,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Town Square";
  long_desc=
"     Tall buildings surround the town square of the city of\n"+
"Haven.  In the center of the square is a magnificent marble\n"+
"fountain with openmouthed fishes spitting plumes of water.\n"+
"To the north is a gothic cathedral while to the south are\n"+
"the steps of city hall.\n";
  items=({
    "buildings","The crowded buildings of Haven are typically two to three\n"+
                "stories in height.  The buildings near you are prosperous\n"+
                "and well-maintained",
    "fountain","A white marble fountain with fishes spitting plumes of water",
    "plumes","Frothing white water leaving a rainbow trail in the mist",
    "water","The water frothes white",
    "cathedral","A tall arching cathedral of the gothic style",
    "steps","Tall steps leading up to the entrance",
    "city hall","A tall three story building that looks official"
  });
  dest_dir=({
    PATH+"Haven/cathedral","north",
    PATH+"Haven/iron4","west",
    PATH+"Haven/azure1","east",
    PATH+"Haven/townhall1","south"
  });
}   
