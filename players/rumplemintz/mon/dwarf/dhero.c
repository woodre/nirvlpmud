inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("hero");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Hero");
  set_long("A hero among the dwarven people, he looks well trained.\n");
  set_level(13);
  set_hp(195);
  set_al(-500);
  set_wc(17);
  set_ac(10);
  gold=clone_object("obj/money");
  gold->set_money(700);
  move_object(gold,this_object());
}
