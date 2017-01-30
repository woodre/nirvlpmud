/*
Charge
Attack Spell

  Skill lvl        1        2        3         4        5
  Damage        r(18)+2  r(20)+4  r(22)+8   r(25)+12 r(30)+15   
  Cost            11       14       19        22       25

Wimpy must be OFF. <<-

*/

#include "/players/guilds/warriors/sdefine.h"


main(string str, object gob, object player)
{
	object target;
   object ob;
   int bonus;
	int woot,cost;
   int sklvl,check;
	string msg,msg2,msg3;
   string hm,hr,hh;
	int damage,spamount;
	string wep,where,how;
   int stun;
	if(USER->query_ghost()) return 0;
	if(USER->query_spell_dam()) return 1;
	if(GOB->query_spell_delay()){
		tell_object(USER,
		"You are already using a skill.\n");
		return 1;
	}
    if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     } 
	if(!USER->query_attack()){
		tell_object(USER, "You are not fighting!\n");
		return 1;
	}
   if(!present(ATT, environment(USER))){
      return 1;
      }
   if(ATT->query_ghost()) return;
   if(USER->query_wimpy()){
      tell_object(USER, "You cannot do this when you are ready to flee!\n"); 
      return 1; 
      }
     
   sklvl = GOB->get_skill(19);
   cost = 28;
   
	if(USER->query_sp() < cost || GOB->query_end() < 5){
		tell_object(USER,
		"You are too weak to Charge.\n");
		return 1;
	}

	spamount = cost;
   damage = random(30) + 15;
   damage += bonus;

switch(random(10) + 1){
   case 10:
   hm = "charge ahead fearlessly and attack!";
   hr = "charges ahead fearlessly and attacks!";
   break;
   case 9:
   hm = "charge ahead and attack without mercy!";
   hr = "charges ahead and attacks without mercy!";
   break;
   case 8:
   hm = "fearlessly charge forth into battle!";
   hr = "fearlessly charges forth into battle!";
   break;
   case 7:
   hm = "scream loudly and charge!";
   hr = "screams loudly and charges!";
   break;
   case 6:
   hm = "rush forward without fear!";
   hr = "rushes forward without fear!";
   break;
   case 5:
   hm = "let out a roar and charge!";
   hr = "lets out a roar and charges!";
   break;
   case 4:
   hm = "rush forward, weapon overhead and ready!";
   hr = "rushes forward, weapon overhead and at the ready!";
   break;
   case 3:
   hm = "ignore all danger and charge!";
   hr = "charges fearlessly ahead!";
   break;
   case 2:
   hm = "rush forward, bellowing a war cry!";
   hr = "rushes forward, bellowing a war cry!";
   break;
   case 1:
   hm = "duck and charge forward, brutally attacking!";
   hr = "ducks and charges forward, brutally attacking!";
   break;
   } 
   
switch(random(10) + 1){
   case 10:
   hh = "is blasted backwards by the force";
   break;
   case 9:
   hh = "is sent flying to the ground";
   stun = 1;
   break;
   case 8:
   hh = "is turned sideways and shaken by the blow";
   break;
   case 7:
   hh = "is knocked senseless by the charge";
   break;
   case 6:
   hh = "falls back under the onslaught";
   break;
   case 5: 
   hh = "is knocked to one knee and shaken";
   stun = 1;
   break; 
   case 4:
   hh = "is slammed backwards by the force";
   break;
   case 3:
   hh = "is sent tumbling backwards";
   break;
   case 2:
   hh = "grunts and falls to the ground in a heap";
   stun = 1;
   break;
   case 1:
   hh = "stumbles back and tries to keep "+ATT->POS+" balance";
   break;
   }

if(random(100) < sklvl * 8) stun = 1;
if(random(100) < sklvl * 10 && ATT->query_hp() > 10){
 if(ATT->is_npc()) ATT->heal_self(-10);
 else ATT->add_hit_point(-(random(5) + 1));
 }

tell_object(USER,
HIR+"< "+HIW+"X CHARGE"+HIR+" >"+NORM+" "+
HIW+"You "+hm+"\n"+
ATTN+" "+hh+"!"+NORM+"\n");

tell_room(environment(USER),
HIW+USERN+" "+hr+"\n"+
ATTN+" "+hh+"!"+NORM+"\n", ({USER}));

if(stun){
   if(!present("stun_object_prof", ATT)){
    move_object(clone_object("/players/guilds/warriors/OBJ/stun.c"), ATT);
    tell_object(USER, HIR+ATTN+" is stunned!"+NORM+"\n");
    }
}
   GOB->blocked_wimpy(3);
   msg = "";
	msg2 = "";
	msg3 = "";
   GOB->set_delay(1);
   GOB->ast(19);
   GOB->add_end(-5);
	USER->spell_object(ATT, "XCharge Attack", damage, spamount,
	msg, msg2, msg3);
	return 1;
}

