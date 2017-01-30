#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("pillow");
   set_short("A fluffy pillow");
   set_long(
      "A fluffy pillow that lazy smurf carries around.  It is very \n"+
      "useful for those moments that you just need to lay your \n"+
      "head down and take a nap.\n");
   set_weight(0);
   set_value(25);
}
