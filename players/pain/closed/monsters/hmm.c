
inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("kevin");
   set_race("human");
  set_alias("kevin");
set_short("Kevin");
	set_long("This is a martyr who died in attempting to make his country free\n");
  set_level(100);
  set_hp(2);
  set_al(500);
  set_wc(2);
  set_ac(0);
}

