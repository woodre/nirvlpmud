#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("barbell");
   set_short("A heavy barbell");
   set_long(
      "A metal barbell used by Hefty Smurf to keep his strength \n"+
      "at its top level.  It is something that you don't want\n"+
      "to carry around for a long time.\n");
   set_weight(2);
   set_value(125);
}
