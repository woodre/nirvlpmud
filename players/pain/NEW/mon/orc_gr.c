inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("orc");
	set_short("An Orc Grunt");
	set_long("The grunt stands just short of eight feet tall and is\n"+
		"clothed in the Red and Silver of the Clan. He grunts at\n"+
		"you as you glance at him. The points on his horned helm\n"+
		"look quite sharp. You should probably avoid them.\n");
	set_level(10);
	set_hp(100+random(200));
	set_al(-150);
	set_aggressive(1);
	armor = clone_object("players/pain/NEW/arm/helm.c");
	move_object(armor,this_object());
	init_command("wear helm");
	set_wc(20);
        set_ac(12);
}
