inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
/* These clone unlimited without a check so here is a check
 * -Snow 6/99 */
/* 03/22/06 Earwax: they dest themselves every reset */
/*
  if(arg) { dest_me(); return; }
*/
if (arg) return;
  ::reset(arg);
	set_name("sapper");
	set_race("human");
	set_alias("sapper");
	set_short("A Korean Sapper (*Devious*)");
	set_level(20);
	set_long("The Korean Sapper is clothed in the uniform of the\n"+
	        "North Korean Army. He's been trained by the Chinese to infiltrate\n"+
	       "American camps and cause havoc. You should be quite\n"+
	       "wary of this devious, well armed fellow.\n");
	set_hp(400+random(250));
/* Changed from 250 to -500. To match description and fit with area theme. MASH creatures changed from evil to neutral. -Snow 3/00 */
	set_al(-500);
	set_aggressive(random(2));
	set_chat_chance(7);
	set_a_chat_chance(7);
	load_chat("The Sapper surveys the area carefully.\n");
	load_a_chat("The Sapper prepares himself for battle.\n");
	set_chance(35);
	set_spell_mess1("The Sapper throws a stick of dynamite at you.\n");
	set_spell_dam(30);
/*
	armor = clone_object("players/pain/NEW/arm/pmail.c");
	move_object(armor,this_object());
	init_command("wear platemail");
*/
	weapon = clone_object("players/pain/NEW/weap/carbine.c");
	move_object(weapon,this_object());
	init_command("wield carbine");
	call_out("random_move",10);
	set_wc(30);
        set_ac(17);
}

/* New func. -Snow */
dest_me() {
  object wep;
  while(remove_call_out("random_move") != -1); /* verte */
   set_heart_beat(0);
  wep = present("carbine");
  if(wep) destruct(wep);
  destruct(this_object());
  return; }

random_move() {
    int n;
  if(!environment()) return 1;
if(!query_attack()) {
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
}
call_out("random_move",10);
return 1;
}
