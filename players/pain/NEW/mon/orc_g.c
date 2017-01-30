inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_race("orc");
	set_alias("guard");
	set_short("An Orc Guard");
	set_long("The guard stands just short of eight feet tall and is\n"+
		"clothed in the Red and Silver of the Clan. He grunts at\n"+
		"you as you glance at him and hefts his mace menacingly.\n");
	set_level(15);
	set_hp(200+random(200));
	set_al(-100);
	set_aggressive(1);
	weapon = clone_object("players/pain/NEW/weap/mace.c");
	move_object(weapon,this_object());
	init_command("wield mace");
	call_out("random_move",10);
	set_wc(20);
        set_ac(12);
}
random_move() {
    int n;
    n = random(8);
    if (n == 0)
        command("west");
    else if (n == 1)
        command("east");
    else if (n == 2)
        command("south");
    else if (n == 3)
        command("north");
    else if (n == 4)
        command("northwest");
    else if (n == 5)
        command("southwest");
    else if (n == 6)
        command("northeast");
    else if (n == 7)
        command("southeast");
call_out("random_move",20);
return 1;
}

