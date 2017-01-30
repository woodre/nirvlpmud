#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shield");
  set_short(HIW+"Silver"+BLK+" shield"+NORM);
  set_long(
    "This is a strong steel shield with silver trimming and the symbol\n"+
    "of a griffin in silhouette on its face.\n"
  );
  set_weight(3);
  set_ac(1);
  set_type("shield");
  set_value(1000);
}

do_special(owner) {
  if(!random(10))
  {
    tell_object(owner, "You manage to partially deflect the blow with your shield.\n");
    return 1;
  }
}



