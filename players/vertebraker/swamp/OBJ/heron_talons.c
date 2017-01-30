#include "../define.h"
inherit WEAPON;
reset(arg) {
   if(arg) return;
   set_name("talons");
   set_alias("heron talons");
   set_short("A pair of heron talons");
   set_long(
      "These are small, three-inch talons that can be 'wield'ed\n"+
      "like any other weapon.  They probably won't protect you much\n"+
      "in battle however.\n");
   set_class(10);
   set_value(300);
   set_type("knife");
}
