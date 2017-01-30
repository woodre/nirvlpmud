/* Dark Sphere - This is an object that is created directly from Mp and Sps.
It has 4 settings.  1) Heal - Mp put in gives 35 heal_self
2) Attack - Mp put in gives damage: 17 + r(35)
3) Bind - Will allow someone to 'web' a mob
4) Transfer - Lets Mp pass to another Symb.  50 gives 40
It requires 50 MP and 50 sps to create a sphere of any type.
*/
/* Raised most of the numbers slightly to make for more playability and balance with other guilds. For old numbers see Mal's old sphere.c file. -Chip(4-15-09)*/
inherit "obj/treasure";
#include "/players/chip/ansi.h"
#define USER this_player()
#define ATT USER->query_attack()
#define ATTN ATT->query_name()

string who,type_of;

id(str){ return str == "sphere" || str == "creation_ball"; }
short() { return HIK+"Dark Matter"+NORM+" "+BOLD+"Sphere  ["+NORM+type_of+BOLD+"]"+NORM; }
long(){
	write(
		"This is a smooth sphere that is as hard as stone yet lightweight. It is\n"+
		"warm to the touch and you almost feel as though it is living.  You can\n"+
		"'grasp' it at any time to inact its power. \n"+
	"This "+HIK+"Dark Matter"+BOLD+" Sphere"+NORM+" was created by "+who+"\n");
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
		"The sphere disintegrates as it has fulfilled its purpose...\n");
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
		write("You grasp the Healing Sphere of "+HIK+"Dark Matter..."+NORM+"\n");
		this_player()->heal_self(75);
		write(""+WHT+"It opens a hole in your flesh and enters your body. It runs through your bloodstream and"+NORM+"\n"+
		""+WHT+"repairs some of your wounds."+NORM+"\n");
		write(HIG); command("mon", this_player());  write(NORM);
		destruct(this_object());
		this_player()->recalc_carry();
		return 1;
	}
	else if(type_of == "Attack"){
               if(present("venom_object", this_player())->query_sphere_delay())
               {
                 write("You can only use one attack sphere per round.\n");
                 return 1;
               }
		if(this_player()->query_spell_dam()){ write("You are already using the sphere!\n");  return 1; }
		if(!this_player()->query_attack()){
			write("You are not fighting.\n");
			return 1;
		}
		damage = 25 + random(70);  /* up from damage = 17 + random(35); -Chip(4-17-09)*/
		target = this_player()->query_attack();
		tell_room(environment(this_player()),
			this_player()->query_name()+" grasps a "+HIK+"Dark Sphere..."+NORM+"\n"+
		"The Sphere erupts into motion as it launches into "+ATTN+" and "+HIR+"Impales"+NORM+" them!\n", ({USER}));
		tell_object(USER,
			"You grasp the Dark Matter Sphere...\n"+
			"The Sphere vibrates as it suddenly launches into the air and forms into a Spear!\n"+
		ATTN+" is   "+HIW+"-------  - --    --- -  "+HIR+"I M P A L E D"+NORM+HIW+"  -  -    --  -      -   -"+NORM+"\n");
		ATT->hit_player(damage);
               present("venom_object", this_player())->add_sphere_delay(1);
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
		if(random(100) > 87){  /* changed from if(random(100) > 80){ -Chip(4-17-09)*/
			tell_object(USER,
				"You hold the "+HIK+"Dark Matter"+BOLD+" Sphere"+NORM+" before you...\n"+
			"The Sphere attempts to bind "+target->query_name()+", but misses!\n");
			destruct(this_object());
			this_player()->recalc_carry();
			return 1;
		}
		tell_room(environment(USER),
			USER->query_name()+" holds up a "+HIK+"Dark "+BOLD+"Sphere..."+NORM+"\n"+
		"It flies from their hand and slams into "+ATTN+", trapping them in black webs!\n", ({USER}));
		tell_object(USER,
			"You hold the "+HIK+"Dark Matter"+BOLD+" Sphere"+NORM+" before you...\n"+
		"A stream of "+HIK+"webbing"+NORM+" flies from the "+BOLD+"sphere"+NORM+" covering "+target->query_name()+"!\n");
		web = clone_object("/players/fred/closed/venom/OBJ/webbing.c");
		web->set_time(55 + random(55));
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
			"You grasp the "+HIK+"Dark Matter"+BOLD+" Sphere"+NORM+"...\n"+
		"It dissolves in your hand and you feel a surge of power flow into your body.\n");
		present("venom_object", this_player())->add_mp(40);
		command("mp", this_player());
		destruct(this_object());
		USER->recalc_carry();
		return 1;
	}
	else{   write("Error: Report this using the 'neobug' command.\n"); destruct(this_object());  USER->recalc_carry(); return 1; }
	return 1;
}



query_weight(){ return 1; }
