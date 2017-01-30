inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - Monsters' Guild";
   long_desc =
   "    This is a brightly lit area in the Operational Nexus. Devices sit\n"+
   "  here in a neatly packed cluster in the center of the room. Additional\n"+
   "  power punches can be seen in a lineup servicing these devices.\n"+
   "  Yes, all of the equipment used for operating the Monsters' guild\n"+
   "  lives here. You notice that things are very clean around here, despite\n"+
   "  the added activity caused by all the monsters. There is a shimmering\n"+
   "  portal leading down, presumably to the locker rooms of the Monster's\n"+
   "  Guild. In addition, there is a portal north to the staging area of the\n"+
   "  next generation series.\n";
   
  items = ({
    "machines",
    "There are machines everywhere in this room. They vaguely remind you of\n"+
    "some kind of server room.",

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

    "cables",
    "Large, foot-diameter cables made of a dull gray material snake below your feet.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room03.c", "south",
    "/players/mizan/core/02h/room14.c", "north",
    "/players/mizan/mbv2/ROOMS/locker01.c", "down",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

