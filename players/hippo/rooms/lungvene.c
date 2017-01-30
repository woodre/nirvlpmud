#include "/players/hippo/bs.h"
inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "The lung vene.";
   long_desc = "This is the only vein in a man that contains fresh blood with oxygen."+BS;
   set_light(1);
   dest_dir = 
({
      "/players/hippo/rooms/latrium","up",
      "/players/hippo/rooms/lung","south",
   });
}
