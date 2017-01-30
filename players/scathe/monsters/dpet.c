inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("pet");
    set_race("pet");
    set_short("A Dopple Pet");
    set_long("\
A messy unbroken Dopple Pet.  It snaps at your heels and raises its\n\
hackles.  You feel moved to kill it and make the mud a cleaner place.\n");
   set_level(3 + random(3));
   set_hp(40 + random(25));
   set_wc(6 + random(4));
   set_ac(2 + random(4));
    set_al(-100);
   set_chance(5);
    set_spell_dam(1 + random(4));
    set_spell_mess1("The pet excitedly humps your leg! YUCK!");
    set_spell_mess2("The pet gets a little too excited....");
    load_chat("Pet whimpers after being abused by its master.\n");
    add_money(100 + random(105));
}
