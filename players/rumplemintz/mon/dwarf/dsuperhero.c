inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("superhero");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Superhero");
  set_long("A hero among the hero's, he's a bad dude.\n");
  set_level(17);
  set_hp(425);
  set_al(-500);
  set_wc(24);
  set_ac(14);
  gold=clone_object("obj/money");
  gold->set_money(950);
  move_object(gold,this_object());
}
