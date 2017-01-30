inherit "obj/monster";

reset(arg)
{
  object gold,obj;
  ::reset(arg);
  if(arg) return;
  set_name("lord");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Champion Dwarven Lord");
  set_long("This Lord has risen higher than a regular lord.\n");
  set_level(19);
  set_hp(475);
  set_al(-500);
  set_wc(28);
  set_ac(16);
  gold=clone_object("obj/money");
  gold->set_money(2000);
  move_object(gold,this_object());
  obj=clone_object("/players/rumplemintz/obj/fake_questobj2");
  move_object(obj,this_object());
}
