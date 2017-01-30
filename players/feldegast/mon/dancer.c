
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("juletane");
  set_alt_name("dancer");
  set_short("A belly-dancer");
  set_long(
"She wears the silks and scarves of her trade, simultaneously\n"+
"concealing and revealing her voluptuous figure.  Her long black\n"+
"hair trails down her back, and her lips are painted red.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(9);
  set_wc(12);
  set_ac(8);
  set_hp(130);
  set_al(0);
  set_chat_chance(4);
  load_chat("The dancer gyrates her hips lustily.\n");
  load_chat("The dancer casually sheds a scarf.\n");
  add_money(200+random(400));
}
