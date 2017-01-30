inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object weapon,treasure,coins;
    ::reset(arg);
    if(arg) return;
    set_name("tuna fish");
    set_race("fish");
    set_short("A great big tuna fish");
    set_long("This appears to be a typical Atlantic tuna. It is big, and rather\n"+
    "dopey looking, but it appears to be having no trouble breathing.\n"+
        "You notice that the tuna is looking at you very closely.\n");
    set_level(8);
    set_hp(120);
    set_al(300);
    set_ac(12);
    set_wc(7);
    set_chance(25);
    set_spell_dam(8);
    set_spell_mess1("Tuna tries to swim away, but instead floogles helplessly.");
    set_spell_mess2("Tuna smashes you with a bone-jarring collision.");
    set_chat_chance(10);
    load_chat("The tuna fish blows some bubbles.\n");
    load_chat("The tuna fish flounders about.\n");
    treasure=clone_object("players/mizan/etheriel/heals/fishguts.c");
    move_object(treasure, this_object());
}

