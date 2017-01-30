inherit "obj/weapon.c";
#include <ansi.h>

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("scimitar");
set_short(HIG+"Je"+HIB+"we"+HIR+"ll"+HIM+"ed"+HIW+" Scimitar"+NORM);
set_long(
"  Held by the King of the Green Dragons, this jewelled work\n\
of art is something to behold. It is nearly 4 feet long and\n\
made of pure Platinum. Jewels of numerous types, priceless,\n\
adorn its surface from handle to the crystal orb at its end.\n\
It sparkles with an inner power.\n");
set_type("sword");
set_alias("scimitar_green_dragon");
set_class(14);
set_weight(3);
set_value(150000);
}

/* Added for BF Guild -> Fred 5.25.05 */
query_nonchoose(){ return 1; }
