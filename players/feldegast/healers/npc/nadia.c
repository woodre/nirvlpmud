
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("nadine mouelhi");
  set_alt_name("nadine");
  set_alias("mouelhi");
  set_short("Nadine Mouelhi");
  set_long(
"Nadine Mouelhi is an attractive young apprentice healer with a\n"+
"serious expression on her face.  Despite her sometimes stoic manner,\n"+
"she seems a bit ditzy.  She wears a blue cape pinned with a brooch\n"+
"over her floral yellow dress.\n"
);
  set_gender("female");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(800);
  set_chat_chance(5);
  load_chat("");
  set_a_chat_chance(0);
  load_a_chat("");
  add_money(600);
}
