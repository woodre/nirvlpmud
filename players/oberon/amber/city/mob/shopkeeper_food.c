#include <ansi.h>
inherit "/obj/monster";

string sellitem;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("foodsmith");
	set_alias("smith");
	set_race("human");
	set_short("Amber's Prestige Foodsmith");
	set_long("A very large man, selling world famous food from Amber.\n");
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
	write("|  Potion of Healing     (heal)     $2,250  |\n");
	write("|  Potion of Healing     (special)  $6,000  |\n");
	write("+-------------------------------------------+\n");
	return 1;
}

cmd_buy(arg) {
	switch(arg) {
		case "heal":
			if(this_player()->query_money() < 2250) { write("Not enough gold!\n"); break; }
			write("You purchase a Potion of Healing.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/heal.c"), this_player());
			this_player()->add_money(-2250);
			break;
		case "special":
			if(this_player()->query_money() < 6000) { write("Not enough gold!\n"); break; }
			write("You purchase a special Potion of Healing.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/healx.c"), this_player());
			this_player()->add_money(-6000);
			break;
		default:
			write("The Foodsmith does not carry that item.\n");
			break;
	}
	return 1;
}
