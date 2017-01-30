inherit "obj/monster";

reset(arg)
{
  object gold,obj;
  ::reset(arg);
  if(arg) return;
  set_name("lord");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Superhero Dwarven Lord");
  set_long("One of the top of the lords, he is mega-mean.\n");
  set_level(20);
  set_hp(500);
  set_al(-500);
  set_wc(30);
  set_ac(17);
  gold=clone_object("obj/money");
  gold->set_money(5000);
  move_object(gold,this_object());
  obj=clone_object("/players/rumplemintz/obj/fake_questobj3");
  move_object(obj,this_object());
}
