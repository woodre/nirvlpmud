inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Inside a GIANT pile of socks";
   long_desc =
   "    You are inside a gigantic pile of socks. Strangely enough, there is a\n"+
   "  hollow chamber here, and it really is quite spacious. The only thing\n"+
   "  that is really annoying is the smell. It is almost unbearable. You are\n"+
   "  not quite sure if its a terribly good idea to stay here for a very\n"+
   "  prolonged period.\n";
   
  items = ({
    "ground",
    "The ground is soft and squishy. It is all made of LEFT socks.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/sockworld/ROOMS/room01.c", "north",
    "/players/mizan/etheriel/ROOMS/athol.c", "out",
  });
}
