
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("vedira");
  set_alt_name("woman");
  set_short("Vedira");
  set_long(
"Vedira is a handsome young woman with long brown hair hanging\n"+
"down to the back of her red velvet dress.  Vedira was once the\n"+
"fiancee of a wise and powerful ruler, but when she rejected his\n"+
"love, he used his powerful magics to door her to live in this\n"+
"tapestry for as long as he walked the earth.\n"
);
  set_gender("female");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(500);
  set_chat_chance(5);
  load_chat("Vedira says: Please.  You must put me out of my misery.\n");
  load_chat("Vedira says: It has been centuries, yet he still walks the earth.  How?\n");
  load_chat("Vedira says: You MUST use the sunstone to destroy him.\n");
  load_chat("Vedira says: I watch the sun every day, yet it never sets.\n");
  add_money(450);
}
