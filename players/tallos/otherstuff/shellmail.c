#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(){
    set_id("armor");
    set_alias("shellmail");
    set_type("armor");
    set_short(GRN+"A suit of shellmail"+NORM);
    set_long("A suit of very protective shellmail made from the shells of turtles.\n");
    set_ac(4);
    set_params("magical",4,0,0);
    set_params("other|water",0,15,0);
    set_weight(3);
    set_value(2600+random(15));
}
