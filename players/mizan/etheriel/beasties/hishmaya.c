inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure,coins;
    ::reset(arg);
    if(arg) return;
    set_name("hishmaya");
    set_alias("underling");
    set_race("hishmaya");
    set_short("Hishmaya the underling");
    set_long("The ...figure... hovering before you.. has a face like a Picasso\n"+
    "painting. The rest of his body is gnarled and contorted as well, and \n"+
    "he carries himself in a very evil albeit goofy manner. He appears to\n"+
    "be livid with anger and frustration and generally very dangerous.\n");
    set_level(16);
    set_hp(350);
    set_al(-820);
    set_ac(13);
    set_wc(22);
    set_chance(25);
    set_spell_dam(22);
    set_spell_mess1("Hishmaya lets loose with a flurry of blows in blind rage.");
    set_spell_mess2("Hishmaya screams: WHY??? WHY ME???");
    set_chat_chance(10);
    load_chat("Hishmaya grunts.\n");
    load_chat("Hishmaya stares at you evilly.\n");
    load_chat("Hishmaya fumes angrily.\n");
    coins=clone_object("obj/money");
    coins->set_money(800+random(100));
    move_object(coins, this_object());
    weapon=clone_object("players/mizan/etheriel/items/bknuckles.c");
    move_object(weapon, this_object());
}

