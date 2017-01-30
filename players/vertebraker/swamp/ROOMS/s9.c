#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Hacking and slashing thus far through the swamp has served you well,\n"+
"but the only thing you have achieved is a sense of utter bewilderment.\n"+
"Foliage hangs around your head and something zips by your leg in the\n"+
"waters as you trudge deeper and deeper into the wetlands.\n");
   add_item("foliage","Vines and trees line along all sides of you,\nin some places too deep to pass by");
   add_item("something","A passing fish of some kind");
   add_item("waters","Dark, green, and murky.\nYou can't see the bottom");
   add_exit(ROOMS+"s4","northeast");
   add_exit(ROOMS+"s20","north");
   add_exit(ROOMS+"s42","southwest");
}
