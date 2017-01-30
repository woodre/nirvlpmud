inherit "obj/monster";

reset(arg)
{
  object weapon, gold;
  ::reset(arg);
  if(arg) return;
	set_name("orc");
	set_alias("orc");
	set_short("A Rogue Orc");
	set_long("A Rogue Orc, not allied with a Clan.\n");
	set_level(15);
	set_hp(175+random(100));
	set_al(50);
	set_aggressive(1);
	set_wc(20);
        set_ac(12);
	gold = clone_object("obj/money");
	gold->set_money(750+random(200));
	move_object(gold,this_object());
   /* 03/24/06 Earwax: changed to use standard wander code */
   set_wander_interval(10);
   set_wander(1);
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

