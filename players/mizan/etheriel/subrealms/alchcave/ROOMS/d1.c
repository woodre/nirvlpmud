inherit "/room/room.c";

void reset(int arg) 
{
   call_other("players/mizan/etheriel/subrealms/alchcave/ROOMS/d14.c","???");
   if(arg) return;
   set_light(1);
   
   short_desc = "The Caverns Of Stupidity";

   long_desc =
   "    This is the bottom of a steep shaft in the caverns. The way up seems to\n"+
   "  lead to the outside. The way south seems to lead further into the caverns.\n"+
   "  The stench of sulphur and rotting corpses is getting stronger by the minute.\n"+
   "  You really don't know if there is much profit to be had in venturing\n"+
   "  deeper into this vile sphincter of filth.\n";
   
  items = ({

    "wall",
    "The wall appears to be covered in pig vomit",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/in.c", "up",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d2.c", "south",
  });
}

