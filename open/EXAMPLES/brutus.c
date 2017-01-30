inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("brutus");
   set_race("human");
  set_alias("brutus");
  set_short("Brutus");
  set_long("This time Brutus is an example of a non-talking monster\n"+
	"Brutus is fairly strong and is probably illegal, i haven't\n"+
	"checked him on the monster.chart yet.\n");
  set_level(10);
  set_hp(400);
  set_al(0);
  set_wc(18);
  set_ac(10);
   weapon=clone_object("/open/EXAMPLES/brutusweap");
  move_object(weapon,this_object());
  armor=clone_object("/open/EXAMPLES/brutusarmor");
  move_object(armor,this_object());
}
