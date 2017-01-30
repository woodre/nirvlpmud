inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("cal");
   set_race("human");
  set_alias("cal");
  set_short("Cal");
  set_long("This time Cal is an example of a non-talking monster\n"+
	"Cal is fairly strong and is probably illegal, i haven't\n"+
	"checked him on the monster.chart yet.\n");
  set_level(10);
  set_hp(400);
  set_al(0);
  set_wc(18);
  set_ac(10);
}
