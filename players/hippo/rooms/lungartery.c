#include "/players/hippo/bs.h"
inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "The lung artery.";
long_desc="This is the main vessel to the lungs. A lot of unoxigenized blood is here.\n";
   set_light(1);
   dest_dir = 
({
      "/players/hippo/rooms/rventr","up",
      "/players/hippo/rooms/lung","east",
   });
}
