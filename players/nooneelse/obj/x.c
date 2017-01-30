/*
 x.c
*/
inherit "obj/monster";
reset(arg) {
  if (arg) return;
  ::reset(arg);
  set_name("x");
  set_level(1);
  set_hp(60000);
  set_wc(1);
  set_ac(1);
  set_al(0);
  set_ep(340);
  set_short("An x");
  set_long("An x.\n");
  set_aggressive(0);
  set_whimpy(0);
}
