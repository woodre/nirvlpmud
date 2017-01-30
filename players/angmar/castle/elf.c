#pragma strong_types

inherit "obj/monster";

void
reset(status arg) {
  object gold;
  if (arg)
    return;
  ::reset(arg);
  set_name("elf");
  set_short("An elf");
  set_long("An elf.\n");
  set_level(3);
  set_hp(45);
  set_wc(7);
  set_ac(4);
  set_al(20);
  gold = clone_object("obj/money");
  gold->set_money(80 + random(40));
  move_object(gold, this_object());
}
