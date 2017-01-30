inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("Symidryl");
    set_race("dragon");
    set_alias("symidryl");
    set_short("A Symidryl");
    set_long("	This is a rather cute, miniature dragon. It is about the\n"+
    "  size of a house cat, and is fluttering about on its delicate little\n"+
    "  wings. It appears to be very happy, and is singing a merry song\n"+
    "  in its crisp, high-pitched voice.\n");
    set_level(3);
    set_hp(45);
    set_al(500);
    set_ac(6);
    set_wc(7);
    set_chance(25);
    set_spell_dam(7);
    set_spell_mess1("Symidryl casts magic missile!");
    set_spell_mess2("Symidryl emits an ultrasonic howl that gives you a headache!");
    set_chat_chance(10);
    load_chat("Symidryl chirps happily.\n");
    load_chat("Symidryl smiles at you.\n");
    treasure=clone_object("obj/money");
    treasure->set_money(50+random(10));
    move_object(treasure, this_object());
    weapon=clone_object("players/mizan/etheriel/heals/eigth-note.c");
    move_object(weapon, this_object());
}
