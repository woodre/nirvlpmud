
inherit "players/cyrex/hire/guard";

reset(x) {
  ::reset(x);
  if (!x) {
    set_name("bioroid");
    set_alias("bioroid");
    set_alt_name("guardian");
    set_short("Red Bioroid Guardian");
    attack_string = " booms: I will obey!";
    set_long("A massive hulk of a mech programmed to serve and obey.\n");
    set_level(16);
    set_chance(10);
    set_spell_mess1("Bioroid crushes you with awestruck force!\n");
    set_spell_mess2("Bioroid crushes his opponent with awestruck force!\n");
    set_spell_dam(35);
  }
}

