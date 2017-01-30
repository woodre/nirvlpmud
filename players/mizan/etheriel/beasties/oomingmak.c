inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/NewbieGuard.c"
#include "/players/bastion/closed/color.h"

reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("oomingmak");
    set_race("oomingmak");
    set_alias("bubbling");
    set_short(BLUE+"A bubbling Oomingmak"+OFF);
    set_long("Whatever this is before you is made almost entirely of a blue\n"+
    "liquid, shapeshifting and eerily silent before you.\n");

    set_level(18);
    set_hp(450);
    set_al(670);
    set_ac(26);
    set_wc(15);

    weapon=clone_object("players/mizan/etheriel/items/trick-brick");
    move_object(weapon, this_object());
    move_object(clone_object("players/mizan/etheriel/heals/pickles"), this_object());
}

