
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Gene the Shopkeeper");
  set_alt_name("gene");
  set_alias("shopkeeper");
  set_short("Gene the Shopkeeper");
  set_long(
"Gene is a cheery fellow in his mid-twenties with a pale complection\n"+
"and rosy red cheeks.  His hair is combed back and tied into a ponytail\n"+
"and he wears an old apron while he tends his shop.\n"
);
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(20);
  set_ac(14);
  set_hp(400);
  set_al(350);
  set_chat_chance(5);
  load_chat("Gene putters about the shop.\n");
  load_chat("Gene carefully polishes the counter with an old rag.\n");
  add_money(random(600));
}
