#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Within your sense of dread, you turn in every which way,\n"+
"desperately searching for a way out.  You can see a wisp of smoke \n"+
"emerging far from the southeast, but you are not sure of the exact\n"+
"location.  The croaking of frogs and chittering of insects can be\n"
+"heard in the twilight.\n");
   add_exit(ROOMS+"s25","north");
   add_exit(ROOMS+"s24","south");
   add_exit(ROOMS+"s7","southeast");
   add_item(({"wisp","smoke"}),"The wisp of smoke is coming from the\n"+
      " far southeast");
   add_listen("main","You hear the croaking of frogs and the chittering of insects.");
   add_listen("croaking","..ribbit.  riiiibit.");
   add_listen("frogs","..ribbit.  riiiibit.");
   add_listen("chittering","*chhh* *whzzzzh*");
   add_listen("insects","*chhh* *whzzzzh*");
}
