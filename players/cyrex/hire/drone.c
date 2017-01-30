
inherit "players/cyrex/hire/guard";

reset(x) {
  ::reset(x);
  if (!x) {
    set_name("drone");
    set_alias("lunk");
    set_alt_name("drone");
    set_short("Lunk the Drone");
    attack_string = " beeps: BEEP! BEEP! BEEP! BOP!";
    set_long("Lunk has seen many day of fighting. Although battle has\n"+
             "worn it down, it can still do some considerable damage!\n");
    set_level(14);
    set_chance(10);
    set_spell_mess1("Lunk sends an electric bolt at you...Zaaap!\n");
    set_spell_mess2("Lunk electrifies its opponent!!\n");
    set_spell_dam(25);
  }
}
