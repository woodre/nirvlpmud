inherit "/obj/weapon.c";
#include "/players/persephone/rooms.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_id("uzzi");
    set_name("pistol");
    set_short("A Dueling Pistol");
    set_long("A dueling pistol of ancient make.  The barrel looks\n"+
             "so worn you think it would no longer be accurate at\n" +
             "distances more than three feet\n");
    set_class(18);
    set_weight(3);
    set_value(3000);
    set_hit_func(TOB);
    set_save_flag(0);
}

