#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("a path");
   set_long("   As you walk along the path, you notice it appears well traveled by wagon\n"+
   "tracks.  You notice a sign hung upon one of the trunks of the trees off to\n"+
   "the left.\n"+
   "   The path widens to the south, leading straight into the village proper.");
   add_item("sign", "The sign appears to be made of very dark oak.  Upon its surface are some\nsymbols.  Perhaps you should read it");
   add_item("village", "The village appears to be quite active.  You can see the villagers moving in\nand out of the shops lining the main road");
   add_exit(ROOM_DIR+"forest_reentry", "north");
   add_exit(ROOM_DIR+"niurin/main1",  "south");
}

init() {
   ::init();
   add_action("read", "read");
}

read(str) {
   if(str!="sign") {
      notify_fail("Read what?\n");
      return 0;
   }
   write("The crudely carved sign reads:\n\n  Niurin\n");
   return 1;
}
