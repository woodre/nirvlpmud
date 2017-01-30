#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(){
    set_id("shield");
    set_alias("shellshield");
    set_type("shield");
    set_short(GRN+"A shellshield"+NORM);
    set_long("A very protective shield made from a turtle's shell.\n");
    set_ac(1);
    set_weight(1);
    set_value(885+random(15));
}
