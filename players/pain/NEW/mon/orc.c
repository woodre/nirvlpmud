inherit "obj/monster";

reset(arg)
{
  object weapon, gold;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("orc");
	set_short("An Orc");
	set_long("The orc stands just short of seven feet tall and is\n"+
		"clothed in the shoddy mail from the Clan. He grunts at\n"+
		"you as you glance at him and contemplates moving on.\n");
	set_level(10);
	set_hp(100+random(200));
	set_al(-75);
	set_wc(14);
	set_ac(8);
	set_aggressive(0);
	gold = clone_object("obj/money");
	gold->set_money(200+random(250));
	move_object(gold,this_object());
}
