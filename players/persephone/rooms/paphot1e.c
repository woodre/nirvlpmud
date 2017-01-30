inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(0);
  short_desc="Damp Wet Corridor";
  long_desc="You are in a damp corridor that smells extremely musty. Both the walls\n" +
            "and the floor seemed to be covered in something while the ceiling also\n" +
            "looks strange. This corridor continues to the east while to the north,\n" +
            "west and south you see rooms.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/paphot1f","west",
              "players/persephone/rooms/paphot1d","east",
  });
 }
}
