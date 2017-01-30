inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("ford prefect");
    set_race("human");
    set_alias("prefect");
    set_short("Ford Prefect");
    set_long("This fellow does'nt look as twitchy as Arthur, but he is\n"+
    "very disoriented, and is still mad about losing his left shoe\n"+
    "while falling out of the window of an office building... \n"+
    "But that is another story...\n");
    set_level(12);
    set_hp(175);
    set_al(0);
    set_ac(9);
    set_wc(15);
    set_chance(25);
    set_spell_dam(14);
    set_spell_mess1("Prefect kicks you.  OUCH!!");
    set_spell_mess2("Prefect goes: Ahooooo.. Arthur, we are in a bit of a predicament!");
    set_chat_chance(15);
    load_chat("Prefect surveys the area.\n");
    load_chat("Prefect says: Ahh...er... I can't say that I've been here before...\n");
    load_chat("Prefect fiddles with a hand-held computer.\n");
    weapon=clone_object("players/mizan/etheriel/items/right-shoe.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/guide2.c");
    move_object(treasure, this_object());
}
