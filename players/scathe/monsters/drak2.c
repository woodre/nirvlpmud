inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("A small Drak");
    set_long("\
A rather stupid beast, it is small and not tough looking except\n\
for its razor sharp teeth.  Its sinuous body shifts, seeking out\n\
your weak spots\n");
    set_level(17);
    set_hp(425);
    set_al(-1000);
    set_wc(24);
    set_ac(14);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(600 + random(100));
}
