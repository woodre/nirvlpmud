inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(arg) return;
  set_light(0);
  short_desc="Eerie Path";
  long_desc="The air in this part of the jungle is getting even\n" +
            "thicker and you feel that you would be much safer\n" +
            "going back the way you came. The trees are now closing\n" +
            "in around you and you here many blood curdling howls to\n" +
            "the east and back to the west the path looks lighter.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/junpat1","west",
             "players/persephone/rooms/warglr","east",
           });
}
