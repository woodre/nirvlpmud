/* This sword is gained by completing the Elemental Test at extreme risk of death
 * if this weapon seems powerful for that, please try out the test. - Snow
 * changed everything to Damage Types [5.25.01] Vertebraker
 *
 * Updated by Oberon 10.17.16
 * - Merged all elemental weapons into one location.
*/
inherit "/obj/weapon.c";
#include "/players/snow/closed/color.h"
#define ELE		RED+"~ "+OFF+BLUE+"Ele"+OFF+GREEN+"men"+OFF+BOLD+"tal "
#define WEP		"We"+OFF+GREEN+"ap"+OFF+BLUE+"on"+OFF+RED+" ~"+OFF
#define AXE		"Bat"+OFF+GREEN+"tle"+OFF+BLUE+"axe"+OFF+RED+" ~"+OFF
#define DAGGER	"War"+OFF+GREEN+"Dag"+OFF+BLUE+"ger"+OFF+RED+" ~"+OFF
#define HAMMER	"War"+OFF+GREEN+"ham"+OFF+BLUE+"mer"+OFF+RED+" ~"+OFF
#define MACE	"M"+OFF+GREEN+"ac"+OFF+BLUE+"e"+OFF+RED+" ~"+OFF
#define PIKE	"P"+OFF+GREEN+"ik"+OFF+ BLUE+"e"+OFF+RED+" ~"+OFF
#define SCEPTER	"Sc"+OFF+GREEN+"ept"+OFF+ BLUE+"er"+OFF+RED+" ~"+OFF
#define SCYTHE	"War"+OFF+GREEN+"Scy"+OFF+ BLUE+"the"+OFF+RED+" ~"+OFF
#define SPEAR	"Hal"+OFF+GREEN+"fSp"+OFF+ BLUE+"ear"+OFF+RED+" ~"+OFF
#define STAFF	"War"+OFF+GREEN+"sta"+OFF+BLUE+"ff"+OFF+RED+" ~"+OFF
#define SWORD	"S"+OFF+GREEN+"wo"+OFF+ BLUE+"rd"+OFF+RED+" ~"+OFF
#define WHIP	"Spi"+OFF+GREEN+"ked"+OFF+BLUE+"whip"+OFF+RED+" ~"+OFF

int smack;
string weaponDesc, type;
mapping ac_effects;

reset(arg) {
	::reset(arg);
	set_name("elemental weapon");
	set_alias("weapon");
	set_short("An Elemental Weapon");
	set_long("An Elemental Weapon");
	set_class(21);
	set_weight(2);
	set_value(10000);
	set_hit_func(this_object());
}

id(str) { return (::id(str) || str == "snow_elem_wep"); } /*added by Zeus 5/02*/
/* this allows saving the weapon to fix it if broken
query_save_flag() { return 0; }
- illarion */
query_save_flag() { return !(!broke); } /* 1 if broke, 0 if not */

weapon_hit(object ob) {
	int r;
	int dam;
	r = random(16);
	if(!ob || !environment() || !this_player() || this_player() != environment()) return;

	if(!random(20) && !ob->is_player() && ob->query_ac() > 5) {
		tell_room(environment(ob),
			"*** "+ob->query_name()+"'s defenses are weakened! ***\n");
		
		/* Changed to provent exp loss - Oberon 10.13.2016
		ob->set_ac(ob->query_ac() - 1); */
		if(!ac_effects) ac_effects=([]);
		if(ac_effects[ob]) {
			ac_effects[ob]--;
		} else {
			ac_effects[ob]=-1;
		}
		ob->RegisterArmor(this_object(),({"physical",ac_effects[ob],0,0}));
		
		return 3;
	}
	if(!r) {
		earth(ob);
		dam = (int)ob->hit_player(random(5) + 5, "other|earth");
		if(ob)
			if((int)ob->query_spell_point() > 0)
				ob->add_spell_point(-dam);
		return 3;
	}
	if(r == 1) {
		water(ob);
		dam = (int)ob->hit_player(random(8) + 1, "other|water");
		if(ob)
			if((int)ob->query_spell_point() > 0)
				ob->add_spell_point(-dam);
		return 3;
	}
	if(r == 2) {
		flame(ob);
		dam = (int)ob->hit_player(random(5) + 5, "other|fire");
		if(ob)
			if((int)ob->query_spell_point() > 0)
				ob->add_spell_point(-dam);
		return 3;
	}
	call_out("extra_hit", 3, ob);
	return;
}

