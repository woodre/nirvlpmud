inherit "obj/monster";

reset(arg)
{
  object armor, gold;
  ::reset(arg);
  if(arg) return;
	set_name("worker");
	set_race("human");
	set_alias("worker");
	set_short("A Worker from Bigelow");
	set_long("The worker is a laborer in the rudimentary economic\n"+
		"system of the small town of Bigelow. He isn't very skilled\n"+
		"or very intelligent, but he goes to work everyday.\n");
	set_level(12);
	set_hp(150+random(200));
	set_al(-75);
	set_aggressive(0);
	gold = clone_object("obj/money");
	gold->set_money(200);
	move_object(gold,this_object());
	armor = clone_object("players/pain/NEW/arm/gloves");
	move_object(armor,this_object());
	init_command("wear gloves");
	set_wc(17);
        set_ac(10);
}
