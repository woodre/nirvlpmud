#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
    if(arg) return;
    set_name("designer jeans");
    set_id("jeans");
    set_alias("pants");
set_ac(1);
set_weight(2);
set_value(1100);
    set_type("pants");
    set_short(""+BLU+"Designer jeans"+NORM+"");

    set_long(
      "These are a very nice pair of designer jeans worn by Jefferson D'Arcy.\n"+
      "They are light blue, and tight fitting.  Notice the fancy stitching.\n"+
      "Jefferson probably bought these on Marcy's credit card \n");
}
