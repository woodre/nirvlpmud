inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Emma");
  set_alt_name("emma");
  set_alias("murdoch");
  set_short("Emma Murdoch");
  set_long(
"Emma is a raven haired beauty with the kind of looks\n"+
"men have been known to raze small greek towns over.\n"+
"Her deep green eyes are so beautiful you feel like\n"+
"devoting your heart and happiness to her.  She is\n"+
"the estranged wife of John Murdoch.\n"
);
  set_gender("female");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(10);
  set_hp(175);
  set_al(2000);
  set_chat_chance(5);
  load_chat("Emma sings: Sway with me...\n");
  set_a_chat_chance(5);
  load_a_chat("Emma screams for help!\n");
}
