inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("A medium Drak");
    set_long("\
This Drak is not very big compared to most dragons, but it is\n\
smarter and stronger than its smaller kindred.\n");
    set_aggressive(1);
    set_level(18);
    set_hp(450);
    set_al(-1000);
    set_wc(26);
    set_ac(16);
    set_chance(22);
    set_spell_dam(15);
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(600 + random(100));
}
