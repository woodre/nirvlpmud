inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(1);
  short_desc="Damp Corridor";
  long_desc="You are in a damp musty corridor that continues to the west while you\n" +
            "see the top of a staircase to the east and rooms to the north an south\n" +
            "All around you there are big piles of bodies and there is a dark pool\n" +
            "of liquid just next to them.\n" +
            "\n";
  items=({"corridor","You do not know how anyone in their right mind would call this\n" +
                     "a corridor but it once had white walls and a while ceiling",
          "ceiling","The ceiling which use to be white now is a sickly shade of green\n" +
                    "which leads you to think that some sort of mould has started to\n" +
                   "grow on the ceiling",
          "floor","Bodies of all shapes and sizes obscure the floor this must have\n" +
                  "really been a massacre",
          "walls","They are totally covered in a brownish liquid that has finger marks\n" +
                  "running down them",
          "liquid","You guessed it this liquid is definately blood",
          "blood","You know that reddy brown stuff that runs through you veins",
          "bodies","What do you think a body is a dead human corpse but in this\n" +
                   "instance there a lot of them",
          "rooms","There is absolutely no way you can enter these rooms bodies block\n" +
                  "entrances and you are starting to doubt whether you want to\n" +
                  "west perhaps east is the safer way",
           });
  dest_dir=({"players/persephone/rooms/paphot1e","west",
             "players/persephone/rooms/stairsa2.c","east",
  });
 }
}
realm() { return "NT";}
