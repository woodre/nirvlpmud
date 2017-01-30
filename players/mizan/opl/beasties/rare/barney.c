inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"

reset(arg)
{
    object gold;
    ::reset(arg);
    if (arg) return;
    set_name("barney");
    set_name("barney");
    set_alias("barney");
    set_short("Barney the psychotic purple dinosaur");
    set_level(STATS_DM->get_level_easy());
    set_hp(STATS_DM->get_hp_easy());
    set_al(-540);
    set_wc(STATS_DM->get_wp_easy());
    set_ac(STATS_DM->get_ac_easy());
    set_hp_bonus(STATS_DM->get_hp_bonus_weak());
    set_heal(15, 1);

    set_chance(20);
    set_spell_dam(80);
    set_spell_mess1("Barney cackles: Die! Die! Die!\n");
    set_chat_chance(20);
    load_chat("Barney goes: I HATE kids, they HATE me...\n");
    load_chat("Barney says: Godzilla's a WUSS!\n");
    load_chat("Barney goes: The true God is SATAN!\n");
    load_chat("Barney cackles manically.\n");

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

}

