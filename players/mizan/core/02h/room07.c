inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - Astraparna";
   long_desc =
   "    There is a lack of machines in this area and consequently it's very\n"+
   "  quiet and relaxing. There are beanbags scattered around one side of the\n"+
   "  floor. A cool breeze minus the hum of air conditioners, and some low-fi\n"+
   "  is playing in the background.\n";   
  
   items = ({

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room05.c", "east",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

