#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(){
    set_id("amulet");
    set_alias("shellamulet");
    set_type("amulet");
    set_short(GRN+"A shellamulet"+NORM);
    set_long("A very decorative amulet made from a turtle's shell.\n");
    set_ac(1);
    set_weight(1);
    set_value(865+random(15));
}
