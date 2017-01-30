/* This NPC can be hired to hunt any player that is equal to or above level
   8. The cost to hunt is 500 coins per level of the target. He will hunt
   only one person at a time until they log off or die. The target can
   only be hunted in my areas, /players/maledicta...OR, in Dragnar's areas
   (with his permission of course) /players/dragnar. He will move himself
   to the target immediately and begin attacking them. He cannot follow 
   outside of the designated areas, and will return to the restaurant in
   Derellia when not fighting. Quitting out is an option, and he is not 
   unbeatable. */


#define opp this_object()->query_attack()

#include "/players/maledicta/ansi.h"

inherit "obj/monster.c";
int heals;
int hunting_it;
object meat;
object hunting_now;
reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("hunter");
set_alt_name("whiteblade");
set_alias("owner");
set_race("human");
set_short(""+HIW+"Whiteblade the "+HIR+"Hunter"+NORM+"");
set_long(
"  Standing before you is a man of slight build and a hawklike visage. He\n"+
"wears a full suit of light combat armor that covers everything but his\n"+
"head. Allowing a clear view of his long black hair and dark eyes. A\n"+
"blaster pistol is strapped to his side.\n");

set_level(20);
set_hp(600);
set_al(-500);
set_wc(28);
set_ac(16);
set_aggressive(0);
enable_commands();
set_heart_beat(1);
set_chat_chance(5);
  load_chat("Whiteblade says: Need something?\n");
  load_chat("Whiteblade studies the room with an expert eye.\n");
  load_chat("The hunter says: Show me money and I am interested. Otherwise, go away.\n");
  load_chat("Whiteblade says: Need a job done? I'm the one to hire.\n");
gold = clone_object("obj/money");
gold->set_money(1000 + random(1000));
move_object(gold,this_object());
heals = 5;
}

init(){
  ::init();
  add_action("hire_me", "hire");
  }

/****************************************************/
catch_tell(str){
object corpse;
string extra;
string who;
corpse = present("corpse", environment());	
if(sscanf(str, "You killed %s.\n", who)) {
if (sscanf(file_name(corpse),"obj/corpse%s",extra)){
	move_object(corpse, this_object());
        tell_room(environment(),
        "Whiteblade takes corpse.\n");
	}	
tell_room(environment(),
"Whiteblade grins evilly and says: Another satisfied customer.\n");
hunting_now = 0;
hunting_it = 0;
  }
}		

/*****************************************************/
hire_me(string str){

if(!str){
   write("Hire who?\n");
   return 1;
   }			
if(str == "hunter" || str == "whiteblade"){
if(hunting_now){
	write("Whiteblade says: I am busy, maybe another time.\n");
	return 1;
        }
write("Whiteblade looks up, a gleam in his eyes.\n");
write("He then says: Yeah, I'm the man for the job. Who do you want dead?\n");
write("Enter victim: ");
input_to("victim_me");
return 1;
    }
return 0;
}

/*******************************************************/
victim_me(str){
meat = find_living(str);
if(!str){
    write("Whiteblade says: Heh, I don't know who that is. Sorry.\n");
    return 1;
    }
if(!meat){ write("Whiteblade says: I don't know who that is. Sorry.\n");
return 1;
}	

if(meat->query_npc()){ write("Whiteblade says: HA!! I only kill people.\n");
return 1;
}

if(meat){
if(meat->query_level() < 8){
write("Whiteblade smirks and says: You need an amateur for such a small job.\n");
return 1;
}	
if(meat->query_level() > 19){
write("Whiteblade laughs in your face!\n");
return 1;
}	
    write("Whiteblade gives you a brief smile and leans forward.\n"+
          "He then says: Yeah, I know "+meat->query_objective()+",\n"+
          "but it will cost you. I need "+meat->query_level()*500+" coins up front.\n");
    write("Is this acceptable? <y/n> ");
    input_to("accept_it");
   }
return 1;
}

/*********************************************************/
accept_it(string str){
	
if(!str || str == "n"){
write("Whiteblade says: I didn't think you could afford that.\n");
return 1;
       }

if(str == "y"){
if(!meat){
   write("Whiteblade says: You waited too long. Maybe another time.\n");
   return 1;
   }				    
if(this_player()->query_money() < meat->query_level()*500){
   write("Whiteblade says: You don't have that kind of cash!\n");
   return 1; 
   }
write("Whiteblade stands and says: Consider them dead.\n");
hunting_now = meat;
hunting_it = 1;
this_player()->add_money(-(meat->query_level()*500));
this_object()->add_money(meat->query_level() *250);
return 1;
   }
write("Whiteblade says: I didn't think you could afford that.\n");
return 1;
}

/************************************************************/
query_hbflag(){ return "hbstayon"; }

/************************************************************/
heart_beat(){
string place;
  ::heart_beat();


  
if(query_attack() && random(100) < 25){
   tell_room(environment(),
   "Whiteblade fires a deadly round of blaster fire at "+opp->query_name()+"!\n");
   opp->hit_player(random(35)+15);
   }
	
if(query_hp() < query_mhp()/8 && random(100) < 40 && heals){
   hit_point += 50;
   tell_room(environment(),
   "Whiteblade punches a button on his breastplate and feels better.\n");
   heals -= 1;
   }	

if(query_hp() < query_mhp() && !query_attack()){
   hit_point += 10;
   }

if(hunting_now && hunting_now->query_ghost()){
  tell_room(environment(),
  "Whiteblade laughs and says: Looks like someone did the job for me.\n");
  hunting_now = 0;
  hunting_it = 0;
  }	
if(!hunting_now && hunting_it){
  tell_room(environment(),
  "Whiteblade growls and says: I will get them next time.\n");
  hunting_now = 0;
  hunting_it = 0;
  }	
if(hunting_now && present(hunting_now, environment()) && !query_attack()){
 if(sscanf(file_name(environment(hunting_now)), "players/maledicta/%s", place) ||
    sscanf(file_name(environment(hunting_now)), "players/dragnar/%s", place)){
    tell_object(hunting_now,
   "Whiteblade the Hunter says: Its nothing personal, but you must die.\n");
   attack_object(hunting_now);     
  }
}
if(hunting_now && !query_attack()){
 if(sscanf(file_name(environment(hunting_now)), "players/maledicta/%s", place) ||
 sscanf(file_name(environment(hunting_now)), "players/dragnar/%s", place) ||
 sscanf(file_name(environment(hunting_now)), "players/zeus/realm/city/%s", place)){
 tell_room(environment(),
 "Whiteblade grins evilly and leaves suddenly.\n");
 move_object(this_object(), environment(hunting_now));
 tell_object(hunting_now,
 "Whiteblade the Hunter says: Its nothing personal, but you must die.\n");
if(present(hunting_now, environment())){
 attack_object(hunting_now);             
   } 
  }
 }
if(!hunting_now && 
!sscanf(file_name(environment(this_object())), "players/maledicta/town/rooms/%s", place) &&
!query_attack()){
tell_room(environment(),
"Whiteblade leaves.\n");	
move_object(this_object(), "/players/maledicta/town/rooms/t9.c");	
      }
}          				
