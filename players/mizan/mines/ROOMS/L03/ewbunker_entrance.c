inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Entrance to the Dirt-Walled Earwaxian Superbunker";
   long_desc = 
"    Before you is a giant mess. Garbage from fast food wrappers and empty\n"+
"  discount liquor bottles are strewn all over what appears to be a hastily\n"+
"  dug entrance for a series of tunnels that extend further below. There\n"+
"  seems to have been a cave-in here recently, which explains the roughly\n"+
"  hewn nature of this tunnel area.\n";
   
  
  dest_dir = 
  ({
/*    "/players/mizan/mines/ROOMS/L03/ewbunker_corridor.c","west",*/
  });

  call_other("/players/mizan/mines/grids/L03_superbunker.c","???");
  set_no_clean(1);
}

init()
{
   ::init();
}

