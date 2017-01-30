#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("plate");
  set_alias("breastplate");
  set_short(HIY+"Golden"+BLK+" breastplate"+NORM);
  set_long(
    "This is a piece of finely made armor, suitable for a knight or a\n"+
    "lord.  It consists of a thick plate of steel with gold leaf trim\n"+
    "and a silver griffin in profile on the chest.\n"
  );
  set_weight(8);
  set_ac(4);
  set_type("armor");
  set_value(6000);
}

do_special(owner) {
  if(!random(10)) {
    tell_object(owner,"The blow bounces off of your breastplate.\n");
    return 1;
  }
}

