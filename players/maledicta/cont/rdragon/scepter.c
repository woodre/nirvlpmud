#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("scepter");
set_short(HIG+"Je"+HIB+"we"+HIR+"ll"+HIM+"ed"+HIW+" Scepter"+NORM);
set_long(
"  Held by the King of the Red Dragons, this jewelled work\n"+
"of art is something to behold. It is nearly 2 feet long and\n"+
"made of pure gold. Jewels of numerous types, priceless, adorn\n"+
"its surface from handle to the crystal orb at its end. It\n"+
"sparkles with an inner power.\n");
set_type("club");
set_alias("scepter_red_dragon");
set_class(12);
set_weight(3);
set_value(150000);
}


/* Added for BF Guild -> Fred 5.25.05 */
query_nonchoose(){ return 1; }
