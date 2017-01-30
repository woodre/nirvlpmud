inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("champion");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Champion");
  set_long("This dwarf has proven his abilities in combat, beware.\n");
  set_level(16);
  set_hp(400);
  set_al(-500);
  set_wc(22);
  set_ac(13);
  gold=clone_object("obj/money");
  gold->set_money(890);
  move_object(gold,this_object());
}
