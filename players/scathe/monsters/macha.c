inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("macha");
    set_race("macha");  /* ? */
    set_short("The Macha!");
    set_long("\
This is the Macha! Beware, he is swift and dangerous!  He wears only\n\
few scars from past warriors foolish enough to attack.  He seems to\n\
be guarding great treasures.....\n");
    set_level(20);
    set_hp(500);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    set_chance(70);
    set_spell_dam(15+random(30));
    set_spell_mess1("HOLEEEEE MACHA!!!!!!!!!!!");
    set_spell_mess2("HOLEEEEE MACHA!!!!!!!!!!!");

    move_object(clone_object("/players/scathe/closed/rodm"), this_object());
}
