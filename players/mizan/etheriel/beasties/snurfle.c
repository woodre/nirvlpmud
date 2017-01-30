inherit "/players/mizan/core/monster.c";
#include "/players/bastion/closed/color.h"

reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("snurfle");
    set_race("snurfle");
    set_short(BOLD + RED + "A snurfle" + OFF);
    set_long("You are not really sure what this thing is. It has a spherical\n"+
    "'body', but there are a whole bunch of appendages sticking out of it.\n"+
    "It seems that the tips of these appendages work like eyes, ears, and\n"+
    "nose combined.\n");
    set_level(7);
    set_hp(105);
    set_al(201);
    set_ac(11);
    set_wc(5);
    set_chance(10);
    set_spell_dam(5);
    set_spell_mess1("Snurfle electrozogs you!");
    set_spell_mess2("Snurfle showers you with a wet, gooey, spittle.\n");
    weapon=clone_object("players/mizan/etheriel/heals/zokball");
    move_object(weapon, this_object());
}

