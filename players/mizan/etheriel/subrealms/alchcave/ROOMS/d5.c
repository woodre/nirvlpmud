inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Caverns Of Stupidity - Hallway";

   long_desc =
   "    This appears to be part of a long hallway that leads through the caverns.\n"+
   "  Bodily noises of some sort can be heard coming from the area to the west.\n"+
   "  You are forced to cover your nose with your hand at this point from the\n"+
   "  smell. Strange markings and paintings were hastily scribbled into the rock\n"+
   "  face. You are really begining to wonder what could possibly smell so bad.\n";
   
  items = ({

    "wall",
    "The wall appears to be covered in pig vomit",

    "markings",
    "A lot of the markings are repetitive. They read:\n"+
    "'SCARTHE == 31337 HAXX0R'",
    
    "paintings",
    "On the wall appears to be a crude painting of something that that looks like a\n"+
    "water buffalo with what appears to be a canoe stuck in its rear end\n\nAbsolutely fascinating",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d2.c", "north",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d7.c", "south",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d6.c", "west",
  });
}

