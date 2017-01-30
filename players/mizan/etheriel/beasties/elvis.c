inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure,coins;
    ::reset(arg);
    if(arg) return;
    set_name("elvis");
    set_race("The King");
    set_alias("impersonator");
    set_short("An Elvis impersonator");
    set_long("A cult phenomenon in the United States, impersonating the King has\n"+
    "almost become a national pastime. This fellow here, however, really\n"+
    "should keep his day job.\n");
    set_level(6);
    set_hp(90);
    set_al(0);
    set_ac(5);
    set_wc(10);
    set_chance(25);
    set_spell_dam(6);
    set_spell_mess1("Elvis sneers at you.");
    set_spell_mess2("Elvis goes: 'Ah hey!");
    set_chat_chance(14);
    load_chat("Elvis goes: You 'aint nothing but a hound dog! Uh-huh..\n");
    load_chat("Elvis goes: Uh-huh. Yeah baby..\n");
    coins=clone_object("obj/money");
    coins->set_money(80+random(25));
    move_object(coins, this_object());
    weapon=clone_object("players/mizan/etheriel/heals/herring.c");
    move_object(weapon, this_object());
}

