#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
#define POS query_possessive()

static int done3n, dtwo3n;
static string hit3;
static string part3;
static int done1n, dtwo1n;
static string hit1;
static string part1;
static int done2n, dtwo2n;
static string part2n;
static defense_bonus;
string shapetype;
int sp,mp,msp;
object webbed;
object remember;
int hyper_mode;
int bdelay;
string symb_name;
int base_wc,base_ac;


reset(arg)  {
	::reset(arg);
	if(arg) return;
	set_name("symbiote");
	set_race("symbiote");
	set_level(1);
	set_al(-1000);	
	set_hp(10);
	set_wc(1);
	set_ac(1);
	
	set_heart_beat(1);
	set_dead_ob(this_object());
	message_hit=({
			""+HIR+"D E S T R O Y E D"+NORM+"", " with a frenzy of attacks",
			""+RED+"Mutilated"+NORM+"", "'s body into bloody ribbons",
			""+HIW+"Destroyed"+NORM+"", " with an onslaught of blows",
			""+HIW+"Massacred"+NORM+""," into small fragments",
			""+RED+"Slammed"+NORM+""," into the ground with bone shattering force",
			""+HIW+"Smashed"+NORM+""," with a bone crushing sound",
			""+HIW+"Hit"+NORM+""," very hard",
			""+HIW+"Hit"+NORM+""," hard",
			""+HIW+"Hit"+NORM+"","",
			""+HIW+"Grazed"+NORM+"","",
			""+HIW+"Tickled"+NORM+""," in the stomach",
	});
	
}


set_mp(int i){ mp = i; }
set_sp(int i){ if(!msp) msp = i; sp = i; }


webslam(i){
	int damage;
	if(i){
		damage = random(35) + 10;
	}
	else damage = random(11) + 10;
	
	tell_room(environment(),
		"A stream of "+HIW+"webs"+NORM+" shoots out from "+capitalize(symb_name)+"'s hands.\n"+
	"The stream of "+HIW+"web"+NORM+" hits "+attacker_ob->query_name()+" in the chest.\n");
	if(damage > 33){
		tell_room(environment(),
		capitalize(symb_name)+" spins "+attacker_ob->query_name()+" overhead "+HIR+"S L A M M I N G"+NORM+" them off of the ground.\n");
	}
	else if(damage > 28){
		tell_room(environment(),
		capitalize(symb_name)+" spins "+attacker_ob->query_name()+" about "+HIR+"Pounding"+NORM+" them against the ground.\n");
	}
	else if(damage > 20){
		tell_room(environment(),
		capitalize(symb_name)+" flips "+attacker_ob->query_name()+" over it's shoulder, "+RED+"Driving"+NORM+" them to the ground.\n");
	}
	else if(damage > 15){
		tell_room(environment(),
		capitalize(symb_name)+" sends "+attacker_ob->query_name()+" flying through the air and landing with a dull thud.\n");
	}
	else if(damage > 10){
		tell_room(environment(),
		capitalize(symb_name)+" throws "+attacker_ob->query_name()+", sending them "+(random(40) + 10)+" feet across the room.\n");
	}
	else{
		tell_room(environment(),
		capitalize(symb_name)+" slings "+attacker_ob->query_name()+", sending them bouncing across the floor.\n");
	}
	attacker_ob->hit_player(damage);
	
}

