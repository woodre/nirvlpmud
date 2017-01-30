#include "/players/jaraxle/ansi.h"

inherit "obj/weapon.c";







reset(arg){

  ::reset(arg);

  if (arg) return;

set_name("dagger");

set_short(HIG+"Je"+HIB+"we"+HIR+"ll"+HIM+"ed"+HIW+" Dagger"+NORM);

set_long(

"  Held by the King of the Blue Dragons, this jewelled work\n"+

"of art is something to behold. It is barely 1 foot long and\n"+

"made of pure silver. Jewels of numerous types, priceless, adorn\n"+

"its surface from handle to the crystal orb at its end. It\n"+

"sparkles with an inner power.\n");

set_type("knife");

set_alias("dagger_blue_dragon");

set_class(12);

set_weight(1);

set_save_flag(1);

set_value(150000);

}


/* Added for BF Guild -> Fred 5.25.05 */

query_nonchoose(){ return 1; }


