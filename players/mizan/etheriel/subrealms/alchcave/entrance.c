inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Smoky Cavern";
   long_desc =
   "    You are standing at the opening of a deep cavern. It is a horrible and\n"+
   "  wretched maw in the ground, that smells like sulphur and rotting flesh.\n"+
   "  There is also a great deal of smoke coming from further within, and\n"+
   "  strange cracks of all sorts line the walls within the cave.\n";
   
  items = ({
    "cracks",
    "Upon closer inspection you realize that some of the cracks are large\n"+
    "enough for someone to 'slip' through",

    "smoke",
    "The smoke appears to be very dusty... Someone down there somewhere is\n"+
    "brewing some sort of trouble. Burning corpses into ashes perhaps..",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/in.c", "down",
    "/players/mizan/etheriel/ROOMS/niall.c", "out",
  });
}

init()
{
   ::init();
   add_action("slip","slip");
}

slip()
{
   write("You slip through a crack in the wall and emerge somewhere else...\n");
   this_player()->move_player("through a crack in the wall#/players/mizan/etheriel/subrealms/alchcave/ROOMS/richard.c");
   return 1;
}
