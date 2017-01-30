inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("dragonne");
    set_race("dragonne");
    set_short("A Dragonne");
    set_long("\
A unique combination of dragon and lion, this creature has the scales\n\
of a dragon, but the body shape of a lion.  Beware his mighty roar.\n");
    set_level(14);
    set_hp(210);
    set_al(-1000);
    set_wc(18);
    set_ac(11);
    set_chance(25);
    set_spell_dam(10 + random(20));
    set_spell_mess1("The room trembles as the Dragonne unleashes his mighty roar");
    set_spell_mess2("Your bones rattle as the Dragonne's roar blasts you");
    set_chat_chance(20);
    load_chat("The Dragonne eyes you hungrily......\n");
    add_money(200 + random(650));
}
