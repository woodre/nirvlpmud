inherit "/obj/treasure";
#include "/players/jareel/define.h"

reset(){
    set_id("ademonhide");
    set_alias("hide");
    set_short(HIK+"A Dark Demon's Hide"+NORM);
    set_long(
    HIK+"A magical skin from a Dark Demon.  Mystical energy resides inside the leathery\n"+
    "skin waiting to be unleashed"+NORM+".\n");
    set_weight(1);
    set_value(random(500));
}

