/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	eg_bow.c
=-=
=-=	An Elven Guard's Bow
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/players/pain/NEW/flet/Wep/bweapon";
#include "/players/pain/color.h"
#define TPR environment(this_player())
#define TPN this_player()->query_name()

reset() {
	set_short("An "+BOLD+GREEN+"Elven"+END+" Bow");
	set_long("This Bow is made of the finest highly polished yew exclusively\n"+
		"for the "+BOLD+GREEN+"Elven Guards of the Vale"+END+". It's bowstring is finely\n"+
		"woven hair of the Elven Princesses. This is a truly valuable item\n");
	set_weight(2);
	set_class(15);
	set_value(500+random(500));
	set_alias("bow");
	set_hit_func(this_object());
}
weapon_hit(attacker) {
int number;

number = random(10);
if(number <3) {
	write("The Elven Bow begins to hum!\n\n");
	tell_room(TPR,TPN+"'s Elven Bow begins to hum!\n");
	write(BOLD+GREEN+"The Bow slams a bolt into your enemy"+END+".\n");
	tell_room(TPR,BOLD+GREEN+TPN+"'s bow slams a bolt into "+
		attacker->query_name()+".\n");
	tell_object(attacker,TPN+"'s bow fires a bolt into your abdomen.\n\n"+
			"\t\t\t"+BOLD+GREEN+"T H U N K !"+END+"\n");
	write("Your bow fires a bolt into your enemy's abdomen.\n"+
		"\t\t\t"+BOLD+GREEN+"T H U N K !"+END+"\n");
	return 3+random(3);
}
}
