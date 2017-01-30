inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("swashbuckler");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Swashbuckler");
  set_long("Just swashbuckin away!\n");
  set_level(14);
  set_hp(210);
  set_al(-500);
  set_wc(18);
  set_ac(11);
  gold=clone_object("obj/money");
  gold->set_money(850);
  move_object(gold,this_object());
}
