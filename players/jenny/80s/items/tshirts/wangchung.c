#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
    if(arg) return;
    set_alias("t-shirt");
    set_id("shirt");
set_ac(1);
set_value(40);
set_weight(1);
    set_type("armor");
    set_short("A "+RED+"Wang Chung "+NORM+"shirt");

    set_long(
      "A white t-shirt with "+RED+"Wang Chung "+NORM+"written on\n"+
      "the front.\n");
}
