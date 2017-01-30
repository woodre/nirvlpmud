#pragma strong_types

inherit "obj/monster";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("spider");
  set_short("A small poison spider");
  set_long(
"A little black poison spider.\n");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(100);
  add_money(450);
}
