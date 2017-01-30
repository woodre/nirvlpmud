#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Paranoia creeps along your spine as you descend deeper and deeper\n"+
"into the murky green depths.  You can feel a slime crawling along your\n"+
"legs as you trod through the muck, which is especially deep here.  A\n"+
"billow of smoke can be seen faintly to the south.\n");
   add_item("slime","Protoplasmic goo that somehow has discovered the ability\nto crawl, making it quite weird");
   add_item("billow","You can see smoke in the south horizon");
   add_item("smoke","You can see smoke in the south horizon");
   add_touch("slime","...slimy...");
   add_smell("main","Amidst the pungent odor of the swamp waters, you detect\nthe smoke that you see spiraling to the south.");
   add_exit(ROOMS+"s25","west");
   add_exit(ROOMS+"s28","east");
}
