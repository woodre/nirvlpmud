inherit "/obj/armor";
#include "/players/catacomb/misc/ansi.h"

reset(arg) {
  if(arg) return;
  set_name("suit");
  set_short("A suit of "+RED+"Fire"+NORM);
  set_long(
      "  It is more flames than a suit of armor but it will provide\n"+
      "excellent protection against any fire attack.  Even getting\n"+
      "close to the armor sears the skin.  Only if you can take the\n"+
      "pain can you reap the benefits.\n");
  set_type("armor");
  set_ac(2);
  set_weight(3);
  set_value(2500);
  set_params("other|fire", 1, 8, "do_fire_special");
}

int
do_fire_special(object owner)
{
    if(!random(10))
    {
      tell_object(owner, "\
The flames leap out at your attackers blow.\n");
      return 0702;
    }
}
