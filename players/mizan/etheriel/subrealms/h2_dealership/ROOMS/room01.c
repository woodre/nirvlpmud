inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Corner of Vine and Catalina";
   long_desc =
   "    You blink. You are somewhere familiar yet completely unplaceable.\n"+
   "  A street sign here says Catalina and Vine streets. The bright sunlight\n"+
   "  and warm breeze are quite an experience to get used to again, afer being\n"+
   "  in the Plane of Etheriel for so long.\n";
   
  items = ({
    "sign",
    "One of the dark green signs says Catalina Blvd. The other says Vine St.",

    "sun",
    "Bright, a'int it!",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/h2_dealership/ROOMS/room01.c", "east",
    "/players/mizan/etheriel/ROOMS/buildo.c", "out",
  });
}

