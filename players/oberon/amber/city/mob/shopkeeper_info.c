#include <ansi.h>
inherit "/obj/monster";

string sellitem;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("shopkeeper");
	set_alias("keeper");
	set_race("human");
	set_short("Information Shopkeeper");
	set_long("A very large man, selling information about Amber.\n");
	set_gender("male");
	set_level(16);
	set_hp(600 + random(1000));
	set_wc(30);
	set_ac(20);
	set_aggressive(0);
	set_al(0);
	add_money(5000+random(1000));
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
	write("|  Map of Amber          (map)      $500    |\n");
	write("+-------------------------------------------+\n");
	return 1;
}

cmd_buy(arg) {
	switch(arg) {
		case "map":
			if(this_player()->query_money() < 500) { write("Not enough gold!\n"); break; }
			/*write("The shopkeeper is fresh out of maps. Try again later!\n");*/
			write("You purchase a Map of Amber.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/map.c"), this_player());
			this_player()->add_money(-500);
			break;
		default:
			write("The Shopkeeper does not carry that item.\n");
			break;
	}
	return 1;
}
