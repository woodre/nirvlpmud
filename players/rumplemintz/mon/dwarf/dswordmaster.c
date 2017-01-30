inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("swordmaster");
  set_race("dwarf");
   set_alias("dwarf");
  set_short("A Dwarven Swordmaster");
  set_long("A proficient swordsman produced in the Dwarven area.\n");
  set_level(12);
  set_hp(180);
  set_al(-500);
  set_wc(16);
  set_ac(9);
  gold=clone_object("obj/money");
  gold->set_money(600);
  move_object(gold,this_object());
}
