#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(){
    set_id("boots");
    set_alias("shellboots");
    set_type("boots");
    set_short(GRN+"A pair of shellboots"+NORM);
    set_long("A very protective pair of boots made from the shells of turtles.\n");
    set_ac(1);
    set_weight(1);
    set_value(870+random(15));
}
