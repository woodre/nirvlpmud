inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("arthur dent");
    set_race("human");
    set_alias("arthur");
    set_short("Arthur Dent");
    set_long("This fellow looks very bewildered, and seems to be on the\n"+
    "verge of having a nervous breakdown. He is starting to panic.\n");
    set_level(10);
    set_hp(150);
    set_al(0);
    set_ac(8);
    set_wc(14);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Arthur screams: Do stop that!");
    set_spell_mess2("Arthur screams: Prefect!! Do something spectacularly amazing!");
    set_chat_chance(15);
    load_chat("Arthur looks around, woozily.\n");
    load_chat("Arthur curses: What in Zark's name happened?\n");
    load_chat("Arthur whines: Fooooooooord...\n");
    load_chat("Arthur says: I think I should have stuck to making sandwiches...\n");
    move_object(clone_object("players/mizan/etheriel/heals/sandwich.c"), this_object());
    weapon=clone_object("players/mizan/etheriel/items/butter-knife.c");
    move_object(weapon, this_object());
    treasure=clone_object("obj/money");
    treasure->set_money(200+random(30));
    move_object(treasure, this_object());
}
