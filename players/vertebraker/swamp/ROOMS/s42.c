#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"    Masses of tangled vines and the remnants of an old stone wall stop\n"+
"you from leaving south or west, and the less-trodden path wraps to the\n"+
"northeast and east.  Fear creeps back up your spine, as though you\n"+
"should get out of here fast.\n");
   add_item("masses","Askew masses of vines lie on top of a wall,\ncovering its rugged surface");
   add_item("wall","Remnants of an ancient stone wall stand here,\nas though something was once here");
   add_item("remnants","Remnants of an ancient stone wall stand here,\nas though something was once here");
   add_item("vines","Large green vines");
   add_item("path","The path wraps northeast and east");
   add_touch("wall","The wall feels grimy and cold.");
   add_exit(ROOMS+"s9","northeast");
   add_exit(ROOMS+"s43","east");
}
