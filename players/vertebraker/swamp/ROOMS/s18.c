#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Hacking and slashing thus far through the swamp has served you\n"+
"well, but the only thing you have achieved is a sense of utter\n"+
"bewilderment.  Vines hang around your head and something zips by your\n"+
"leg in the waters as you trudge deeper and deeper into the wetlands.\n");
   add_item("vines","Vines and trees line along all sides of you,\nin some places too deep to pass by");
   add_item("something","A passing fish of some kind");
   add_item("waters","Dark, green, and murky.\nYou can't see the bottom");
   add_exit(ROOMS+"s10","northwest");
   add_exit(ROOMS+"s16","south");
}
