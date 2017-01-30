inherit "/obj/weapon.c";
#include "/players/persephone/rooms.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_id("whip");
    set_name("whip");
    set_short("Cat O'nine Tails");
    set_long("A cool looking whip with nine lashes hence its name.\n"+
             "While it looks impressive you feel that it is not all\n" +
             "that useful as a weapon and that it is more intended \n" +
             "for show\n");
    set_class(14);
    set_weight(1);
    set_value(2000);
    set_hit_func(TOB);
    set_save_flag(0);
}

