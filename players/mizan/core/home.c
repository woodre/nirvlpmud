inherit "/room/room.c";

void reset(int arg)
{
   if(arg) return;
   set_light(1);

   short_desc = "02h Nexus";
   long_desc =
   "    You are standing in the Operational Nexus of 02h. Power punches and\n"+
   "  the humming of machines drowns the room, which seemingly extends to an\n"+
   "  infinite expanse. The gleaming, crystalline floors are warm to the touch\n"+
   "  and almost emit a pulsating feeling with you could swear to feeling.\n"+
   "  A spiral staircase on one side of the Nexus leads downstairs to the\n"+
   "  Proving Grounds control area. To the east is the laboratory access\n"+
   "  junction.\n";

  items = ({
    "machines",
    "There are machines everywhere in this room. They vaguely remind you of\n"+
    "some kind of server room.",

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",
  });

  dest_dir = ({
    "/players/mizan/workroom.c", "out",
    "/players/mizan/core/02h/room01.c", "north",
    "/players/mizan/core/02h/room15.c", "south",
    "/players/mizan/core/02h/room11.c", "east",
    "/players/mizan/core/02h/room05.c", "down",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

