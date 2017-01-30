#include "/players/wicket/guild/defs.h"
#include <ansi.h>
inherit "/obj/monster";

object owner, target;

int monitor, stay;

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("djinn");
	set_alt_name("water");
	set_race("djinn");
	set_alias("water djinn");
	set_short("An "+HIW+"Ancient"+NORM+""+HIC+" Water Djinn"+NORM+" ("+CYN+"shrouded in mist"+NORM+")" );  
	set_level(0);
	set_hp(0);
	set_ac(0);
	set_wc(0);
	set_al(0);
	set_heal(5, 5);
	set_no_exp_value(1);
	monitor = 1;
}

long(){
	write("An ancient water djinn that is shrouded by deep power from the element of\n");
	write("water. It is made of nothing but complete water and mist and just glows with\n");
	write("immense power. It appears to pay attention to only its master for which it\n");
	write("was summoned.\n");
  if(TP == owner){
    write("Use 'ecmds' for more details.\n"); }
    if(hit_point < (max_hp/10)) {
      write("The Djinn is in very bad shape.\n"); return; }
    if(hit_point < (max_hp/5)) {
      write("The Djinn is in bad shape.\n"); return; }
    if(hit_point < (max_hp/2)) {
      write("The Djinn is somewhat hurt.\n"); return; }
    if(hit_point < (max_hp - 20)){
      write("The Djinn is slightly hurt.\n"); return;}
      write("The Djinn is in good shape.\n");
 }

init(){
	::init();
    	
	if(TP && TP == owner && !TP->query_ghost()) {
	    add_action("fight","attack");
	    add_action("dismiss", "dismiss");
	    add_action("feed","feed");
	    add_action("beckon","beckon");
	    add_action("dmon","dmon");
	    add_action("ecmds","ecmds");
  	}
}

ecmds(){
	tell_object(owner, "\n(~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~)\n");
	tell_object(owner, "				Djinn Commands\n");
	tell_object(owner, "attack		Makes your Djinn attack a mob.\n");
	tell_object(owner, "dismiss		Dismiss your Djinn.\n");
	tell_object(owner, "feed		Offer a corpse to your Djinn.\n");
	tell_object(owner, "beckon		Command your pet to stay/follow.\n");
	tell_object(owner, "dmon		Can be used to turn 'on' and 'off' or to check its health.\n");
	tell_object(owner, "(~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~)\n");
	return 1;
}

fight(str){
	if(!str && !owner->query_attack()){
		write("The Water Djinn blinks at you.\n");
		return 1;
	}
	
	if(!str && TO->query_attack()){ 
		write("The Water Djinn tells you: I'm already attacking "+TO->query_attack()->query_name()+".\n");
		return 1;
	}
	
	if(!str && owner->query_attack() && !attacker_ob && !owner->query_attack()->is_player()){
		say("The Water Djinn forms into a huge wave and crashes into  "+owner->query_attack()->query_name()+".\n");
		attacker_ob = owner->query_attack();
		return 1;
	}
	
	target = present(str, environment(TO));
	
	if(!target){
		write("The Water Djinn tells you: I don't see any "+str+" here\n");
		return 1;
	}
	
	if(target->query_npc() == 0) {
		write("The Water Djinn tells you: Kill the player on your own!\n");
		return 1;
	}
	say("The Water Djinn forms into a huge wave and crashes into "+target->query_name()+".\n");
	this_object()->attack_object(target);
	return 1;
}

dismiss(){
	object ob;
	
	ob = present("wicket_element_orb", TP);
	say("The Water Djinn bows to its audience and evaporates into the sky.\n");
	ob->set_has_djinn(0);
	ob->gsave();
	destruct(TO);
	return 1;
}

feed(){
	object ob;
	ob = present("corpse", ENV(TO));
	if(!ob){
		tell_object(owner, "The Djinn fails to find a corpse and "+HIR+"GASHES"+NORM+" your arm out of anger!\n");
		owner->hit_player(30 + random(10), "other|water");
		return 1;
	}
	say("The Djinn gains the heal_value from the corpse. Duh, dumbass.\n");
	hit_point += ob->heal_value();
	if(hit_point > max_hp) hit_point = max_hp;
	destruct(ob);
	return 1;
}


beckon(){
	if(this_object()->query_attack()){
		write("The Djinn glares at you while continuing its attack.\n");
		return 1; 
	}
	
	if(stay != 1)
	{
		say("The Djinn bows to "+owner->query_name()+" and begins to relax.\n");
		stay = 1;
		return 1;
	}
	
	if(stay == 1)
	{
		say("The Djinn nods to "+owner->query_name()+" and begins to follow.\n");
		stay = 0;
		return 1;
	}
	return 1;
}

dmon(str){

	if(!str){
		tell_object(owner, BOLD+HIC+"Water Djinn: "+HIW+((hit_point * 10)/max_hp)+" / 10"+NORM+"\n");
		return 1;
	}
	
	if(str == "on" && monitor == 1){
		write("Your pet monitor is already on.\n");
		return 1;
	}
	
	if(str == "on" && monitor != 1){
		write("You turn on your pet monitor.\n");
		monitor = 1;
		return 1;
	}
	
	if(str == "off" && monitor != 1)
	{
		write("Your pet monitor is already off.\n");
		return 1;
	}
	
	if(str == "off" && monitor == 1)
	{
		write("You turn off your pet monitor.\n");
		monitor = 0;
		return 1;
	}
}


heart_beat(){
 
	if(root()) return;
	if(!owner) return;
	::heart_beat();
	
	if(owner && stay != 1 && !owner->query_ghost()){
		if(ENV(TO) != ENV(owner)){
			say("The Water Djinn follows after it's owner, "+capitalize(owner->query_name())+".\n");
			move_object(this_object(), environment(owner));
			say("The Water Djinn flows in behind "+capitalize(owner->query_name())+".\n");
			set_heart_beat(1);
		}
		if(TO->query_attack() && monitor == 1){
			tell_object(owner, 
 			BOLD+HIY+"Water Djinn: "+HIW+((hit_point * 10)/max_hp)+" / 10"+NORM+"\n");
		} 
		if(!TO->query_attack() && owner->query_attack() && !owner->query_attack()->is_player()){
 			say("The Water Djinn forms into a huge wave and crashes into "+owner->query_attack()->query_name()+".\n");
			this_object()->attack_object(owner->query_attack());
		}
	}
}

is_pet(){ return 1; }
is_djinn() { return 1; }

patch_owner(o) { owner = o; }
