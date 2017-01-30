
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("May");
  set_alt_name("may");
  set_alias("hooker");
  set_short("May");
  set_long(
"May is a sultry young prostitute wearing a short\n"+
"skirt and fishnet stockings.  She wears too much\n"+
"make-up, but she makes up for it with a seductive\n"+
"personality and a husky voice.\n"
);
  set_gender("female");
  set_race("human");
  set_level(10);
  set_wc(15);
  set_ac(8);
  set_hp(145);
  add_money(450);
  set_al(0);
  set_chat_chance(8);
  load_chat("May runs a seductive finger down your chest.\n");
  load_chat("May shifts her clothes flirtatiously.\n");
  set_a_chat_chance(7);
  load_a_chat("May screams for help!");
}
