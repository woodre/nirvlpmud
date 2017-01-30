inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - Matsuura Cybernetica";
   long_desc =
   "    A quiet but steady hum of machines combined with the gleaming racks\n"+
   "  of slightly more sinister looking hardware make you feel somewhat\n"+
   "  uneasy, but the absolute lack of any frivolous blinkenlights is what\n"+
   "  really does it. There is feeling of great singular energy here, as if\n"+
   "  the hardware here is on a mission and will simply not relent.\n"+
   "  Unlike France, surrender is not an option.\n";
   
  items = ({
    "machines",
    "There are machines everywhere in this room. They vaguely remind you of\n"+
    "some kind of server room.",

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",
   });
     
  dest_dir = 
  ({
    "/players/mizan/core/home.c", "north",
    "/players/mizan/core/02h/room16.c", "south",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

