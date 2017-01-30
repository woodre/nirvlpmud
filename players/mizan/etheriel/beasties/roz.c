inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("roz");
    set_race("roz");
    set_alias("rozzo");
    set_short("Roz the Dirt Collector");
    set_long("Roz is a frizzled looking individual in a dirty (once white)\n"+
           "laboratory coat. He is relentlessly searching for that perfect\n"+
           "soil specimen... Hmm.\n");
    set_level(15);
    set_hp(225);
    set_al(100);
    set_ac(12);
    set_wc(20);
    set_chance(9);
    set_spell_dam(30);
    set_spell_mess1("Roz screams: Auuugh!");
    set_spell_mess2("Roz throws some sand in your face!\nYou are blinded momentarily!\n\n\n\n");
    set_chat_chance(10);
    load_chat("Roz says: Hmm... No good dirt around here.\n");
    load_chat("Roz blinks his beady little eyes furiously.\n");
    load_chat("Roz goes: Where the hell am I?\n");
    load_chat("Roz screams: Wherever this is, there's no dirt!\n");
    load_chat("Roz cries: Soil! Humus! Compost! Dirt!\n");
    weapon=clone_object("players/mizan/etheriel/items/dirtvial.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/heals/dirtbag.c");
    move_object(treasure, this_object());
}