heart_beat(){
	::heart_beat();
	
	if(attacker_ob && !remember){
		remember = attacker_ob;
	}
	
	if(!attacker_ob && remember){
		attacker_ob = remember;
	}
	
	weapon_class = base_wc;
	armor_class = base_ac;
	
	if(sp < msp) sp += 2;
	
	if(sp > 15 && attacker_ob){
		if(sp > 50 && vlvl >= 15){
			webslam(1);
			sp -= 50;
		}
		else if(vlvl > 6){
			webslam();
			sp -= 15;
		}
	}
	if(random(100) < 5 && sp > 40 && attacker_ob && !webbed &&
		vlvl >= 14){
		tell_object(attacker_ob,
			BOLD+"\n\n"+capitalize(symb_name)+" stretches out it's hand...\n"+
		"A thick webbing flies from it and covers you!"+NORM+"\n\n");
		webbed = attacker_ob;
		sp -= 40;
	}
	if(sp > 50 && !hyper_mode && attacker_ob &&
		vlvl > 19){
		hyper_mode += 30 + random(40);
		tell_room(environment(),
			"\n"+capitalize(symb_name)+" yells...\n\n\n"+
		BOLD+"          - --- ---------- - - "+NORM+HIR+"H Y P E R M O D E"+NORM+BOLD+" --------- --- -- -"+NORM+"\n\n\n");
		sp -= 50;
	}
	
	if(attacker_ob){
		weapon_class += proficiency_hit();
		armor_class += venom_defense();
	}
	/* FINISHER - Fear it! */
	if(attacker_ob && attacker_ob->query_hp() < 50){
		if((attacker_ob->query_hp()*10)/(attacker_ob->query_mhp()) < 1){
			if(random(100) < 80){
				tell_room(environment(),
					"<"+HIG+"devour"+NORM+"> "+query_name()+"'s symbiotic mouth elongates to a massives size.\n"+
				"         "+query_name()+"'s razor like teeth begin its decent...\n");
				tell_room(environment(),
				"         "+attacker_ob->query_name()+"'s headless body drops lifelessly to the ground.\n");
			}
			else{
				tell_room(environment(),
					"<"+HIG+"eviscerate"+NORM+"> A horde of tentacles lash out from "+query_name()+".\n"+
				"             "+attacker_ob->query_name()+" decides to run but its far too late.\n");
				tell_room(environment(),
					"             You can see "+attacker_ob->query_name()+"'s eyes stare blankly at the inevitable...\n"+
				"             "+attacker_ob->query_name()+" groans in pain as it is ripped limb from limb.\n");
			}
			if(attacker_ob->is_npc())
			attacker_ob->heal_self(-(attacker_ob->query_hp()));
			else attacker_ob->add_hit_point(-(attacker_ob->query_hp()));
			attacker_ob->hit_player(300);
			return 1;
		}
	}
}


short(){ if(symb_name) return BOLD+capitalize(symb_name)+"   ("+NORM+HIR+" Symbiote "+NORM+BOLD+")"+NORM;
	return BOLD+"A Symbiote"+NORM;
}

long(){
	write(
		"  This is the "+BOLD+"Dark Matter"+NORM+" Symbiote "+capitalize(symb_name)+".\n"+
		"It is a Symbiotic Being that has taken over a host and now\n"+
		"controls it for combat and domination of new beings.  It is\n"+
	"an evil creation that is ruled by a far more powerful being.\n");
	return 1;
}

set_wc(int i){ if(!base_wc) base_wc = i; weapon_class = i; }
set_ac(int i){ if(!base_ac) base_ac = i; armor_class = i; }


set_symb_name(str){ symb_name = str; }
query_symb_name(){ return symb_name; }


slamtwo(){
	int damageone;
	
	if(random(100) < 60){
		tell_object(attacker_ob,
			"<"+HIR+"slam"+NORM+"> "+capitalize(symb_name)+" grab's you and tosses you through the air.\n"+
		"You scream as you collide with the ground!\n");
		damageone = 10;
	}
	else{
		tell_object(attacker_ob,
			capitalize(symb_name)+" grab's you by the leg.\n"+
			"You see a blur as your are spun around and around.\n"+
		"You fly through the air landing with a solid THUD!\n");
		damageone = 15;
	}
	
	return damageone;
}


bitetwo(){
	int damageone;
	
	random_part2n();
	
	tell_object(attacker_ob,
	"<"+HIR+"bite"+NORM+"> A tentacle lashes out at you from "+capitalize(symb_name)+". Flesh is devoured.\n");
	dtwo2n = 3;
	
	damageone = done2n + dtwo2n;
	if(hit_point < 900){
		hit_point += random(2)+1;
	}
	return damageone;
}


clawstwo(){
	int damageone;
	
	random_part1n();
	random_hit1n();
	
	tell_object(attacker_ob,
	"<"+HIR+"claw"+NORM+"> "+capitalize(symb_name)+" "+hit1+" you in the "+part1+".\n");
	damageone = done1n + dtwo1n;
	return damageone;
}


kicktwo(){
	int damageone;
	
	
	random_part32n();
	random_hit32n();
	
	tell_object(attacker_ob,
	"<"+HIR+"kick"+NORM+"> "+capitalize(symb_name)+" "+hit3+"'s you in the "+part3+".\n");
	damageone = done3n + dtwo3n;
	
	return damageone;
}




