inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Inner Sanctum - Locker Room Entrance";
   long_desc =
   " This is the entrance to the various locker rooms available to the Guild.\n"+
   " The male entrance is to the east, female to the south, and creature to the\n"+
   " west. The hall back to the prep room is to the north.\n";
   
  items = ({

    "floor",
    "The floor appears to be made of some fairly high quality bathroom tile.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mbv2/ROOMS/locker01.c", "west",
    "/players/mizan/mbv2/ROOMS/locker01.c", "east",
    "/players/mizan/mbv2/ROOMS/locker01.c", "south",
    "/players/mizan/mbv2/ROOMS/locker01.c", "north",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

