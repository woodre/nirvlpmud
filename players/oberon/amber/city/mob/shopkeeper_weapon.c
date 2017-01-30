#include <ansi.h>
inherit "/obj/monster";

string sellitem;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("weaponsmith");
	set_alias("smith");
	set_race("human");
	set_short("Amber's Prestige Weaponsmith");
	set_long("A very large man, selling world famous weapons from Amber.\n");
	set_gender("male");
	set_level(16);
	set_hp(1000000);
	set_wc(50);
	set_ac(50);
	set_aggressive(0);
	set_al(0);
	set_heal(5000, 1);
}

init() {
	::init();
	add_action("cmd_list", "list");
	add_action("cmd_buy", "buy");
}

heart_beat() {
	::heart_beat();
}

cmd_list() {
	write("+-------------------------------------------+\n");
	write("|  Item                  Alias      Cost    |\n");
	write("|                                           |\n");
	write("|  Sword of Healing      (heal)     $5,000  |\n");
	write("|  Sword of Detoxing     (detox)    $5,000  |\n");
	write("+-------------------------------------------+\n");
	return 1;
}

cmd_buy(arg) {
	switch(arg) {
		case "heal":
			if(this_player()->query_money() < 5000) { write("Not enough gold!\n"); break; }
			write("You purchase a Prestige Sword of Healing.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/sword_heal.c"), this_player());
			this_player()->add_money(-5000);
			break;
		case "detox":
			if(this_player()->query_money() < 5000) { write("Not enough gold!\n"); break; }
			write("You purchase a Prestige Sword of Detoxing.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/sword_detox.c"), this_player());
			this_player()->add_money(-5000);
			break;
		default:
			write("The Weaponsmith does not carry that item.\n");
			break;
	}
	return 1;
}
