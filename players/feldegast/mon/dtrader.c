
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tully");
  set_alt_name("goodbeard");
  set_short("Tully Goodbeard");
  set_long(
"  Tully Goodbeard is a bespectacled dwarf, placed in charge of this\n"+
"obscure dwarven trading post due to his total lack of tact.  Beneath\n"+
"his long, luxurious black beard he wears a leather apron.\n"
  );
  set_gender("male");
  set_race("dwarf");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(200);
  set_chat_chance(3);
  load_chat("Tully putters about the shop.\n");
  load_chat("Tully fans his face with his apron.\n");
  load_chat("Tully says: Let me know if there's anything you need.\n");
  load_chat("Tully closes his eyes and nods off.\n");
  load_chat("Tully sweats profusely.\n");
  add_money(500+random(200));
}
