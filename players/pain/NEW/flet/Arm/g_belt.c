/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	Filename: g_belt.c
=-=
=-=	Belt of Giant Strength
=-=
=-=	This is a quest item that alters the strength
=-=	of the player wearing it. Since the player's
=-=	strength gets agumented, there are some drawbacks:
=-=	the player's stl, luc and mag all get lowered
=-=	while the belt is worn.
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/armor";
#include "/players/pain/color.h"
#define WB worn_by
#define TP this_player()
#define TPS this_player()->query_attrib("str")
#define TPST this_player()->query_attrib("stl")
#define TPL this_player()->query_attrib("luc")
#define TPM this_player()->query_attrib("mag")

int changed;

reset() {
	set_short("A finely crafted "+BLUE+"belt"+END);
	set_long("This belt was forged many years ago in the dwarvish caverns\n"+
		"north of what is now Bigelow. It is rumored that those who wear\n"+
		"this belt gain the strength of giants long forgotten. The well\n"+
		"worn leather shines with life, and the thick padding looks quite\n"+
		"comfortable. As you prepare to wear the belt, you wonder if the\n"+
		"legends are true.\n");
	set_alias("belt");
	set_name("belt");
	set_type("misc");
	set_ac(3);
	set_weight(4);
	set_value(1000000);
}

init() {
	::init();
	add_action("check_wear","wear");
}

check_wear(str) {

	if(!str || str != "belt") { return 0; }
	if(TP->query_level() < 15) {
		write("You wrap the belt around your waist and wait for something to happen.\n"+
			"You feel well armored, but no stronger, perhaps this will change as\n"+
			"you gain in levels.\n");
		::wear(str);
		return 1;
	}
	changed = 1;
	this_player()->raise_magic_aptitude(-9);
	this_player()->raise_luck(-9);
	this_player()->raise_stealth(-9);
	this_player()->raise_strength(18);
	write("As you don the belt you feel "+RED+"strength and vigor"+END+" rush through you.\n"+
		"After the initial feeling passes you notice that you feel less lucky,\n"+
		"a little clumsier and less magically inclined.\n");
	::wear(str);
	call_out("health",100);
	call_out("hurt",100);
	return 1;
}

remove(str) {
    if (!id(str))
        return 0;
    if (!worn) {
        return 0;
    }
    call_other(worn_by, "stop_wearing",name);
    if(changed = 1) {
	changed = 0;
        this_player()->raise_magic_aptitude(9);
        this_player()->raise_luck(9);
        this_player()->raise_stealth(9);
        this_player()->raise_strength(-18);
   }
    worn_by = 0;
    worn = 0;
    return 1;
}

health() {
	if(WB->query_attack()) {	
		write(BLUE+"The belt fills you with a renewed vigor and strength, healing you\n"+
			"slightly so that you can continue the fight."+END+"\n");
		WB->add_hp(random(5));
		call_out("health",20);
		call_out("hurt",15);
		return 1;
	}
	call_out("health",20);
	return 1;
}
		
hurt() {
object ob;
int damage;
	if(WB->query_attack()) {
		ob = WB->query_attacker();
		if(present(ob,environment(TP))) {
			write(RED+"The belt gives you a burst of extra strength and you hit your opponent\n"+
				"a little harder."+END+"\n");
			damage = random(8);
			ob->hit_player(damage);
			TP->add_sp((-5*damage)/3);
			call_out("hurt",15);
			return 1;
		}
		return 1;
	}
	return 1;
}

drop(silently) {
    if (worn) {
        call_other(worn_by, "stop_wearing", name);
	if(changed == 1) {
	changed = 0;
        this_player()->raise_magic_aptitude(9);
        this_player()->raise_luck(9);
        this_player()->raise_stealth(9);
        this_player()->raise_strength(-18);
	}
        worn = 0;
        worn_by = 0;
        if (!silently)
            tell_object(environment(this_object()),"You drop your worn armor.\n"
);
    }
    return 0;
}

