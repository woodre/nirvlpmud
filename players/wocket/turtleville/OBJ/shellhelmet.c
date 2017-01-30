#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(){
    set_id("helmet");
    set_alias("shellhelmet");
    set_short(GRN+"A shellhelmet"+NORM);
    set_long("A very protective helmet made from a turtle's shell.\n");
    set_ac(1);
    set_weight(1);
    set_value(875+random(15));
    set_type("helmet");
}
