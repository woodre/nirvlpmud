inherit "obj/monster";

reset(arg)
{
  object gold,obj;
  ::reset(arg);
  if(arg) return;
  set_name("lord");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Lord");
  set_long("Lord of the Dwarves.\n");
  set_level(18);
  set_hp(450);
  set_al(-500);
  set_wc(26);
  set_ac(15);
  gold=clone_object("obj/money");
  gold->set_money(1000);
  move_object(gold,this_object());
  obj=clone_object("/players/rumplemintz/obj/fake_questobj");
  move_object(obj,this_object());
}
