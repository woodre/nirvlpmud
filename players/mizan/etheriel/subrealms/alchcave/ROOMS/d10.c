inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Caverns Of Stupidity - Hallway";

   long_desc =
   "    You are at the end of a long hallway in the caverns. Three numbered doors\n"+
   "  to the south appear to be offices of some sort. The stench is so bad now that\n"+
   "  you have a headache. Your face burns not from the heat but from the acrid\n"+
   "  acid in the air that seems to be a  mixture of boiling sweat and fecal matter.\n";
   
  items = ({

    "wall",
    "The wall appears to be covered in pig vomit",

    "markings",
    "A lot of the markings are repetitive. They read:\n"+
    "'BITTER 0WNZ J00!'\n'SCARTHE lol BUTHAXX0R!'",
    
    "paintings",
    "On the wall appears to be a crude painting of something that that looks like a\n"+
    "man spreading his rear end. This is truly horrid stuff",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d7.c", "north",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d13.c", "southeast",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d12.c", "south",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d11.c", "southwest",
  });
}

