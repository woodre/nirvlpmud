#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor.c";

reset(){
    set_id("sash");
    set_alias("shellsash");
    set_type("misc");
    set_short(GRN+"A shellsash"+NORM);
    set_long("This is a very protective sash decorated with the shells of turtles.\n");
    set_ac(1);
    set_weight(1);
    set_value(870+random(15));
}
