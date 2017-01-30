inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Entrance to The Caverns Of Stupidity";

   long_desc =
   "    This is the bottom of a steep shaft in the caverns. The way up seems to\n"+
   "  lead to the outside. The way north seems to lead further into the caverns.\n"+
   "  The stench of sulphur and rotting corpses is getting stronger by the minute.\n"+
   "  You really don't know if there is much profit to be had in venturing\n"+
   "  deeper into this vile sphincter of filth.\n";
   
  items = ({

    "walls",
    "The wall appears to be covered in pig vomit and dried blood.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/beating_council/ROOMS/hell.c", "north",
    "/players/mizan/etheriel/ROOMS/bog.c", "out",
  });
}

