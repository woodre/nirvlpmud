inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("A medium Drak");
    set_long("\
These Draks are much slightly more dangerous than other Draks of\n\
smaller size.\n");
    set_aggressive(1);
    set_level(19);
    set_hp(475);
    set_al(-1000);
    set_wc(28);
    set_ac(16);
    set_chance(25);
    set_spell_dam(18);
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(600 + random(100));
}
