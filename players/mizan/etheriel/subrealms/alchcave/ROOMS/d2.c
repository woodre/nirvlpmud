inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Caverns Of Stupidity - Hallway";

   long_desc =
   "    This appears to be part of a long hallway that leads through the caverns.\n"+
   "  Strange chanting can be heard coming from the rooms along the side, and the\n"+
   "  source of the incredibly vile smell appears to be much stronger in these\n"+
   "  parts of the cavern. Strange markings and paintings were hastily scribbled\n"+
   "  into the rock face. Your stomach is beginning to get queasy. Ick.\n";
   
  items = ({

    "wall",
    "The wall appears to be covered in pig vomit",

    "markings",
    "A lot of the markings are repetitive. They read:\n"+
    "'DETH TO @LL DOPPLES! THEY YUO SUXX0R!!'\n"+
    "'SCARTHE IZ DAH BIZNITCH DOOOODE!!'n",

    "paintings",
    "On the wall appears to be a crude painting of a naked man, straddling\n"+
    "what appears to be a sheep or goat of some sort. Disgusting",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d1.c", "north",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d5.c", "south",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d3.c", "east",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d4.c", "west",
  });
}

