inherit "/obj/armor";
#include "/players/catacomb/misc/ansi.h"

reset(arg) {
  if(arg) return;
  set_name("ring");
  set_short("A dark"+BLU+" blue"+NORM+" ring.");
  set_long(
   "  The ring has a deep "+BLU+"blue"+NORM+" sapphire set into it.\n"+
   "The ring gives off an aura of some kind giving\n"+
   "the wearer a sense of calm.\n");
  set_type("ring");
  set_ac(1);
  set_params("other|mental",1,10,"do_mental");
  set_weight(1);
  set_value(1000);
}
do_mental()
{
 if (random(10)>8)
 {
  tell_object(this_player(),
	"\nThe ring glows a "+BLU+"bright blue"+NORM+".\n\n");
  return 0300;
 }
}
