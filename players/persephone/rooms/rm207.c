inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="The Presidential Suite";
  long_desc="This is the the Presidential Suite of the Chelsea Hotel, you cannot\n" +
            "help but be amazed by the opulence of this suite it is really quite\n" +
            "amazing. Even with all the elegance you can see definite security\n" +
            "devices all around you. The only exit is the corridor to the north.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/hcorr2b","north",
           });
 }
}
realm() { return "NT"; }
