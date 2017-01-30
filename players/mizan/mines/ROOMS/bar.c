inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Piss Factory";
   long_desc =
   "   Right now there is nothing here yet. Sorry it sucks.\n";
   
  items = ({

    "floor",
    "The floor appears to be made of some fairly high quality bathroom tile.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/lounge.c", "south",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

