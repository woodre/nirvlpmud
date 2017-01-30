
/*  Unconscious Body Object for use with the Symbiotes  */


inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define following find_player(follow)
#define TP this_player()
#define USER TP
#define GOB present("venom_drag_object", this_player())
int stored_level,stored_wc,stored_ac,stored_spell_dam,stored_spell_chance;
int stored_heal_intv,stored_heal_rate,stored_mhp;
string stored_name,stored_short,stored_long,stored_gender;
string follow;
object feeding;
int ruined;

id(str){ return str == "body" || str == "venom_uncon_object"; }

short(){ return "The Unconscious Body of "+stored_name+""; }

long(){
	write("This is the body of "+stored_name+".\n"+
	"It might be useful, but you aren't sure how.\n");
         /* 6.11.01 - removed a bracket so the if(GOB) check affects the other checks too. verte */
	if(GOB){
		write("You can 'drag' the body and 'release' it at any time.\n");
	if(GOB->query_control() > 3 && GOB->query_combat() > 3){
		write("You may 'feed on body' for additional health.\n");
	}
	if(GOB->query_creation() > 5){
		write("You may 'dominate' the body at any time to force it to be a pet.\n");
	}
        }
        return;
}

reset(){ call_out("destruct_this", 1800); }

destruct_this(){
        /* next line 6.11.01 by verte */
        if(!environment()) return;
	tell_room(environment(), "The "+stored_name+" wakes up and wanders off dazed and confused...\n");
	destruct(this_object());
	return 1;
}


query_weight(){ return 30; }
query_value(){ return 0; }
query_save_flag(){ return 1; }

init(){
	add_action("drag_body", "drag");
	add_action("release_corpse", "release");
	add_action("feed_on", "feed");
	add_action("assimilate_this", "dominate");
}

assimilate_this(str){
	object pet;
	if(!GOB) return 0;
	if(GOB->query_creation() < 6) return 0;
	if(!str){ 
		write("dominate what?\n");
		return 1;
	}
      if(str != "body"){
		write("dominate what?\n");
		return 1;
	}
	if(ruined){ write("You cannot dominate this body, it is useless.\n"); return 1; }
	if(follow){ write("You cannot dominate a body that is being drug.\n"); return 1; }
	if(feeding){ write("This body is being fed on.\n"); return 1; }
	if(GOB->query_pet()){ write("You have already dominated a pet.\n");  return 1; }
	if(GOB->query_mp() < 100){
		write("You lack the Dark Matter to perform that.\n");
		return 1;
	}
	if(this_player()->query_sp() < 100){
		write("You lack the energy to perform that.\n");
		return 1;
	}
	pet = clone_object("/players/maledicta/venom2/OBJ/pet.c");
	pet->set_name(stored_name);
	pet->set_short(stored_short);
	pet->set_wc(stored_wc);
	pet->set_ac(stored_ac);
	pet->set_health(stored_mhp);
	pet->set_owner(this_player());
	pet->set_nowner(this_player()->query_real_name());
	GOB->set_pet(pet);
	move_object(pet, environment(USER));
	GOB->add_mp(-100);
	this_player()->add_spell_point(-100);
	tell_room(environment(USER),
		USER->query_name()+" leans over the body of "+stored_name+"...\n"+
		"A thin tendril of "+BOLD+"Dark Matter"+NORM+" extends from "+USER->query_possessive()+" palm and enters the body.\n"+
	"The body shakes and awakens.  "+stored_name+" stands and bows low to its Master.\n", ({ this_player() }));
	tell_object(TP,
		"You place your palm on the body of "+stored_name+"...\n"+
		BOLD+"Dark Matter"+NORM+" is injected directly into its brain through a long tendril.\n"+
		"The Matter works its way into the higher functions of the mind of "+capitalize(stored_name)+".\n"+
	"It rises up and bows low to you, its Master.\n");
	destruct(this_object());
	return 1;
}


