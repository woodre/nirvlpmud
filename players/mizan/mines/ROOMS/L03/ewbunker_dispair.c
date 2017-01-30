inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The End of the Dirt-Walled Earwaxian Superbunker";
   long_desc = "Man this shit is MAD GHETTO.\n";
   
  items = ({

    "floor",
    "The floor is dirt that has been stained with fecal matter, urine, and blood.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/L03/ewbunker_corridor.c","up",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

