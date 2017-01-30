/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	Winged Elven Helm
=-=
=-=	This helm provides the wearer with extra protection
=-=	from blows to the head. It can only be received if
=-=	a player brings Deathbringer's helm to the Elven lord 
=-=	in exchange. The helm acts as a light source and heals the
=-=	player periodically while in combat. It is very unique, and
=-=	can only be gotten by fighting all the wave through the orc
=-=	caves and the Elven flet. Since it is so difficult to get
=-=	and it is a part of my quest, I am going to make it saveable.
=-=	Also, I am going to make it so that it is rather fragile and
=-=	will need to be repaired after it breaks.
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/armor";
#include "/players/pain/color.h"
#define WB worn_by

int count;

set_count(str) { count = str; }
query_count() { return count; }

reset() {
	set_short("A Winged Elven "+BOLD+GREEN+"Helm"+END);
	set_long("A beautiful helm, mithril over leather. It has a high crest and\n"+
		"wings to deflect damage to your head. It looks quite regal, almost\n"+
		"like something a king would wear. Although it is mithril, you are\n"+
		"sure that you will need to keep this helm in good repair in order for\n"+
		"it to serve you as well as you will need it to. As you stare at it, you\n"+
		"are sure that this treasure is unique throughout Nirvana and vow to\n"+
		"protect it with your life. Such a treasure as this could bring destruction\n"+
		"to your foes, or to the Elvish Lords should you lose it.\n");
	set_weight(2);
	set_ac(2);
	set_value(1000000);
	set_type("helmet");
	set_alias("helm");
	set_name("helm");
	call_out("health",100);
}

init() {
	::init();
}

health() {
	if(count > 50 && WB->query_attack()) {
		tell_object(WB, BOLD+RED+"The helm glows brightly, but has lost its healing powers."+END+"\n"+
			"Perhaps you should see about having it repaired.\n");
			return 1;
	}
	if(count < 51 && WB->query_attack()) {
		tell_object(WB, BOLD+GREEN+"The helm glows brightly and fills you "+
			"with a renewed sense of vigor."+END+"\n");
		WB->add_hp(15+random(6));
		WB->add_sp(-4);
		count++;
		call_out("health",25);
		return 1;
	}
	call_out("health",25);
	return 1;
}

