inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus East";
   long_desc =
   "    You stand in a quieter section of the Operational Nexus. Before\n"+
   "  you are a large array of what appear to be power cables and punches.\n"+
   "  Gleaming, hard plastic-like material forms a barrier between you and.\n"+
   "  certain death if you were to touch the exposed connections at the\n"+
   "  termination junctions. Further east is a different part of the Nexus,\n"+
   "  as it seems to be bathed in a soft orange light instead of the crystal\n"+
   "  bright white lamprails that envelope the rest of the area. To the\n"+
   "  north is a sign proclaiming the Ops center for the Monster's Guild.\n";
   
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
    "/players/mizan/core/02h/room01.c", "west",
    "/players/mizan/core/02h/room04.c", "east",
    "/players/mizan/core/02h/room08.c", "north",
  });

  set_no_clean(1);
}

init()
{
   ::init();
  if(this_player() && this_player()->query_level() < 20)
    {
      this_player()->hit_player(5000000);
    }
}

