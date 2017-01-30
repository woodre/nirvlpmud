inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/FastRandomMove.c"

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("pascale the happy wombat");
    set_race("wombat");
    set_alias("pascale");
    set_short("Pascale the happy wombat");
    set_long("Pascale is a happy green wombat. A wombat is a large marsupial\n"+
    "indigenous to the continent of Australia, and he is green because\n"+
    "he dyed his hairs. Don't stare! It's impolite.\n");
    set_level(15);
    set_hp(225);
    set_al(600);
    set_ac(12);
    set_wc(20);
    set_chance(25);
    set_spell_dam(30);
    set_spell_mess1("Pascale says: Hey, you... dick!");
    set_spell_mess2("Pascale poots all over you. Gross.");
    set_chat_chance(10);
    load_chat("Pascale licks himself.\n");
    load_chat("Pascale chomps on some dirt.\n");
    load_chat("Pascale peers at you quizzically.\n");
    weapon=clone_object("players/mizan/etheriel/items/telephone-pole.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/bunny-slippers.c");
    move_object(treasure, this_object());
}
