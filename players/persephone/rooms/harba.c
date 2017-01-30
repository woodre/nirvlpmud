inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="Harbour Edge";
  long_desc="You have come to the Edge of a Small Carabbian style harbour. To the\n" +
             "Northeast you see the first of three wharves there appears to be\n" +
            "some sort of activity on the wharf to the Notheast while there appears\n" +
            "to be a lot of commotion further to the East and to the Norwest you\n" +
            "see a beach.\n";
  items=({"beach","A sandy white beach that seems to be innaccessable",
          "wharves","Where ships dock silly there seems to be a great\n" +
                    "deal of activity on them",
          "commotion","It almost appears as if there is some sort of Auction",
         });
  dest_dir=({
             "players/persephone/rooms/harbb","east",
             "players/persephone/rooms/pier1a","northeast",
  });
 }
}
realm(){ return "NT"; }
