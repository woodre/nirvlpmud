inherit "obj/monster";

reset(arg)
{
  object weapon, gold;
  ::reset(arg);
  if(arg) return;
	set_name("bunny");
	set_alias("bunny");
	set_short("A cute little bunny");
	set_long("A cute little bunny hopping about.\n");
	set_level(5);
	set_hp(75+random(30));
	set_al(50);
	set_aggressive(0);
	set_wc(9);
        set_ac(5);
	gold = clone_object("obj/money");
	gold->set_money(150+random(60));
	move_object(gold,this_object());
   /* 03/24/06 Earwax: changed to use standard wander code */
   set_wander_interval(10);
   set_wander(1);
  set_wander_realm("/players/pain/NEW");
}
random_move() {
    int n;
	call_out("random_move",10);
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

