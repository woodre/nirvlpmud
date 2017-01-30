inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (arg) return;
  set_light(0);
  short_desc="Dark Path";
  long_desc="The dark narrow path turns at this point. To the south your way is\n" +
            "blocked by a very dense jungle. The path coninues either to the east\n" +
            "into the jungle or to the north which look much more hospitable. \n" +
            "Trees  surround the path and they appear to get thicker to the east.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/dpath3","north",
             "players/persephone/rooms/junpatb","east",
  });
}
