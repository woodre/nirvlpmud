inherit "/players/mizan/core/monster.c";
#include "/players/bastion/closed/color.h"
#include "/players/mizan/closed/NewbieGuard.c"

reset(arg) 
{
    object weapon,treasure,coins;
    ::reset(arg);
    if(arg) return;
    set_name("tacoban");
    set_race("tacoban");
    set_short(BLINK + YELLOW + "Tacoban" + OFF);
    set_long("This thing looks like one GIANT gold coin... it is one of\n"+
    "the few 'organisms' here that is nearly solid and physically\n"+
    "consistent. That makes it easier to deal with. Those same \n"+
    "attributes also make it considerably harder to kill.\n");
    set_level(20);
    set_hp(1000);
    set_al(0);
    set_ac(30);
    set_wc(20);
    set_chance(15);
    set_spell_dam(35);
    set_spell_mess1("Tacoban drifts by and smashes you on the head!");
    set_spell_mess2("Tacoban smacks you with a solid 'KLUNG!'");
    set_chat_chance(6);
    load_chat("Tacoban flips around.\n");
    load_chat("Tacoban fades from view for a split-second.\n");
}

