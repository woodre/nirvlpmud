inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - Lab Junction";
   long_desc =
   "    You are standing in an access junction to the 02h Nexus laboratories.\n"+
   "  To proceed, you must have proper access credentials. To the west is the \n"+
   "  Operational Nexus. The way down into the laboratories looks very brightly\n"+
   "  lit and a way very foreboding and terrifying.\n";
   
  items = ({

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/home.c", "west",
    "/players/mizan/core/02h/room12.c", "down",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

