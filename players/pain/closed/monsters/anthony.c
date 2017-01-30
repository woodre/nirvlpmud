
inherit "obj/monster";

reset(arg)
{
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("anthony");
   set_race("human");
  set_alias("anthony");
  set_short("Anthony, Guardian of the Realm");
  set_long("	This is a proud warrior of the Clan McKay,\n"+
	"who has served his lord well. He is the finest warrior\n"+
	"in the land. It will be difficult to kill this man.\n");
  set_level(20);
  set_hp(1000);
  set_al(500);
  set_ac(11);
  if(random(3) == 1) {
		weapon = clone_object("/players/pain/NEW/items/retribution.c");
		move_object(weapon,this_object());
		init_command("wield claymore");
		set_wc(20);
	}
else {
	weapon = clone_object("/players/pain/closed/weapons/slswdweap.c");
	move_object(weapon,this_object());
	init_command("wield blade");
	}
}

