#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("flesh");
  set_alias("hunk");
  set_short("hunk of "+RED+"flesh"+NORM+"");
set_long(
"A hunk of "+RED+"flesh"+NORM+".  It is red and bloody.  It was taken from\n"+
"a person while fighting an ant.\n");
  set_value(0); /* verte */
  set_weight(1);
}
init () {
   ::init() ;
     }
