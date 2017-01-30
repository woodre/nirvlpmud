#include "../../define.h"
#define PATH "/players/vertebraker/castle/new/"
int m;
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A darkened forest");
   set_long(
      "    The forest has become much darker here, the twilight moon beaming\n"+
      "down has become much less powerful.  A pool of brown mud cakes the\n"+
      "area to the left of you, and you narrowly evade stepping into it.\n"+
      "Small pine cones have fallen on the path, providing an addition to\n"+
      "the strange, rustic beauty here.\n");
   add_item(({"cones","pine cones"}),
      "Small brown pine cones have fallen onto the path here");
   add_item("path",
      "The shady \"path\" continues to the north and south directions");
   add_item("moon",
      "Strangely, the moonbeams have dimmed a bit here in this part of the forest,\n"+
      "as though the area doesn't \"deserve\" the moon's cool light");
   add_exit(PATH+"n1","north");
   add_exit(PATH+"vortex","south");
}

id(str) {
   if(str == "mud" || str == "pool") {
      if(!m)
         write("You gaze at the muddy pool, and see something glinting through\n"+
         "the sloshy brown muck.   Maybe it deserves a closer investigation?\n");
      else write(
            "You gaze at the muddy pool, and don't see anything within its shallow depths.\n");
      return 1; }
   else return ::id(str); }
cmd_search(str) {
   if(str == "mud" || str == "pool") {
      if(!m) {
         write("You drag your hand through the shallow depths of the brown muck,\n"+
            "and retrieve a small silver pin.\n");
         MO(CO(PATH+"pin"),TP);
         m = 1;
         return 1; }
      write("You drag your hand through the shallow depths, and find nothing.\n");
      return 1; } ::cmd_search(str); return 1; }