random_hit32n(){
	switch(random(5) + 1){
		case 4..5:
		hit3 = "slam";
		dtwo3n = 2;
		break;
		case 1..3:
		hit3 = "kick";
		dtwo3n = 1;
		break;
		default:
		hit3 = "kick";
		dtwo3n = 1;
		break;
	}
}
random_part32n(){
	switch(random(20) + 1){
		case 19..20:
		part3 = "face";
		done3n = 2;
		break;
		case 17..18:
		part3 = "chest";
		done3n = 2;
		break;
		case 11..16:
		part3 = "arm";
		done3n = 2;
		break;
		case 6..10:
		part3 = "leg";
		done3n = 1;
		break;
		case 1..5:
		part3 = "hand";
		done3n = 1;
		break;
		default:
		part3 = "hand";
		done3n = 0;
		break;
	}
}




random_hit1n(){
	switch(random(10) + 1){
		case 8..10:
		hit1 = "ripped";
		dtwo1n = 3;
		break;
		case 5..7:
		hit1 = "slashed";
		dtwo1n = 2;
		break;
		case 1..4:
		hit1 = "grazed";
		dtwo1n = 1;
		break;
		default:
		hit1 = "miss";
		dtwo1n = 0;
		break;
	}
}

random_part1n(){
	switch(random(20) + 1){
		case 19..20:
		part1 = "face";
		done1n = 3;
		break;
		case 15..18:
		part1 = "chest";
		done1n = 3;
		break;
		case 13..14:
		part1 = "arm";
		done1n = 2;
		break;
		case 8..12:
		part1 = "leg";
		done1n = 2;
		break;
		case 1..7:
		part1 = "hand";
		done1n = 1;
		break;
		default:
		part1 = "hand";
		done1n = 0;
		break;
	}
}


random_part2n(){
	switch(random(20) + 1){
		case 19..20:
		part2n = "face";
		done2n = 3;
		break;
		case 16..18:
		part2n = "chest";
		done2n = 3;
		break;
		case 11..15:
		part2n = "arm";
		done2n = 2;
		break;
		case 6..10:
		part2n = "leg";
		done2n = 1;
		break;
		case 1..5:
		part2n = "hand";
		done2n = 0;
		break;
		default:
		part2n = "hand";
		done2n = 1;
		break;
	}
}

venom_defense(){
	int def;
	def = random(120);
	defense_bonus = 0;
	if(!attacker_ob) return 0;
	if(def > 85){
		tell_room(environment(),
			"Tentacles lash out from "+capitalize(symb_name)+".\n"+
			""+attacker_ob->query_name()+" fights for control of "+attacker_ob->POS+" weapon.\n"+
		""+attacker_ob->query_name()+" is slowly over powered.\n");
		defense_bonus = 14;
	}
	else if(def > 64){
		tell_room(environment(),
			capitalize(symb_name)+" headbutts the on coming attack.\n"+
			capitalize(symb_name)+" screeches in ecstasy.\n"+
		""+attacker_ob->query_name()+" cringes.\n");
		defense_bonus = 4;
		
	}
	else if(def > 55){
		tell_room(environment(),
		capitalize(symb_name)+" smacks the attack aside.\n");
		defense_bonus = 3;
		
	}
	else if(def > 35){
		tell_room(environment(),
		capitalize(symb_name)+" tenses up absorbing most of the impact.\n");
		defense_bonus = 2;
		
	}
	else if(def > 5){
		tell_room(environment(),
		capitalize(symb_name)+" leaps aside.\n");
		defense_bonus = 1;
	}
	return defense_bonus;
}


