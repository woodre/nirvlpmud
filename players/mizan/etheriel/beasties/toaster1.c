inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold;
    ::reset(arg);
    if(arg) return;
    set_name("toaster");
    set_race("toaster");
    set_alias("toaster");
    set_short("A singing toaster");
    set_long("This is a singing toaster. Yes, they're very commonplace...\n"+
    "It's alive, and does not like to be stared at.\n");
    set_level(10);
    set_hp(150);
    set_al(100);
    set_wc(14);
    set_ac(8);
    set_chance(10);
    set_spell_dam(10);
    set_spell_mess1("The toaster cries: O'fortuna! O'fortuna!");
    set_spell_mess2("The toaster cries: You're a jerk!");
    set_chat_chance(10);
    load_chat("The toaster sings: I try to discover... a little something to make me sweeter..\n");
    load_chat("The toaster sings: Oh baby refrain.. from breaking my heart.. I'm so in love\n"+"with you...\n");
    load_chat("The toaster sings: i'll be forever blue... that you gimme no reason...\n");
    load_chat("The toaster sings: e work so hard...\n");
    gold=clone_object("obj/money");
    gold->set_money(450);
    move_object(gold,this_object());
}
