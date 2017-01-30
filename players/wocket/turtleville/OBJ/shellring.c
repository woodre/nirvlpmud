#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(){
    set_id("ring");
    set_alias("shellring");
    set_type("ring");
    set_short(GRN+"A shellring"+NORM);
    set_long("A very protective ring made from a turtle's shell.\n");
    set_ac(1);
    set_weight(1);
    set_value(860+random(15));
}
