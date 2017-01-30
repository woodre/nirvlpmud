inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("A large Drak");
    set_long("\
About as big as most adult dragons, these Draks are very fearsome\n\
enemies, and the bones of their enemies surround their huge feet.\n");
    set_level(20);
    set_hp(500);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    set_chance(30);
    set_spell_dam(20);
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(1750 + random(100));
}
