#include "/players/feldegast/defines.h"
inherit "obj/armor";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("amulet");
  set_alias("crystal");
  set_short("A crystal amulet");
  set_long(
    "A delicate crystal amulet.\n"
  );
  set_ac(0);
  set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(15);
  set_params("other|fire",1,0,"fire_special");
}

do_special(owner) {
     tell_object(owner,"Your crystal amulet glows protectively.\n");
    return 10000;
}

fire_special(x) {
   tell_object(x, HIR+"Your crystal amulet glows intensely!\n"+NORM);
    return 0;
}
