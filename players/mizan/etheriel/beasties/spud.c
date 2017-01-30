inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("spud");
    set_race("spud");
    set_alias("potato");
    set_short("A potato named Spud");
    set_long("This is an animated potato, obviously the work of a baby-wizzy.\n"+
    "Stop laughing! Someday, the wizard that created this misbegotten\n"+
    "thing will be churning out iron golems faster than you can say\n"+
    "'flee!'.\n");
    set_level(5);
    set_hp(75);
    set_al(100);
    set_ac(5);
    set_wc(9);
    set_chance(25);
    set_spell_dam(10);
    set_spell_mess1("Spud cries: heeeeeeeelp!");
    set_spell_mess2("Spud tries to flee, but fails.");
    set_chat_chance(10);
    load_chat("Spud says: I'm a potato.\n");
    load_chat("Spud says: How are you today?\n");
    load_chat("Spud looks at you.\n");
    weapon=clone_object("players/mizan/etheriel/items/pencil.c");
    move_object(weapon, this_object());
    treasure=clone_object("obj/money");
    treasure->set_money(100+random(50));
    move_object(treasure, this_object());
}
