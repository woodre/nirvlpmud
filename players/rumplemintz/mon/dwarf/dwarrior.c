inherit "obj/monster";
object gold;

reset(arg)
{
  if(arg) return;
  set_name("warrior");
  set_race("dwarf");
  set_alias("dwarf");
  set_short("A Dwarven Warrior");
   set_long("A slightly stronger Dwarven Warrior.\n");
  set_level(11);
  set_hp(165);
  set_al(-500);
  set_wc(15);
  set_ac(9);
  gold=clone_object("obj/money");
  gold->set_money(500);
  move_object(gold,this_object());
}
