
inherit "players/cyrex/hire/guard";

reset(x) {
  ::reset(x);
  if (!x) {
    set_name("zor");
    set_alias("zor");
    set_alt_name("master");
    set_short("Zor Prime the Master");
    attack_string = " laughs and nods.";
    set_long("Zor, the father of Robotechnology. He is excellent in mind\n"+
             "and in combat. However, one can't tell if he is a clone or\n"+
             "not. Don't disappoint him and die while he is under your\n"+
             "service.\n");
    set_level(17);
    set_chance(10);
    set_spell_mess1("Zor dodges and strikes with incredible speed!\n");
    set_spell_mess2("Zor swiftly dodges the blow and strikes with power!\n");
    set_spell_dam(40);
  }
}
