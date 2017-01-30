/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	eg_scimitar.c
=-=
=-=	An Elven Guard's Scimitar
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/* Fixed color bleed : Dragnar 11/29/99 */
inherit "/obj/weapon";
#include "/players/pain/color.h"
#define TPN this_player()->query_name()
#define TPR environment(this_player())


reset() {
	set_short("An "+BOLD+GREEN+"Elven"+END+" Scimitar");
	set_long("This scimitar is forged of the finest steel and is made exclusively\n"+
		"for the "+BOLD+GREEN+"Elven Guards of the Vale"+END+". It's blade is adorned\n"+
		"with runes and it has been ground to a razor sharp edge.\n");
	set_weight(2);
	set_class(15);
	set_value(500+random(400));
	set_alias("scimitar");
	set_hit_func(this_object());
}
weapon_hit(attacker) {
int number;

number = random(10);
if(number <3) {
	write("The Elven Scimitar begins to hum!\n\n");
	tell_room(TPR,TPN+"'s Elven Scimitar begins to hum!\n");
	write(BOLD+GREEN+"The Scimitar lashes out against your enemy"+END+".\n");
    tell_room(TPR,BOLD+GREEN+TPN+"'s Scimitar lashes out against "+
            attacker->query_name()+END+".\n");
	tell_object(attacker,TPN+"'s scimitar slashes across your chest.\n\n"+
			"\t\t\t"+BOLD+GREEN+"S L I C E !"+END+"\n");
	write("Your scimitar slashes across your enemy's chest.\n"+
		"\t\t\t"+BOLD+GREEN+"S L I C E !"+END+"\n");
	return 3+random(3);
}
}
