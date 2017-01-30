
inherit "players/cyrex/hire/guard";

reset(x) {
  ::reset(x);
  if (!x) {
    set_name("invid");
    set_alias("invid");
    set_alt_name("trooper");
    set_short("Invid Shock Trooper");
    attack_string = " says: As you wish.";
    set_long("This invid is not out for fun and games. It needs some\n"+
             "excercise in killing.\n");
    set_level(15);
    set_chance(10);
    set_spell_mess1("Invid Shock Trooper tears at you!\n");
    set_spell_mess2("Invid Shock Trooper tears at its opponent!\n");
    set_spell_dam(30);
  }
}

