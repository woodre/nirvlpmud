inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus West";
   long_desc =
   "    This is the communications tap grid of the Operational Nexus.\n"+
   "  A high density array of monitoring devices report the status of\n"+
   "  various events that can be heard or seen in the production matrix.\n"+
   "  You are somewhat in awe of the sheer amount of bandwidth that must\n"+
   "  flow through this side of the room.\n";
   
  items = ({
    "machines",
    "There are machines everywhere in this room. They vaguely remind you of\n"+
    "some kind of server room.",

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room01.c", "east",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

