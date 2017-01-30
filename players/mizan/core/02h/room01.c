inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus North";
   long_desc =
   "    You are standing in the northern side of the Operational Nexus.\n"+
   "  There are more machines here, but they are smaller in size, and seem\n"+
   "  to be running much quieter. Unlike other parts of the Nexus, some\n"+
   "  chattering noises which seem to be verbal communications can vaguely\n"+
   "  be heard. It appears to be coming strongest from the west.\n";
   
  items = ({
    "machines",
    "There are machines everywhere in this room. They vaguely remind you of\n"+
    "some kind of server room.",

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room02.c", "west",
    "/players/mizan/core/02h/room03.c", "east",
    "/players/mizan/core/home.c", "south",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

