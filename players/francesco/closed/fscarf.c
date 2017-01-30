
/* useless item, made because she asked to have a reminder of Illarion */
inherit "obj/treasure";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_id("scarf");
  set_short("A dark black scarf");
  set_long("A black, but fuzzy scarf.  It can be used to speak with\n"+
           "Illarion even if he is invisible or bsy, or simply\n"+
           "to check if he is on, with the command: "+BLD("itell(e)")+".\n"+
           "Note: this ability was removed since he went inactive.\n");
  set_value(0);
  set_weight(0);
}
init() {
  ::init();
}


