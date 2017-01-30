inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Corridor in the Dirt-Walled Earwaxian Superbunker";
   long_desc = 
  "    This appears to be a hastily dug out corridor, but the floor looks\n"+
  "  to be very well worn. Sheep are probably not best optimized for digging\n"+
  "  burrows, but they have somehow managed to do it in this case.\n"+
  "  It seems that this corridor might be near the end of the line, and you\n"+
  "  sense that Earwax's actual command bunker might be very close by.\n"+
  "  Tattered charts cling to the moist, dirt walls, and stray radio traffic\n"+
  "  can still be heard, heralding your arrival into this truly rotten and\n"+
  "  dingy little area.\n";
   
  items = ({

    "floor",
    "The floor is dirt that has been stained with fecal matter, urine, and blood.",

  });
  
  dest_dir = 
  ({
/*    "/players/mizan/mines/ROOMS/L03/ewbunker_entrance.c","east", */
    "/players/mizan/mines/ROOMS/L03/ewbunker_dispair.c","down",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

