/*  Symbiotic Slave Pet - 6th level Creation Power.
This is just an object, not a monster, and does not
attack every round as most pets do. Instead, a
Hit_player() is called within the Guild Object on about
a 26% chance per round...at best.  The pet can and
will die. It does not heal like Wolves and Mechs.
It is bigger than other pets, but is more limited.
Look at it!
Yes, you!
ok.
*/

#include "/players/maledicta/ansi.h"
#define ATTACKER owner->query_attack()
int countdown;
string name,short,race,gender,nowner;
object owner;
int health,wc,ac,max_health;

id(str) { if(stringp(name) && str == lower_case(name)) return 1; return (str == "venom_pet" || str == "pet" || str == "slave"); }

reset(arg){
 if(arg) return;
 if(!short) short = "";
 set_heart_beat(1);
 }

/* if nowner check by verte */
short()
{
    if(nowner) return short + " " + BOLD + "[" + nowner + "]'s Dark Matter Slave" + NORM;
}
long(){
	write(
		"This is the enslaved pet of "+capitalize(nowner)+".  The "+name+" has strands\n"+
		"of "+BOLD+"Dark Matter"+NORM+" covering its body in long streaks and splotches.  It's\n"+
            "eyes hold no semblance of intelligence, but instead a dull white light shines there\n"+
            "like a mechanical animal.  The "+name+"'s mind is now owned by the Darkness.\n");
	if(this_player() == owner){
		write("As the Master, you may 'destroy' this creature at any time.\n");
	}
	write("It is in "+get_condition()+" condition.\n");
	return 1;
}

heart_beat(){
if(!owner && !root()) {  /* root() check by verte */
 countdown += 1;
 if(countdown > 300) destruct(this_object());
 return;
 }
if(root()) { set_heart_beat(0); return; }
if(!present("link", owner) || owner->query_ghost()) { /* query_ghost() check by verte 6.23.01 */
 destruct(this_object());
 return;
 }

countdown = 0;

		if(!present(nowner, environment())){
			call_exit();
			move_object(this_object(), environment(owner));
			call_enter();
		}
		/******** About a 26% chance it will do an attack per round, and only against Npc's *****/
		if(owner->query_attack() &&
			random(100) < owner->query_attrib("wil") * 2 + random(6) &&
			ATTACKER->is_npc()){
			do_attack(ATTACKER);
		}
	}



get_condition(){
int heh;
heh = (health*10)/max_health;
if(heh > 9) return "perfect";
else if(heh > 7) return "very good";
else if(heh > 3) return "good";
else if(heh > 2) return "below average";
else if(heh > 1) return "bad";
else if(heh > 0) return "very bad";
else return "terrible"; 
}


set_nowner(str){ nowner = str; }
query_nowner(){ return nowner; }

set_health(int i){
	if(i > 300) i = 300;
	max_health = i;
	health = i;
}

call_exit(){ 
 tell_room(environment(), 
 name+" leaves the room following "+owner->query_name()+".\n");
 }

call_enter(){
 tell_room(environment(), 
 name+" enters the room following "+owner->query_name()+".\n");
 }


query_health(){ return health; }
set_owner(object ob){ owner = ob; }
query_owner(){ return owner; }
set_name(str){ name = str; }
query_name(){ return name; }
set_wc(int i){
	if(i > 30) i = 30;
	wc = i;
}
set_ac(int i){
	if(i > 20) i = 20;
	ac = i;
}
query_wc(){ return wc; }
query_ac(){ return ac; }
set_short(str){ short = str; }
query_short(){ return short; }


do_attack(object attacker){
	int damage;
	string where,how,boo;
	
	if(!attacker) return;
	if(!present(attacker, environment())) return;
   if(!owner) return;
	if(attacker != owner->query_attack()) return;
	if(!present(owner, environment())) return;
	tell_room(environment(),
	capitalize(name)+" charges forward to attack "+capitalize(attacker->query_name())+"!\n");
	damage = random(wc) + 1;
	if(attacker->query_hp() < damage){
		tell_object(owner, capitalize(name)+" circles and waits for you to finish "+attacker->query_name()+".\n");
		return;
	}
	switch(damage){
		case 30..10000: how = HIR+"D E V A S T A T E D"+NORM; break;
		case 25..29: how = "Massacred"; break;
		case 21..24:       how = "Butchered"; break;
		case 17..20:       how = "Smashed"; break;
		case 12..16:       how = "Struck"; break;
		case 7..11:         how = "Hit"; break;
		case 3..6:           how = "Grazed"; break;
		case 1..2:           how = "Knicked"; break;
	}
	switch(random(5) + 1){
		case 5:  where = "head"; break;
		case 4:  where = "chest"; break;
		case 3:  where = "leg"; break;
		case 2:  where = "arm"; break;
		case 1:  where = "shoulder"; break;
	}
	
	switch(random(5) + 1){
		case 5: boo = "with a Tendril slash"; break;
		case 4: boo = "raking "+BOLD+"Dark Matter"+NORM+" claw"; break;
		case 3: boo = "running strike"; break;
		case 2: boo = "lashing tenticle"; break;
		case 1: boo = "combo slash and claw"; break;
	}
	
	tell_object(owner,
	HIR+"(SLAVE)"+NORM+" "+capitalize(name)+" "+how+" "+attacker->query_name()+" in the "+where+" with a "+boo+".\n");
	tell_room(environment(),
	capitalize(name)+" "+how+" "+attacker->query_name()+" in the "+where+" with a "+boo+".\n", ({ owner }));
	attacker->heal_self(-damage);
	if(random(owner->query_attrib("wil") + ac) < random(attacker->query_wc())){
		tell_room(environment(),
		capitalize(name)+" is struck by "+attacker->query_name()+" as it attacks!\n");
		hurt_this(attacker->query_wc());
	}
	else{
		tell_room(environment(),
		capitalize(name)+" dodges the side attack of "+attacker->query_name()+"!\n");
	}
	return;
}

hurt_this(int i){
	if(!i) return;
	health -= random(i);
	if(health < 0){
		tell_room(environment(),
		capitalize(name)+" is killed!\n");
		if(present("venom_drag_object", owner)){
			present("venom_drag_object", owner)->set_pet(0);
		}
		destruct(this_object());
		return 1;
	}
	tell_object(owner,
		"("+HIG+"Slave Health"+NORM+")  "+
	HIG+(health*100)/max_health+"%"+NORM+"\n");
	return;
}

get(){ return 0; }

query_weight(){ return 100000; }
query_value(){ return 0; }

is_pet(){ return 1; }

init(){
	add_action("dest_this", "destroy");
}

dest_this(str){
	if(!id(str)) return;
	if(this_player() != owner) return;
	tell_room(environment(this_player()),
		this_player()->query_name()+" points at "+capitalize(name)+"...\n"+
		BOLD+"Dark Matter"+NORM+" rises from its body in tendrils and reunites with "+this_player()->query_name()+".\n"+
	"The body disintegrates before your eyes.\n", ({ this_player() }));
	tell_object(this_player(),
		"You point at "+capitalize(name)+"...\n"+
		BOLD+"Dark Matter"+NORM+" rises from it in tendrils and reunites with your own body.\n"+
	"Your slave disappears in a lump of bubbling deterioration.\n");
	destruct(this_object());
	return 1;
}
query_save_flag(){ return 1; }
