
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("karl");
  set_alt_name("uncle");
  set_alias("uncle karl");
  set_short("Uncle Karl");
  set_long(
"Uncle Karl is a grizzled old sailor with a salt and pepper\n"+
"beard.  For some unknown reason, he is confined to a rickety\n"+
"old wheelchair.\n"
);
  set_gender("male");
  set_race("human");
  set_level(9);
  set_wc(12);
  set_ac(7);
  set_hp(155);
  add_money(400);
  set_al(400);
  set_chat_chance(5);
  load_chat("Uncle Karl says: What're you doing here?\n");
  load_chat("Uncle Karl says: Have you seen my nephew?\n");
  load_chat("Uncle Karl says: Where IS Shell Beach anyway?\n");
  set_a_chat_chance(8);
  load_a_chat("Uncle Karl runs over your foot with his wheelchair.\n");
}
