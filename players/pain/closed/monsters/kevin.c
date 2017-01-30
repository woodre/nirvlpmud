
inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("kevin");
   set_race("human");
  set_alias("kevin");
  set_short("Young Kevin Barry <<martyr>>");
	set_long("This is a martyr who died in attempting to make his country free\n");
  set_level(20);
  set_hp(2000);
  set_al(500);
  set_wc(25);
  set_ac(70);
   weapon=clone_object("players/pain/closed/weapons/rebelweap.c");
  move_object(weapon,this_object());
  armor=clone_object("players/pain/closed/armor/rebelarmor.c");
  move_object(armor,this_object());
}