feed_on(str){
	if(!GOB) return 0;
	if(GOB->query_control() < 3 || GOB->query_combat() < 3){
		return 0;
	}
	if(!str || str != "on body"){
		write("feed on what?\n");
		return 1;
	}
	if(follow){ write("You cannot feed on a body that is being drug.\n"); return 1; }
	if(feeding){ write("This body is already being fed on.\n"); return 1; }
	tell_room(environment(),
	this_player()->query_name()+" forces a "+BOLD+"Dark Matter"+NORM+" tentacle into the body of "+stored_name+".\n");
	feeding = this_player();
	follow = 0;
	ruined = 1;
	set_heart_beat(1);
	return 1;
}

drag_body(str){
	if(!GOB) return 0;
	if(!str){ write("Drag what?\n"); return 1; }
	if(str != "body"){ write("Drag what?\n"); return 1; }
	if(follow && this_player()->query_real_name() == follow){ write("You are already dragging it!\n"); return 1; }
	if(follow){ write("It is already being drug...\n"); return 1; }
	if(GOB->query_body() > 7){ write("You are already dragging the max number.\n"); return 1; }
	if(feeding){ write("You cannot drag a body that is being fed on.\n"); return 1; }
	follow = this_player()->query_real_name();
	GOB->add_body(1);
	set_heart_beat(1);
	tell_room(environment(this_object()),
	this_player()->query_name()+" latches onto body of "+stored_name+" with a "+BOLD+"Dark Matter"+NORM+" tentacle.\n");
	return 1;
}

release_corpse(str){
	if(!follow) return 0;
	if(follow != this_player()->query_real_name()) return 0;
	if(!str || str != "body"){ write("release what?\n"); return 1; }
	follow = 0;
	GOB->add_body(-1);
	set_heart_beat(0);
	tell_room(environment(this_object()),
	this_player()->query_name()+" retracts a "+BOLD+"Dark Matter"+NORM+" tentacle from the body of "+stored_name+".\n");
	return 1;
}

heart_beat(){
	if(ruined) follow = 0;
	if(follow){
     if(!following) follow = 0;
     }
   if(follow){
	if(following->query_ghost()) follow = 0;
	if(present("venom_drag_object", following)){
		if(!present("venom_drag_object", following)->query_body()){
			follow = 0;
		}
	  }
    }
   if(follow){
	if(!present(following, environment())){
		tell_room(environment(), "Body of "+capitalize(stored_name)+" leaves the room, drug by "+capitalize(follow)+"'s tentacles.\n");
		move_object(this_object(), environment(following));
		tell_room(environment(),
		"A body enters the room being drug by "+capitalize(follow)+"'s tentacles.\n");
	 }
   }
	if(feeding){
		if(!present(feeding, environment())){
			tell_room(environment(),
			"Body of "+stored_name+" withers away unattended.\n");
			destruct(this_object());
			return 1;
		}
		tell_object(feeding, "You feel energy rush from the body of "+stored_name+" to you.\n");
		feeding->heal_self(2);
		stored_level -= 1;
		if(stored_level < 1){
			tell_room(environment(), feeding->query_name()+" finishes draining the body. It withers away.\n");
			destruct(this_object());
			return 1;
		}
	}
}

query_ruined(){ return ruined; }

store_gender(str){
	if(!str) return stored_gender;
	stored_gender = str;
}
store_name(str){
	if(!str) return stored_name;
	stored_name = str;
}
store_level(int i){
	if(!i) return stored_level;
	stored_level = i;
}
store_short(str){
	if(!str) return stored_short;
	stored_short = str;
}
store_long(str){
	if(!str) return stored_long;
	stored_long = str;
}
store_spell_dam(int i){
	if(!i) return stored_spell_dam;
	stored_spell_dam = i;
}
store_spell_chance(int i){
	if(!i) return stored_spell_chance;
	stored_spell_chance = i;
}
store_heal_rate(int i){
	if(!i) return stored_heal_rate;
	stored_heal_rate = i;
}
store_heal_intv(int i){
	if(!i) return stored_heal_intv;
	stored_heal_intv = i;
}
store_mhp(int i){
	if(!i) return stored_mhp;
	stored_mhp = i;
}
store_ac(int i){
	if(!i) return stored_ac;
	stored_ac = i;
}
store_wc(int i){
	if(!i) return stored_wc;
	stored_wc = i;
}

