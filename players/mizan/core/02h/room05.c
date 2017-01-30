inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - PG Control Room";
   long_desc =
   "    At the bottom of what seemed like a fairly long descent is the control\n"+
   "  facility for the Proving Grounds within the Operational Nexus. From here\n"+
   "  you are able to test combat with a variety of monsters in combat.\n"+
   "  To the north is the isolation chamber proving ground. To the east is\n"+
   "  a hallway leading to individual riot rooms. The cafe area is to the west.\n";   
  
   items = ({

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/home.c", "up",
    "/players/mizan/core/02h/room06.c", "north",
    "/players/mizan/core/02h/room07.c", "west",
    "/players/mizan/core/02h/room09.c", "east",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

