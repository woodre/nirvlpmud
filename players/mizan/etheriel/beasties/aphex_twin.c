inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("Mr. James");
    set_race("human");
    set_alias("james");
    set_short("Mr. James");
    set_long(" " +
    "Cloaked in a black leather anorak, James is hunched over some kind\n"+
    "of music machine. He does not appear to be too happy to see you.\n");
    set_level(11);
    set_hp(160);
    set_al(-20);
    set_ac(9);
    set_wc(15);
    set_chance(25);
    set_spell_dam(11);
    set_spell_mess1("Mr. James punches you!");
    set_spell_mess2("Mr. James kicks you in the shins!");
    set_chat_chance(10);
    load_chat("Mr. James goes: Get out!\n");
    load_chat("Mr. James cries: Can't a man work alone in peace??\n");
    load_chat("Mr. James grumbles.\n");
    load_chat("Mr. James pushes a button and you hear some strange-as-heck sounds.\n");
    move_object(clone_object("players/mizan/etheriel/items/bowling-ball-weapon.c"), this_object());
    move_object(clone_object("players/mizan/etheriel/items/solenoid.c"), this_object());
}
