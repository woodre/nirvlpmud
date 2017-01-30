/*
  spectre.c
*/

inherit "obj/monster";

reset(arg) {
  object obb;
  ::reset(arg);
  if(arg) return;
  set_name("spectre");
  set_level(5);
  set_alias("undead");
  set_race("spectre");
  set_hp(275);
  set_al(-300);
  set_short("Spectre");
  set_long("A chilling spectre!\n");
  set_wc(12);
  set_ac(8);
  set_aggressive(1);
  obb=clone_object("obj/money");
  obb->set_money(200);
  move_object(obb, this_object());
}

id(str) { return str=="spectre" || str=="nooneelsespectre" ||
                 str=="undead"; }
