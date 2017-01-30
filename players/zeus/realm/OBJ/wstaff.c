inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("staff");
  set_short("A wooden staff");
  set_long(
"This is a wooden oak staff, about five feet long.  At the top of the\n"+
"staff the wood is twisted around a small black jewel.  There is an\n"+
"engraving just below the black jewel.\n");
  set_value(700);
  set_weight(1);
  set_class(12);
  set_read("The engraving reads:  Yjod erp divld\n");
}
