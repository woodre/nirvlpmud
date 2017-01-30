inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
  if(!present("sheriff")){
  move_object(clone_object("players/persephone/monster/sheriff"),TOB);
  }
 if (!arg) { 
  set_light(1);
  short_desc="Prison Cell";
  long_desc="You have just entered a prison cell it looks much like every other prison\n" +
           "against the west wall you see the normal sanitary facilities and a small\n" +
           "cell window. Wandering around the middle of the cell looking miserable\n" +
           "and muttering to himself is an old man.\n\n";
items=({"cell","This is just the standard prison cell with none of the\n" +
               "modern conveniences not even a picture on the wall",
        "facilities","Well let's see there is a toilet a wash basin and\n" +
                     "a roll of toilet paper. Who could ask for more",
        "window","The window is barred and out of it you see a\n" +
                 "stone wall",
        "walls","The walls are very plain and in the west wall is a window",
        "floor","The floor is just concrete",
        "toilet","Actually bucket would be a more apt description\n" +
                 "for the toilet",
        "basin","The basin is steel and attached firmly to the wall",
        "paper","Ordinary unbleached and recycled toilet paper",
        "bars","The bars are very strong and you might as well forget about\n" +
               "trying to escape",
      });          
  dest_dir=({"players/persephone/rooms/pol_stat2","west",
            });
  ("players/persephone/rooms/pol_stat2"->load_up());
 }
}
realm(){ return "NT";}
