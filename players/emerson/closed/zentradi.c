
inherit "players/cyrex/hire/guard";

reset(x) {
  ::reset(x);
  if (!x) {
    set_name("zentradi");
    set_alias("breetai");
    set_alt_name("zentradi");
    set_short("Breetai the Zentradi Commander");
    attack_string = " smirks and nods.";
    set_long("Breetai is the leader of the Zentradi Armada. The Zentradi\n"+
             "are beings bred solely for the disciplines of combat and\n"+
             "military strategy. They are a race of giants nearly 60 feet\n"+
             "tall. Humans appear to be microscopic in comparison. His\n"+
             "only concern is conquest at all cost. He is now under your\n"+
             "command so use him wisely.\n");
    set_level(18);
    set_chance(10);
    set_spell_mess1("Breetai throws his opponent against the wall, SMACK!!!\n");
    set_spell_mess2("Breetai smashes his opponent with incredible force!\n");
    set_spell_dam(45);
  }
}

