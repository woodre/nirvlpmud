inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("bugs bunny");
    set_race("rabbit");
    set_alias("bugs");
    set_short("Bugs Bunny");
    set_long("You feel in awe, standing here in the presence of the GREAT Bugs Bunny.\n"+
    "He looks somewhat bewildered and flustered, but his charming demeanor and\n"+
    "calm attitude leads you to believe everything is under control.\n"+
    "Somehow, you imagined that he was taller.\n");
    set_level(16);
    set_hp(390);
    set_al(0);
    set_ac(23);
    set_wc(14);
    set_chance(25);
    set_spell_dam(35);
    set_spell_mess1("Bugs smashes you with an ACME Super Industrial Sledgehammer!");
    set_spell_mess2("Bugs whips out a glove loaded with a brick, and slaps you with it!");
    set_chat_chance(20);
    load_chat("Bugs chews on his carrot.\n");
    load_chat("Bugs says: Nyah... what's up, doc?\n");
    load_chat("Bugs says: Ahh.. nice weapons you got there hee hee.\n");
    load_chat("Bugs asks: Whatcha doin? Huntin' Elmers?\n");
    load_chat("Bugs chortles gleefully.\n");
    load_chat("Bugs ponders: I should have made that left turn at Albuquerque...\n");
    weapon=clone_object("players/mizan/etheriel/heals/raw-carrot.c");
    move_object(weapon, this_object());
}

