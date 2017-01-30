inherit "obj/monster";

reset(arg){
    object ob;

    ::reset(arg);
    if (arg || root()) return;
    set_name("Monk of the Dragon Fist Order");
    set_alias("monk");
    set_race("human");
    set_short("A Monk of the Dragon Fist Order");
    set_long("\
At first glance, this robed man seems rather harmless. Do not be\n\
fooled though, the monks of the Dragon Fist Order are among the\n\
most powerful fighters in the world.\n");
    set_level(12);
    set_hp(180);
    set_al(-1000);
    set_chance(20);
    set_spell_dam(15+random(15));
    set_spell_mess2("The monk concentrates for a moment, and strikes you with a glowing fist.");
    set_spell_mess1("The monk smashes his foe with a glowing fist!");
    set_chat_chance(20);
    load_chat("The monk says: How are you today?\n");

    ob = clone_object("/players/scathe/armor/damulet");
    move_object(ob, this_object());
    command("wear amulet", this_object());

    ob = clone_object("/players/scathe/armor/garb");
    move_object(ob, this_object());
    command("wear garb", this_object());
    set_wc(16);
    set_ac(9);
}
