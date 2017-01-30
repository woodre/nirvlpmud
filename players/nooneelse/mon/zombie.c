/*
  zombie.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
::reset(arg);
if(arg) return;
  set_name("zombie");
  set_level(4);
  set_alias("undead");
  set_race("zombie");
  set_hp(130);
  set_al(-200);
  set_short("A zombie");
  set_long("A terrible smelling, rotting zombie!\n");
  set_wc(7);
  set_ac(5);
  set_aggressive(1);
  set_alt_name("nooneelsezombie");
  obj=clone_object("obj/money");
  obj->set_money(150);
  move_object(obj, this_object());
}
