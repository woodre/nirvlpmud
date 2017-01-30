/*
  wraith.c
*/

inherit "obj/monster";

reset(arg) {
  object obb;
  ::reset(arg);
  if(arg) return;
  set_name("wraith");
  set_level(5);
  set_alias("undead");
  set_race("wraith");
  set_hp(150);
  set_al(-300);
  set_short("A wraith");
  set_long("A life-stealing wraith!\n");
  set_wc(8);
  set_ac(7);
  set_aggressive(1);
  set_alt_name("nooneelsewraith");
  obb=clone_object("obj/money");
  obb->set_money(200);
  move_object(obb, this_object());
}
