#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A village pathway");
   set_long(
"     A dusty straw hut stands tall to the north and the path wraps\n"+
"southeast, in which you can see the beginning of a massive swamp.\n"+
"A few guards wander by, looking for something, and scouring the area.\n");
   add_item("hut","A dusty straw hut stands to the north,\n"+
      " and the door is wide open");
   add_item("swamp","The strange swamp lies perilously further southeast\n"+
      " and you get a feeling of dread");
   add_item("guards","They appear to be looking for something");
   add_exit(VILLAGE+"path4","west");
   add_exit(VILLAGE+"shut","north");
   add_exit(VILLAGE+"path6","southeast");
}
