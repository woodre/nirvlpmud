inherit "/players/mizan/core/monster.c";
#include "/players/bastion/closed/color.h"

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
    set_hp(300+random(80));
    set_al(0);
    set_ac(17);

    /* added this... after realizing how much of a cash cow this is. evil :) */
    if(1 == random(12))
      set_wc(96 + random(50));
    else
     set_wc(30);

    set_chance(15);
    set_spell_dam(35);
    set_spell_mess1("Tacoban drifts by and smashes you on the head!");
    set_spell_mess2("Tacoban smacks you with a solid 'KLUNG!'");
    set_chat_chance(6);
    load_chat("Tacoban flips around.\n");
    load_chat("Tacoban fades from view for a split-second.\n");
    coins=clone_object("obj/money");
    if(1 == random(100))
    coins->set_money(12500 + random(8000));
    else
    coins->set_money(4500+random(800));
    move_object(coins, this_object());
    if(1==random(4)) {
        move_object(clone_object("players/mizan/etheriel/items/moo-toaster"), this_object());
    }
}

