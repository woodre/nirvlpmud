inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Inside a GIANT pile of socks";
   long_desc =
   "    You are inside a cramped pocket underneath the rest of the chamber.\n"+
   "  The 'ground' seems to be more dense here, but its filth also makes it more\n"+
   "  foreboding. A strange whiff of motor oil permeates the air here, including\n"+
   "  the same old nasty sock stench.\n";
   
  items = ({
    "ground",
    "The ground is soft and squishy. It is all made of LEFT socks.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/sockworld/ROOMS/room05.c", "up",
  });
}
