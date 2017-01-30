/* Dark Sphere - This is an object that is created directly from Mp and Sps.
It has 4 settings.  1) Heal - Mp put in gives 25 heal_self
2) Attack - Mp put in gives damage: 12 + r(25)
3) Bind - Will allow someone to 'web' a mob
4) Transfer - Lets Mp pass to another Symb.  50 gives 35
It requires 50 MP and 50 sps to create a sphere of any type.
*/
inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define USER this_player()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()

string who,type_of;

id(str){ return str == "sphere" || str == "creation_ball"; }
short() { return BOLD+"Dark Matter Sphere  ["+NORM+type_of+BOLD+"]"+NORM; }
long(){
	write(
		"This is a smooth sphere that is as hard as stone yet lightweight. It is\n"+
		"warm to the touch and you almost feel as though it is living.  You can\n"+
		"'grasp' it at any time to inact its power. \n"+
	"This "+BOLD+"Dark Matter Sphere"+NORM+" was created by "+who+"\n");
}

reset(arg){
      if(arg) return;
	call_out("destroy_this", 3600);
}

destroy_this(){
        /* by verte. 7.7.01 */
        if(root() || !environment()) return;
	if(living(environment())){
		tell_object(environment(),
		"The sphere disintegrates as it dies...\n");
                destruct(this_object());
		return 1;
	}
	else{
		destruct(this_object());
		return 1;
	}
	return 1;
}

query_value(){ return 100; }
query_save_flag(){ return 1; }

set_type_of(str){ type_of = str; }
set_who(str){ who = str; }
query_who(){ return who; }
query_type_of(){ return type_of; }


init(){
	add_action("use_sphere", "grasp");
}

use_sphere(str){
	object target,web;
	string msg,msg2,msg3;
	int damage,spamount;
	
	if(this_player()->query_ghost()) return;
	if(environment() != this_player()) return;
	if(!str || str != "sphere"){ write("grasp what?\n"); return 1; }
	if(type_of == "Heal"){
		write("You grasp the Healing Sphere of "+BOLD+"Dark Matter..."+NORM+"\n");
		this_player()->heal_self(25);
		write("It softens and enters your body.  There it winds through your bloodstream and\n"+
		"repairs your wounds.\n");
		write(HIG); command("mon", this_player());  write(NORM);
		destruct(this_object());
		this_player()->recalc_carry();
		return 1;
	}
	else if(type_of == "Attack"){
		if(this_player()->query_spell_dam()){ write("You are already casting!\n");  return 1; }
		if(!this_player()->query_attack()){
			write("You are not fighting!\n");
			return 1;
		}
		damage = 12 + random(25);
		target = this_player()->query_attack();
		tell_room(environment(this_player()),
			this_player()->query_name()+" grasps a "+BOLD+"Dark Sphere..."+NORM+"\n"+
		"The Sphere erupts into motion as it launches into "+ATTN+" and "+HIR+"Impales"+NORM+" them!\n", ({USER}));
		tell_object(USER,
			"You grasp the Dark Matter Sphere...\n"+
			"The Sphere vibrates as it suddenly launches into the air and forms into a Spear!\n"+
		ATTN+" is   "+BOLD+"-------  - --    --- -  "+HIR+"I M P A L E D"+NORM+BOLD+"  -  -    --  -      -   -"+NORM+"\n");
		ATT->hit_player(damage);
      destruct(this_object());
		this_player()->recalc_carry();
		return 1;
	}
	else if(type_of == "Bind"){
		if(!USER->query_attack()){
			write("You must be in combat!\n");
			return 1;
		}
		target = ATT;
		if(target->is_living() && !target->query_npc()){
			write("You cannot cast this on players!\n");
			return 1;
		}
		if(target->webbed()){
			tell_object(USER, "You cannot web "+target->query_name()+" again!\n");
			return 1;
		}
		if(random(100) > 80){
			tell_object(USER,
				"You hold the "+BOLD+"Dark Matter Sphere"+NORM+" before you...\n"+
			"The Sphere attempts to bind "+target->query_name()+", but misses!\n");
			destruct(this_object());
			this_player()->recalc_carry();
			return 1;
		}
		tell_room(environment(USER),
			USER->query_name()+" holds up a "+BOLD+"Dark Sphere..."+NORM+"\n"+
		"It flies from their hand and slams into "+ATTN+", trapping them in black webs!\n", ({USER}));
		tell_object(USER,
			"You hold the "+BOLD+"Dark Matter Sphere"+NORM+" before you...\n"+
		"A stream of "+HIW+"webs"+NORM+" fly from the Sphere covering "+target->query_name()+"!\n");
		web = clone_object("/players/maledicta/venom/OBJ/webbing.c");
		web->set_time(40 + random(40));
		web->web_person(target);
		destruct(this_object());
		USER->recalc_carry();
		return 1;
	}
	else if(type_of == "Transfer"){
		if(!present("venom_object", this_player())){
			write("You cannot figure out what to do with it.\n");
			return 1;
		}
		tell_object(USER,
			"You grasp the Dark Matter Sphere...\n"+
		"It dissolves in your hand and you feel a flow of power enter your body.\n");
		present("venom_object", this_player())->add_mp(35);
		command("mp", this_player());
		destruct(this_object());
		USER->recalc_carry();
		return 1;
	}
	else{   write("Error: Report this.\n"); destruct(this_object());  USER->recalc_carry(); return 1; }
	return 1;
}



query_weight(){ return 1; }
