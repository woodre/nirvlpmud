#include <ansi.h>
inherit "/obj/monster";

#define COST 80000
string sellitem;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("armorsmith");
	set_alias("smith");
	set_race("human");
	set_short("Amber's Prestige Armorsmith");
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
	write("|  Item                 Alias      Cost     |\n");
	write("|                                           |\n");
	write("|  Ring of Protection   (rop)      $"+COST+"   |\n");
	write("+-------------------------------------------+\n");
	return 1;
}

cmd_buy(arg) {
	switch(arg) {
		case "rop":
			if(this_player()->query_money() < COST) { write("Not enough gold!\n"); break; }
			write("You purchase a Ring of Protection.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/rop.c"), this_player());
			this_player()->add_money(-COST);
			break;
		default:
			write("The Armorsmith does not carry that item.\n");
			break;
	}
	return 1;
}
