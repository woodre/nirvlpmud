#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("corpse pile");
  set_alias("pile");
  set_short(""+RED+"A large corpse pile"+NORM+"");
set_long(
"This is a very large pile of human corpses.  The corpses have been dragged\n"+
"into here by the worker ants.  They put all the bloody corpses into a pile\n"+
"to make it easier to dismember them, and make them into food for the queen\n");
  set_value(0);
  set_weight(140);
}
