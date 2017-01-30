inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/pain/color.h"
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())

reset(arg)
{
  object weapon, armor, gold;
  ::reset(arg);
  if(arg) return;
	set_name("paladin");
	set_race("human");
	set_alias("paladin");
	set_short("A Paladin in the service of Bigelow");
	set_long("The Paladin sits atop a beautiful white charger watching\n"+
		"over the city and inhabitants of Bigelow. He is a symbol\n"+
		"of all that is right and good in Bigelow and is a stalwart\n"+
		"against the onslaught of the orc Clan.\n");
	set_level(20);
	set_hp(400+random(250));
	set_al(250);
	set_aggressive(0);
	set_chat_chance(7);
	set_a_chat_chance(7);
	load_chat("The Paladin surveys the area carefully.\n");
	load_a_chat("The Paladin charges to the defense of Bigelow.\n");
	gold = clone_object("obj/money");
	gold->set_money(random(500) + 3000);
	move_object(gold,this_object());
	armor = clone_object("players/pain/NEW/arm/pmail.c");
	move_object(armor,this_object());
	init_command("wear platemail");
	weapon = clone_object("players/pain/NEW/weap/mstar.c");
	move_object(weapon,this_object());
	init_command("wield morningstar");
	call_out("random_move",10);
	call_out("rebeat",10);
	set_wc(30);
    set_ac(17);
    set_wc_bonus(24);
}

heart_beat() {
	::heart_beat();

if((MEAT) && (random(9) <= 3)) {
	do_stuff(MEAT);
	}
return 1;
}

do_stuff(object ob) {
if(present(MEAT,environment(TO))) {
tell_object(MEAT,"The Paladin raises his morningstar high aboce his head.\n"+
	"The Paladin brings the morningstar "+BOLD+RED+"S L A M M I N G"+END+" down!.\n"+
	"The Paladin beats you to a "+BOLD+RED+"bloody pulp"+END+".\n");
if(ob->is_player()) {
	ob->add_hit_point(-(random(30)+15));
	return 1;
	}
ob->hit_player(random(50)+50);
return 1;
}
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
call_out("random_move",10);
return 1;
}

rebeat() {
	call_out("rebeat",20);
	set_heart_beat(1);
	heart_beat();
	return 1;
}

