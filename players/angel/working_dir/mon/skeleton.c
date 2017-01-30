/*
  skeleton.c
*/

inherit "obj/monster";

reset(arg) {
  object obb;
  ::reset(arg);
  if(arg) return;
  set_name("skeleton");
  set_level(4);
  set_race("skeleton");
  set_hp(225);
  set_al(-200);
  set_short("skeleton");
  set_long("A rattling, undead skeleton!\n");
  set_wc(10);
  set_ac(1);
  set_aggressive(1);
  obb=clone_object("obj/money");
  obb->set_money(150);
  move_object(obb, this_object());
}

id(str) { return str=="skeleton" || str=="nooneelseskeleton" ||
                 str=="undead"; }
