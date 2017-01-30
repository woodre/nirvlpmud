inherit "obj/monster";

void reset(int arg) {
    object ob;
    ::reset(arg);
    if (arg || root()) return;

    set_name("Monk of the Dragon Fist Order");
    set_alias("initiate");
    set_alt_name("monk");
    set_race("human");
    set_short("An initiate of the Dragon Fist Order");
    set_long("\
A tired, stressed, and bedraggled specimen, this poor fellow seems\n\
to be having second thoughts about the path he has chosen for his\n\
life.  He looks at you wearliy, and sets about to do more chores.\n");
    set_level(10);
    set_hp(165);
    set_al(-1000);
    set_chance(10);
    set_spell_dam(10+random(15));
    set_spell_mess2("The initiate feebly strikes you with a soggy mop.");
    set_spell_mess1("Water flies as the initiate clubs his foe with a mop.");
    set_chat_chance(20);
    load_chat("Initiate moans:  I don't see how this will make me a great fighter.\n");
    add_money(random(20)+10);

    ob = clone_object("/players/scathe/armor/igarb");
    move_object(ob, this_object());
    command("wear garb", this_object());
    set_wc(14);
    set_ac(8);
}
