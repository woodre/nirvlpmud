#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object gold,helmet,armor,weapon,shield;
int guarding;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("guard");
set_alt_name("high_guard");
set_alias("templar");
set_race("human");
set_short(HIB+"High Templar"+NORM);
set_long(
"  Before you stand the most powerful of the templar guard. He is\n"+
"dressed in full suits of plate armor, each tinted blue with a white\n"+
"cross displayed on the breastplate and knee guards. A large shield\n"+
"is held at the ready, and an oversized broadsword is left sheathed\n"+
"at the hip. He seems ready for any combat. Use 'command info' for\n"+
"more information on this knight.\n");  
set_level(20);
set_hp(850);
set_al(1000);
weapon = clone_object("players/maledicta/templar/items/bsword");
move_object(weapon, this_object());
command("wield pike", this_object());
armor = clone_object("players/maledicta/templar/items/fullplate2");
move_object(armor, this_object());
command("wear fullplate", this_object());
helmet = clone_object("players/maledicta/templar/items/helmet");
move_object(helmet, this_object());
command("wear helmet", this_object());
shield = clone_object("players/maledicta/templar/items/shield");
move_object(shield, this_object());
command("wear shield", this_object());
set_wc(30);
set_ac(20);
set_aggressive(0);
set_heart_beat(1);
set_chance(20);
set_spell_dam(30);
set_spell_mess1(
  "The High Templar charges his foe!\n");
set_spell_mess2(
  "You feel a biting pain as the High Templars Sword slices into your flesh!\n");
gold = clone_object("obj/money");
gold->set_money(800);
move_object(gold,this_object());
}


init(){
::init();
if(guarding && !present("KnightInvite", this_player()) && !query_attack() && !this_player()->is_npc()){
  attack_object(this_player());
  tell_room(environment(),
  "The High Templar rushes to defend the castle!\n");
  add_action("block_exit","north", 1);
  add_action("block_exit","south", 1);
  add_action("block_exit","east", 1);
  add_action("block_exit","west", 1);
  add_action("block_exit","up", 1);
  add_action("block_exit","down", 1);
  }
if(present("KnightInvite", this_player())){  
add_action("help_knight","command");
  }
}

block_exit(){
if(present("KnightTemplar", this_player()) || present("KnightInvite", this_player())) return;
write("You try to escape but the High Templar blocks you!\n");
return 1;
}

help_knight(str){
string who,where;
object fool;

if(!present("KnightInvite", this_player())) return 0;
if(!str){
 tell_room(environment(),
 "The High Templar looks at "+this_player()->query_name()+" in confusion.\n");
 return 1;
 }
if(str == "info"){
write(
"You may command the High templar to do the following...\n"+
"command kill <who>   - Use this wisely.\n"+
"command guard <where>\n"+
"Where locations:  gatehouse, church, training, courtyard,\n"+
"                  and mainhall\n");
return 1;
}
 
if(sscanf(str,"kill %s", who)){
if(!who) return 1;
fool = present(who, environment());
  if(!fool){
  tell_room(environment(),
  "The High Templar looks at "+this_player()->query_name()+" in confusion.\n");
  return 1;
  }
  if(!living(fool)){
  tell_room(environment(),
  "The High Templar looks at "+this_player()->query_name()+" in confusion.\n");
  return 1;
  }
  if(fool && !present("KnightTemplar", fool)){
  attack_object(fool);
  tell_room(environment(),
  "The High Templar charges to attack "+fool->query_name()+"!\n");
  return 1;
  }
 return 1;
}
if(sscanf(str,"guard %s", where)){   
if(query_attack()){
  write("The guard cannot listen right now!\n");
  return 1;
  }
if(!where) return 1;
if(where == "gatehouse"){
tell_room(environment(),
"The guard nods and leaves.\n");
move_object(this_object(), "players/maledicta/templar/rooms/gatehouse");
guarding = 1;
tell_room(environment(),
"A High Templar arrives to guard the gatehouse.\n");
return 1;
}   
if(where == "courtyard"){
tell_room(environment(),
"The guard nods and leaves.\n");
move_object(this_object(), "players/maledicta/templar/rooms/courtyard");
guarding = 1;
tell_room(environment(),
"A High Templar arrives to guard the courtyard.\n");
return 1;
}   
if(where == "mainhall"){
tell_room(environment(),
"The guard nods and leaves.\n");
move_object(this_object(), "players/maledicta/templar/rooms/main");
guarding = 1;
tell_room(environment(),
"A High Templar arrives to guard the main hall.\n");
return 1;
}   

if(where == "church"){
tell_room(environment(),
"The guard nods and leaves.\n");
move_object(this_object(), "players/maledicta/templar/rooms/church");
guarding = 1;
tell_room(environment(),
"A High Templar arrives to guard the church.\n");
return 1;
}   

if(where == "training"){
tell_room(environment(),
"The guard nods and leaves.\n");
move_object(this_object(), "players/maledicta/templar/rooms/adv_guild");
guarding = 1;
tell_room(environment(),
"A High Templar arrives to guard the training hall.\n");
return 1;
}   

return 1;
}
tell_object(this_player(),
"The High Templar looks at you in confusion.\n");
return 1;
}


query_templar_guard(){ return 1; }

heal_self(int i){
if(i < 0){
tell_room(environment(),
"The High Templar shrugs off the attack!\n");
return 1;
}
::heal_self(i);
return 1;
}

heart_beat(){
int x;
object ob;
object ob2;
object att;
object next;
if(root()) return set_heart_beat(0);
if(query_wc() < 30) set_wc(30);
if(query_ac() < 20) set_ac(20);
  if(query_attack() && present("fear_link", query_attack()))
    destruct(present("fear_link", query_attack()));

::heart_beat();

		
ob2 = first_inventory(environment(this_object()));
if(!query_attack()){
  while(ob2) {
      att = ob2->query_attack();
      next = next_inventory(ob2);
	  if(att && ob2->query_templar_guard()){
		  tell_room(environment(),
			  "The Templar Guard rushes to the attack!\n\n");
		  attack_object(att);
		       }
	  
  ob2 = next;      
  }
}


ob = users();
if(!query_attack() && guarding){
for (x = 0; x < sizeof(ob); x ++){
	if(present(ob[x], environment()) && living(ob[x]) && !ob[x]->is_npc() &&
	   !present("KnightInvite", ob[x])){
	attack_object(ob[x]);
	tell_room(environment(),
   "The High Templar rushes to attack "+ob[x]->query_name()+"!\n");
	                   }
                       }
                    }
  	          }	

