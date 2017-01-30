inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a hoojib");
    set_race("hoojib");
    set_alias("hoojib");
    set_short("A hoojib");
    set_long("This is a small fuzzy thing, not as translucent as most of\n"+
    "the other things that you have seen floating around here, but\n"+
    "it still phases through most matter anyway.\n");
    set_level(12);
    set_hp(180);
    set_al(0);
    set_ac(7);
    set_wc(12);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("The hoojib is not terribly thrilled about being attacked.");
    set_spell_mess2("The hoojib fades into nothing.");
    set_chat_chance(20);
    load_chat("A hoojib clucks loudly.\n");
    load_chat("A hoojib waves its tentacles menacingly.\n");
    weapon=clone_object("players/mizan/etheriel/heals/zokball.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/blockbuster.c");
    move_object(treasure, this_object());
}
