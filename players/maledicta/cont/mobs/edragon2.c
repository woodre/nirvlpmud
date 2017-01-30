#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("dragon");
set_alt_name("cont_dragon");
set_race("dragon");
set_short(HIG+"Emerald "+NORM+GRN+"Dragon"+NORM+" (soldier)");
set_long(
"  This is a large Emerald Dragon, its body covered in thick\n"+
"shining translucent green scales.  It is almost 100 feet in\n"+
"length with huge wings spreading out defensively. Its eyes\n"+
"are a deep blue, watching you carefully.  The dragons claws\n"+
"are as long as swords and even more deadly. Its head is covered\n"+
"with short green spikes and long crystalline horns which jut\n"+
"straight out from behind its tooth filled maw.\n");
set_level(20);
set_hp(700);
set_al(1000);
set_aggressive(0);
set_wc(40);
set_ac(21);
set_heart_beat(1);
set_chat_chance(10);
load_chat("The Emerald Dragon hisses,'I will protect the Queen!'\n");
load_chat("The light strikes the Emerald scales of the Dragon and glows.\n");
load_chat("The Emerald Dragon's tail swishes lazily back and forth.\n");
}


heart_beat(){
int rnum;
object ob2;
object next;
::heart_beat();

rnum = random(100);

if(!bdelay && random(100) < 50 && attacker_ob){
tell_room(environment(),
"A large cloud of "+YEL+"Yellowish Gas"+NORM+" flows from the Dragons\n"+
"open mouth!\n\n"+
"          "+HIY+"Choking Fumes Envelope The Room!"+NORM+"\n\n\n");
ob2 = first_inventory(environment(this_object()));
  while(ob2) {
      next = next_inventory(ob2);
	  if(ob2->is_living() && !ob2->query_emerald_dragon()){
		  tell_room(environment(),
		  ob2->query_name()+" chokes on the Gas!\n");
              ob2->hit_player(random(35) + 20);
		  }
  ob2 = next;      
  }
 bdelay = 3;
 }
else if(attacker_ob){
bdelay -= 1;
if(bdelay < 0) bdelay = 0;
}

if(bdelay && attacker_ob){
if(rnum > 70){
if(random(100) < 70 && attacker_ob){
tell_room(environment(),
"The "+HIG+"Emerald "+NORM+GRN+"Dragon"+NORM+" reaches out and rakes with its gleaming claws!\n",
({ attacker_ob }));
tell_object(attacker_ob,
"You feel a terrible pain as the Dragon rakes you with its claws!\n");
attacker_ob->hit_player(random(21));
}
else if(attacker_ob){
tell_object(attacker_ob,
"You barely dodge the gleaming claws of the Dragon!\n");
}
}
}
else if(rnum < 20){
if(alt_attacker_ob && random(100) < 30){
tell_object(alt_attacker_ob,
"You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");
alt_attacker_ob->hit_player(random(18));
tell_room(environment(),
"The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");
  }
 } 
}

query_emerald_dragon(){ return 1; }