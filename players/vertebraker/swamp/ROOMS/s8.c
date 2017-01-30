#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Within your sense of dread, you turn in every which way,\n"+
"desperately searching for a way out.  You can see a wisp of smoke\n"+
"coming from the northeast, but your passage is blocked in that \n"+
"direction.  The croaking of frogs and chittering of insects can be\n"
+"heard in the twilight.\n");
   add_exit(ROOMS+"s11","east");
   add_exit(ROOMS+"s43","south");
   add_item("wisp","The wisp of smoke is careening from the northwest");
   add_item("smoke","The wisp of smoke is careening from the northwest");
   add_listen("main","You hear the croaking of frogs and the chittering of insects.");
   add_listen("croaking","..ribbit.  riiiibit.");
   add_listen("frogs","..ribbit.  riiiibit.");
   add_listen("chittering","*chhh* *whzzzzh*");
   add_listen("insects","*chhh* *whzzzzh*");
}