earth(object ob) {
	if(!ob) return;
	tell_room(environment(ob),
		BROWN+"\n\t* * THE EARTH SHAKES!\n\n\t"+ob->query_name()+" FALLS TO THE GROUND!\n"+OFF);
	tell_object(ob, BROWN+" * * * * THE EARTH RISES TO CRUSH YOU! * * * * \n"+OFF);
	return 1;
}

water(object ob) {
	if(!ob) return;
	tell_room(environment(ob),
		BLUE+"\n\tTHE SKY GROWS DARK!\n\n\t ,', ,', HAIL CRASHES DOWN FROM THE SKY! ,', ,',\n"+
		"\n\t"+ob->query_name()+" IS PUMMELED BY THE ICE!\n"+OFF);
	tell_object(ob, BLUE+",', ,', THE HAIL SMASHES YOU DOWN! ,', ,',\n"+OFF);
	return 1;
}

flame(object ob) {
	if(!ob) return;
	tell_room(environment(ob),
		RED+"\n\tCRACKS OPEN IN THE EARTH!\n\n\tLAVA SPRAYS FORTH!\n\n\t"+
		ob->query_name()+" SCREAMS IN BURNED AGONY!\n"+OFF);
	tell_object(ob, RED+"\nHOT PAIN RIPS THROUGH YOU!\n");
	return 1;
}

extra_hit(object ob) {
	if(!ob) return;
	if(!environment()) return;
	if(environment(environment()) != environment(ob)) return;
	if(environment()->query_attack() != ob) return;
	if(ob->query_hp() < 80) return;
	tell_room(environment(ob),
		BOLD+environment(this_object())->query_name()+" blurs in a burst of speed!\n"+OFF);
	tell_room(environment(ob),
		environment(this_object())->query_name()+" impales "+ob->query_name()+" with a "+
		"vicious thrust!\n");
	ob->hit_player(class_of_weapon);
	return 1;
}

wield(str) {
	if(this_object()->id(str)) {
		if(!present("elemental aura", this_player())) {
			write("The "+this_object()->query_short()+" burns you with its power!\n");
			return 1;
		}
	}
	/* fixed by Verte 5.28.01 */
	return ::wield(str);
}

offwield_function() {
	if(!present("elemental aura", this_player())) {
		write("The "+this_object()->query_short()+" burns you with its power!\n");
		return 2;
	}
	return 0;
}

query_short() {
	switch(query_type()) {
		case "axe": return ELE+AXE; break;
		case "dagger": return ELE+DAGGER; break;
		case "hammer": return ELE+HAMMER; break;
		case "mace": return ELE+MACE; break;
		case "pike": return ELE+PIKE; break;
		case "scepter": return ELE+SCEPTER; break;
		case "scythe": return ELE+SCYTHE; break;
		case "spear": return ELE+SPEAR; break;
		case "staff": return ELE+STAFF; break;
		case "sword": return ELE+SWORD; break;
		case "whip": return ELE+WHIP; break;
		default: return ELE+WEP; break;
	}
}

long() {
	object a,b;
	write("  You see before you a legendary weapon, molded from the very elements\n"+
		  "themselves, forged by the gods of Nirvana for those mighty and worthy.\n"+
		  weaponDesc);
	if((a = this_player()) && (b = environment()) && (b == a)) {
		write("\n  You can sense a "+BLUE+"mys"+GREEN+"tic"+OFF+BOLD+"al "+OFF+GREEN+"ene"+BLUE+"rgy"+OFF+" coursing through the "+query_type()+".");
		if(present("elemental aura",environment(this_object())))
			write("  Wielded\n"+
				"with strength and purpose, this weapon will strike mighty blows when\n"+
				"wielded by one who has slayed the Five Elements.");
	}
	write("\n");
	::long();
}

/* keep the wep from lowering the exp value */
no_exp_effect() { return 1; }
