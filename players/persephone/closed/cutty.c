inherit "/obj/weapon.c";
#include "/players/persephone/rooms.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_id("drake's Cutlass");
    set_name("cutlass");
    set_short("Ornate Cutlass");
    set_long("An ornate and intricate cutlass with the family coat\n"+
             "of arms of Sir Francis Drake.  It does not look like a \n" +
             "great weapon rather it looks useable at best\n" +
             "for show\n");
    set_class(16);
    set_weight(1);
    set_value(2000);
    set_hit_func(TOB);
    set_save_flag(0);
}

