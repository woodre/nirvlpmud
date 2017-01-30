#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
 if (arg) return 0;

 set_light(1);
 short_desc="A dusty road";
 long_desc="    The dusty path does not seem to receive much use and \n"+
           "is slightly overgrown. The sun beats down from overhead  \n"+
           "with what seems to be an almost personal hatred. Framing \n"+
           "the path, the brush appears to have been at one time lush\n"+
           "and healthy, but is now brown and bent. There is a portal\n"+
           "shimmering to one side.\n";
 items=({
   "path",   "The dusty path winds far to the south",
   "sun",    "Large and angry red, the sun beats down upon you fiercely",
   "portal", "Perhaps you should go back now while you have the chance",
   "brush",  "Brown and scrawny, the remains of lush hedge fence",
   "fence",  "A scraggly hedge fence, framing the path",
   });
  dest_dir=({
    "/players/anshar/chamber", "portal",
    FROOM+"path2", "south",
  });
}
