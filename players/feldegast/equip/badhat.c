#include "/players/feldegast/defines.h"
inherit "obj/armor";

reset(arg) {
  set_name("hat");
  set_short("A "+HIM+"p"+HIG+"l"+HIR+"u"+HIB+
            "m"+HIM+"e"+HIG+"d"+NORM+" hat");
  set_long(
    "This large hat was most likely made by a seriously\n"+
    "disturbed individual.  Bright multicolored feathers\n"+
    "top an otherwise quite fashionable headpiece.\n"
  );
  set_type("helmet");
  set_ac(1);
}

do_special(owner) {
  tell_room(environment(owner),TPN+" puts a dent in "+owner->query_name()+"'s "+short_desc+".\n");
  return 1;
}
