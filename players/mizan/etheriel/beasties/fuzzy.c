inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("Fuzzy-Wuzzy");
    set_race("bear");
    set_alias("fuzzy-wuzzy");
    set_short("A bear named Fuzzy-Wuzzy");
    set_long("Fuzzy-Wuzzy is a bear.\n"+
    "Fuzzy-Wuzzy has no hair.\n"+
    "Fuzzy-Wuzzy was'nt fuzzy was he?\n");
    set_level(15);
    set_hp(225);
    set_al(600);
    set_ac(12);
    set_wc(20);
    set_chance(25);
    set_spell_dam(30);
    set_spell_mess1("Fuzzy-Wuzzy goes: Auuugh!");
    set_spell_mess2("Fuzzy-Wuzzy screams in pain.");
    set_chat_chance(10);
    load_chat("Fuzzy-Wuzzy blinks.\n");
    weapon=clone_object("players/mizan/etheriel/items/spuckpistol.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/spuckballs.c");
    move_object(treasure, this_object());
}
