inherit "obj/monster";

void reset(int arg) {
    object ob;

    ::reset(arg);
    if (arg || root()) return;

    set_name("executioner");
    set_race("human");
    set_short("A hooded Executioner");
    set_long("\
A large and powerfully built man, he wears a black uniform, and the\n\
only part of him you can see are his eyes.  He cuts to your soul with\n\
his stare, and to your heart with his mighty axe.....\n");
    set_level(19);
    set_hp(500);
    set_al(-1000);
    set_aggressive(1);
    set_chance(33);
    set_spell_dam(50+random(15));
    set_spell_mess2("The Executioners Axe crunches through your bone");
    set_spell_mess1("The Executioner's Axe slams its foe to the ground");
    set_chat_chance(20);
    load_chat("The Executioner sharpens his axe slowly.....\n");

    add_money(500 + random(750));

    ob = clone_object("/players/scathe/weap/baxe");
    move_object(ob, this_object());
    command("wield axe", this_object());

    ob = clone_object("/players/scathe/armor/suit");
    move_object(ob, this_object());
    command("wear suit", this_object());

    ob = clone_object("/players/scathe/armor/hood");
    move_object(ob, this_object());
    command("wear hood", this_object());
    set_wc(28);
    set_ac(16);
}
