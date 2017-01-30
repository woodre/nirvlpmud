/*
  ghoul.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
::reset(arg);
  if (arg) return;

  set_name("ghoul");
  set_level(6);
  set_alias("undead");
  set_hp(225);
  set_al(-200);
  set_short("A ghoul");
  set_long("A horrible, flesh-eating ghoul!\n");
  set_wc(12);
  set_ac(5);
  set_aggressive(1);
  obj=clone_object("obj/money");
  obj->set_money(200);
  move_object(obj, this_object());
}
