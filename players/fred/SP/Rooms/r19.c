#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short("South Park");
   set_long(
      "  There is even more junk strewn around the area here.  A rusted gate\n"+
      "is hanging by only one hinge and the large sign above it looks like it\n"+
      "could fall down at any time.  Some people are roaming around on the\n"+
      "other side of the gate.\n");

   add_item("junk","Empty cigarette packs, beer bottles, and shot gun shells....hrmm");
   add_item("gate","An old rod iron gate");
   add_item("sign","The sign reads:\n\n"+
                   "Welcome to South Park's Trailer Court!!\n");
   add_item("people","You see a skinny guy in a stained white tank top working on\n"+
                     "an old truck and several women chasing after little kids.");
   add_smell("main","You take a deep breath and start to cough.....");
   add_listen("main","You hear a loud gunshot followed by someone yelling, \"Woooo eeee!!!!\".");
   add_exit("/players/fred/SP/Rooms/r18.c","south");
   add_exit("/players/fred/SP/Rooms/r20.c","north");
}
