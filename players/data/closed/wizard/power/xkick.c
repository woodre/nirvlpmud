/*
XKick
Attack Spell
[OLD]
  Skill lvl        1        2        3         4        5
  Damage         r(6)+2  r(8)+3  r(10)+4   r(12)+5  r(14)+7   
  Cost             5        7        9         11       14
May gain a bonus if boots are worn.

[NEW]
Skill lvl          1        2        3           4         5
  Damage         r(16)+8  r(18)+9  r(20)+10   r(22)+11  r(24)+12   
  Cost             16        18        20         22       24
*/

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
	object target;
   object ob;
	int woot,cost;
   int sklvl,check;
	string msg,msg2,msg3;
   string hm,hr,hh,ww;
   int bonus;
   int diff;
	int damage,spamount;
	string wep,where,how,COLOR;

	if(USER->query_ghost()) return 0;
	if(USER->query_spell_dam()) return 1;
   if(GOB->query_end() < 5){
      tell_object(USER,
      "You are too low on "+HIW+"["+HIM+"X POWER"+HIW+"]"+NORM+" to perform that.\n");
      return 1;
      }
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
 
   sklvl = GOB->get_skill(22);
   if(sklvl == 1){ cost = 16; }
   else if(sklvl == 2){ cost = 18; }
   else if(sklvl == 3){ cost = 20; }
   else if(sklvl == 4){ cost = 22; }
   else cost = 24;
  
	if(USER->query_sp() < cost && !GOB->query_blood()){
		tell_object(USER,
		"You are too weak to kick.\n");
		return 1;
	}
   if(USER->query_sp() < 1){
      write("You must have at least SOME endurance to attempt this.\n");
      return 1;
      }
   if(USER->query_sp() < cost){
    diff = cost - USER->query_sp();
    if(USER->query_hp() < diff){ 
     write("You don't have the health to do that!\n");
     return 1;
     }
    USER->add_spell_point(-USER->query_sp());
    cost = 0;
    tell_object(USER, HIR+"You trade "+RED+"blood"+NORM+" for "+HIR+"power"+NORM+"..."+NORM+"\n");
    USER->add_hit_point(-diff);
    }  

	bonus += random(boot_check(USER));

	spamount = cost;

   if(sklvl == 1) damage = random(16) + 8;
   else if(sklvl == 2) damage = random(18) + 9;
   else if(sklvl == 3) damage = random(20) + 10;
   else if(sklvl == 4) damage = random(22) + 11; 
   else if(sklvl == 5) damage = random(24) + 12;
   damage += bonus;

switch(random(100) + 1){
   case 96..1000: where = "head";     break;
   case 85..95:   where = "chest";    break;
   case 50..84:   where = "stomach";  break;
   case 30..49:   where = "arm";      break;
   case 16..29:   where = "shoulder"; break;
   case 1..15:    where = "leg";      break;
   }

switch(random(10) + 1){
   case 10:       ww = " Rising Moon-Kick";                       break;
   case 9:        ww = " Dragon-Tail Roundhouse"; where = "head"; break;
   case 8:        ww = " Serpent Front-Kick";               break;
   case 7:        ww = " Wolf-Fang Kick";                   break;
   case 6:        ww = " Flying Hawk-Kick"; where = "head"; break;
   case 5:        ww = " Monkey Side-Kick";                 break;
   case 4:        ww = " Crane Circle-Kick";                break;
   case 3:        ww = " Tiger Sweep-kick"; where = "leg";  break;
   case 2:        ww = " Crane Circle-Kick";                break;
   case 1:        ww = " Bear Power-Kick";                  break;
   }
switch(random(6)){
  case 5: COLOR = ""+HIG+"";
  break;
  case 4: COLOR = ""+HIY+"";
  break;
  case 3: COLOR = ""+HIR+"";
  break;
  case 2: COLOR = ""+HIB+"";
  break;
  case 1: COLOR = ""+HIM+"";
  break;
  case 0: COLOR = ""+HIC+"";
  break;
}
if(!random(2)){
tell_object(USER,
BOLD+"["+NORM+HIM+"XKick"+NORM+BOLD+"]"+NORM+"\n"+
"You deliver a"+COLOR+ww+NORM+" to "+ATTN+"'s "+where+"!\n");

tell_room(environment(USER),
USERN+" delivers a"+COLOR+ww+NORM+" to "+ATTN+"'s "+where+"!\n", ({USER}));
}
else{
tell_object(USER,
BOLD+"["+NORM+HIM+"XKick"+NORM+BOLD+"]"+NORM+"\n"+
"You hit "+ATTN+" with a"+COLOR+ww+NORM+" to the "+where+"!\n");

tell_room(environment(USER),
USERN+" hits "+ATTN+" with a "+COLOR+ww+NORM+" to the "+where+"!\n", ({USER}));
}
   GOB->add_end(-5);
   msg = "";
	msg2 = "";
	msg3 = "";
   GOB->set_delay(1);
  	USER->spell_object(ATT, "Kick Attack", damage, spamount,
	msg, msg2, msg3);
	return 1;
}


boot_check(ob){
object inv;
int x;
int woo;
inv = all_inventory(ob);
   for(x = 0; x < sizeof(inv); x++){
     if(inv[x]->query_worn() && inv[x]->query_type() == "boots"){
      woo = inv[x]->armor_class() + inv[x]->query_weight();
	   return woo;
	   }	
   }
  return 0;
 } 

