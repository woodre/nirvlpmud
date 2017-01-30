/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	rblade.c
=-=
=-=	An Elite Elven Guard's Runeblade
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/weapon";
#include "/players/pain/color.h"
#define TPN this_player()->query_name()
#define TPS this_player()->query_sp()
#define ATTN attacker->query_name()

reset() {
	set_name("runeblade");
	set_short("An "+BOLD+GREEN+"Elven"+END+" "+BOLD+BLUE+"Runeblade"+END);
	set_long("This Runeblade is forged of the finest mithril and is a symbol\n"+
		"of the Alliance of Elves and Dwarves. Elvish runes adorn the shining\n"+
		"dwarven mined mithril. It is the fearsome weapon of choice for the\n"+
		"Elite Elven Guards of the Upper Flet, protectors of the Elven King.\n\n"+
		"If you were smart, you would not use this weapon against a member of\n"+
		"the Alliance.\n");
	set_weight(2);
	set_class(17);
	set_value(600+random(400));
	set_alias("blade");
	set_hit_func(this_object());
}
weapon_hit(attacker) {
int number;
if(attacker->query_race() == "elf" || attacker->query_race() == "dwarf") {
	write("The Runeblade lashes out against you in fury.\n");
	write(BOLD+BLUE+"Elven F L A M E"+END+" lashes out against you for attacking"+
		" a member of the Alliance.\n");
	this_player()->hit_player(10+random(10));
	return;
}

if(TPS < 10) {
	return;
}

number = random(10);
if(number <3) {
	this_player()->add_sp(-5-random(6));
	write("The runes glow bright blue on your Elvish blade.\n");
	tell_room(environment(this_player()),"The runes on "+TPN+"'s blade begin to "+
		BOLD+BLUE+"glow.\n");
	write("A "+BOLD+BLUE+"blue flame licks out at "+ATTN+".\n");
	tell_room(environment(this_player()),"A "+BOLD+BLUE+"flame"+END+" leaps out at "+
		ATTN+" from "+TPN+"'s Runeblade.\n");
	tell_object(attacker, "You are hit by "+BOLD+BLUE+"Elvish F L A M E"+END+"!\n");
	write("You hit "+ATTN+" with "+BOLD+BLUE+"Elvish F L A M E"+END+"!\n");
 5+random(10);
}
if(number == 9) {
	this_player()->hit_player(5);
	write("The Runeblade glows red-hot and burns you in the process.\n");
	return;
}
}
