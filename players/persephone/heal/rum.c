inherit "obj/alco_drink";
#include "/players/persephone/rooms.h"
reset(arg){
    ::reset(arg);
    if (arg) return;
        set_name("inner circle rum");
        set_alt_name("rum");
        set_alias("flask");
        set_short("A Flask of Inner Circle Rum");
        set_long("A flask of dark island rum that appears to be 80%\n" +
                    "alcohol volume and would kick like a mule\n");
        set_weight(1);
        set_strength(49);
        set_drinker_mess("The Rum Burns as it slides down your throat\n");
        set_drinking_mess(" downs the whole flask of Rum like it was water\n");
        set_empty_container("flask");
        set_value(490);
}
