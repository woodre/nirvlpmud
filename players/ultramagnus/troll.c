inherit "obj/monster.c";

reset(arg)
{
	object weapon;
	object armor;
	::reset(arg);
	if(arg) return;
set_name("troll");
set_wc(10);
set_ac(7);
set_level(9);
set_al(-100);
set_hp(100);
set_short("An ugly little troll.");
set_long("An ugly little troll about 4 feet tall.");
set_aggressive(1);
weapon=clone_object("/players/ultramagnus/axe.c");
move_object(weapon,this_object());
command("wield axe",this_object());
}