proficiency_hit(ob){
	
	string mess1,mess11,mess2,mess22;
	int base;
	int dam1, dam2, dam3, dam4;
	int rand1, rand2, rand3, rand4;
	int weptype;
	int damage_bonus;
	dam1 = 0;
	dam2 = 0;
	dam3 = 0;
	dam4 = 0;
	rand1 = random(100);
	rand2 = random(100);
	rand3 = random(100);
	rand4 = random(100);
	weptype = random(4);
	base = random(21);
	if(base < 16) base = 16;
	
	
	if(!weptype){
		switch(random(10)){
			case 7..100:
			mess1 = "slash";
			mess11 = "slashes";
			break;
			case 4..6:
			mess1 = "stab";
			mess11 = "stabs";
			break;
			case 1..3:
			mess1 = "slice";
			mess11 = "slices";
			break;
			default:
			mess1 = "stab";
			mess11 = "stabs";
			break;
		}
	}
	else if(weptype == 1){
		switch(random(10)){
			case 7..100:
			mess1 = "smash";
			mess11 = "smashes";
			break;
			case 4..6:
			mess1 = "slam";
			mess11 = "slams";
			break;
			case 1..3:
			mess1 = "hit";
			mess11 = "hits";
			break;
			default:
			mess1 = "hit";
			mess11 = "hits";
			break;
		}
	}
	else if(weptype == 2){
		switch(random(10)){
			case 7..100:
			mess1 = "stab";
			mess11 = "stabs";
			break;
			case 4..6:
			mess1 = "impale";
			mess11 = "impales";
			break;
			case 1..3:
			mess1 = "thrust";
			mess11 = "impales";
			break;
			default:
			mess1 = "impale";
			mess11 = "impales";
			break;
		}
	}
	else if(weptype == 3){
		switch(random(10)){
			case 7..100:
			mess1 = "chop";
			mess11 = "chops";
			break;
			case 4..6:
			mess1 = "cleave";
			mess11 = "cleaves";
			break;
			case 1..3:
			mess1 = "slash";
			mess11 = "slashes";
			break;
			default:
			mess1 = "slash";
			mess11 = "slashes";
			break;
		}
	}
	
	
	switch(random(10)){
		case 7..100:
		mess2 = "chest";
		break;
		case 4..6:
		mess2 = "arm";
		break;
		case 1..3:
		mess2 = "leg";
		break;
		default:
		mess2 = "arm";
		break;
	}
	
	if(weptype == 0) shapetype = "Sword";
	else if(weptype == 1) shapetype = "Maul";
	else if(weptype == 2) shapetype = "Spear";
	else if(weptype == 3) shapetype = "Axe";
	
	if(mess1 && mess2 && attacker_ob){
		tell_room(environment(),
		query_name()+" "+mess11+" "+attacker_ob->query_name()+" in the "+mess2+" with his "+shapetype+" arm!\n");
		base += random(5) + 6;
	}
	
	
	if(rand1 < 21){
		dam1 = slamtwo();
	}
	else if(rand1 < 45){
		dam1 = bitetwo();
	}
	else if(rand1 < 50){
		dam1 = kicktwo();
	}
	else if(rand1 < 70){
		dam1 = clawstwo();
	}
	
	if(rand2 < 45){
		dam2 = bitetwo();
	}
	else if(rand2 < 55){
		dam2 = kicktwo();
	}
	else if(rand2 < 75){
		dam2 = clawstwo();
	}
	else{ dam2 = 0; }
	
	if(hyper_mode){
		if(rand3 < 30){
			dam3 = slamtwo();
		}
		else if(rand3 < 60){
			dam3 = bitetwo();
		}
		else if(rand3 < 80){
			dam3 = kicktwo();
		}
		else if(rand3 < 95){
			dam3 = clawstwo();
		}
		
		if(rand4 < 30){
			dam4 = slamtwo();
		}
		else if(rand4 < 60){
			dam4 = clawstwo();
		}
		else if(rand4 < 80){
			dam4 = bitetwo();
		}
		else if(rand4 < 95){
			dam4 = kicktwo();
		}
		base += 10;
	}
	damage_bonus = dam1 + dam2 + dam3 + dam4;
	
	if(webbed && !present(webbed, environment())){
		webbed = 0;
	}
	if(webbed && present(webbed, environment())){
		base += random(10) + 5;
		tell_object(webbed,
		HIR+"You struggle in the webbing!"+NORM+"\n");
	}
	if(damage_bonus > 0){
		
		base += damage_bonus;
	}
	return base;
}


query_message_hit(tmp) {
	string *mess;
	
	if (tmp > 55) {
		mess = ({message_hit[1],message_hit[0]});
	}
	else if (tmp > 45){
		mess = ({message_hit[3],message_hit[2]});
	}
	else if (tmp > 35){
		mess = ({message_hit[5],message_hit[4]});
	}
	else if (tmp > 30) {
		mess = ({message_hit[7],message_hit[6]});
	}
	else if (tmp > 25) {
		mess = ({message_hit[9],message_hit[8]});
	}
	else if (tmp > 20) {
		mess = ({message_hit[11],message_hit[10]});
	}
	else if (tmp > 10) {
		mess = ({message_hit[13],message_hit[12]});
	}
	else if (tmp > 5) {
		mess = ({message_hit[15],message_hit[14]});
	}
	else if (tmp > 3) {
		mess = ({message_hit[17],message_hit[16]});
	}
	else if (tmp > 1) {
		mess = ({message_hit[19],message_hit[18]});
	}
	else if (tmp == 1){
		mess = ({message_hit[21],message_hit[20]});
	}
	
	return mess;
}


