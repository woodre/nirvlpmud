/*
Punch
Attack Spell

  Skill lvl        1        2        3         4        5
  Damage         r(15)+2  r(18)+3  r(20)+4   r(22)+5  r(24)+7   
  Cost             10        12        17         20       23
May gain a bonus if gloves are worn.

*/

#include "/players/guilds/warriors/sdefine.h"


main(string str, object gob, object player)
{
	object target;
   object ob;
	int woot,cost;
   int sklvl,check;
	string msg,msg2,msg3;
   string hm,hr,hh;
   string ww;
	int damage,spamount;
   int bonus;
	string wep,where,how;
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
 
   sklvl = GOB->get_skill(17);
   if(sklvl == 1){ cost = 10; }
   else if(sklvl == 2){ cost = 12; }
   else if(sklvl == 3){ cost = 17; }
   else if(sklvl == 4){ cost = 20; }
   else cost = 23;
  
	if(USER->query_sp() < cost){
		tell_object(USER,
		"You are too weak to punch.\n");
		return 1;
	}

	bonus += random(ring_check(USER));

	spamount = cost;

   if(sklvl == 1) damage = random(15) + 2;
   else if(sklvl == 2) damage = random(18) + 3;
   else if(sklvl == 3) damage = random(20) + 4;
   else if(sklvl == 4) damage = random(22) + 5; 
   else if(sklvl == 5) damage = random(24) + 7;
   damage += bonus;

switch(random(100) + 1){
   case 96..1000: where = "head";     break;
   case 85..95:   where = "chest";    break;
   case 50..84:   where = "stomach";  break;
   case 30..49:   where = "arm";      break;
   case 1..29:    where = "shoulder"; break;
   }

switch(random(10) + 1){
   case 10:       ww = "n upper-cut";   break;
   case 6..9:     ww = " jab";         break;
   case 4..5:     ww = " roundhouse";  break;
   case 3:        ww = " backhand blow";    break;
   case 2:        ww = " quick-punch"; break;
   case 1:        ww = " hay-maker punch";   break;
   }
if(!random(2)){
tell_object(USER,
BOLD+"["+NORM+RED+"Punch"+NORM+BOLD+"]"+NORM+"\n"+
"You deliver a"+ww+" to "+ATTN+"'s "+where+"!\n");

tell_room(environment(USER),
USERN+" delivers a"+ww+" to "+ATTN+"'s "+where+"!\n", ({USER}));
}
else{
tell_object(USER,
BOLD+"["+NORM+RED+"Punch"+NORM+BOLD+"]"+NORM+"\n"+
"You hit "+ATTN+" with a"+ww+" to the "+where+"!\n");

tell_room(environment(USER),
USERN+" hits "+ATTN+" with a"+ww+" to the "+where+"!\n", ({USER}));

}
   msg = "";
	msg2 = "";
	msg3 = "";
   GOB->ast(17);
   GOB->set_delay(1);
	USER->spell_object(ATT, "Punch Attack", damage, spamount,
	msg, msg2, msg3);
	return 1;
}


ring_check(ob){
object inv;
int x;
int woo;
inv = all_inventory(ob);
   for(x = 0; x < sizeof(inv); x++){
     if(inv[x]->query_worn() && inv[x]->query_type() == "ring"){
      woo = inv[x]->armor_class() + inv[x]->query_weight();
	   return woo;
	   }	
   }
  return 0;
 } 

