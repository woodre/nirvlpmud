/*
Bash
Attack Spell

  Skill lvl        1        2        3         4        5
  Damage        r(8)+3    r(12)+5  r(15)+7  r(20)+9   r(24)+12        
  Cost             7        11       14       19        24
Requires a Shield

XBASH:
  Skill lvl        1        2        3         4        5
  Damage        r(25)+12  r(26)+13 r(27)+13 r(29)+14  r(30)+15        
  Cost            25       26        27       28        30
	
*/

#include "/players/guilds/warriors/sdefine.h"


main(string str, object gob, object player)
{
	object target;
   object ob;
	int woot,cost;
   int sklvl;
	string msg,msg2,msg3;
   string hm,hr,hh;
   int bonus;
	int damage,spamount;
	string wep,where,how;
	if(USER->query_ghost()) return 0;
	if(USER->query_spell_dam()) return 1;
	if(GOB->query_spell_delay()){
		tell_object(USER,
		"You are already using "+GOB->query_spell_delay()+".\n");
		return 1;
	}
   if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     }  
   if(!shield_check(USER)){ 
      tell_object(USER, "You do not have a shield worn!\n");
      return 1;
      }
   
	if(!USER->query_attack()){
		tell_object(USER, "You are not fighting!\n");
		return 1;
	}
   if(GOB->query_end() < 3){ 
      tell_object(USER, "Your endurance is too low.\n");
      return 1;
      }

   sklvl = GOB->get_skill(102);
   if(sklvl == 1){ cost = 25; }
   else if(sklvl == 2){ cost = 26; }
   else if(sklvl == 3){ cost = 27; }
   else if(sklvl == 4){ cost = 28; }
   else cost = 30;
  
	if(USER->query_sp() < cost){
		tell_object(USER,
		"You are too weak to bash.\n");
		return 1;
   	}
	
	spamount = cost;

   if(sklvl == 1) damage = random(25) + 12;
   else if(sklvl == 2) damage = random(26) + 13;
   else if(sklvl == 3) damage = random(27) + 13;
   else if(sklvl == 4) damage = random(29) + 14; 
   else if(sklvl == 5) damage = random(30) + 15;

   if(GOB->get_skill(33) && random(100) < GOB->get_skill(33)*4){
      damage += random(shield_check(USER)) + 1;
      }
   
  if(GOB->query_knight())
  if(USER->query_wimpy()) damage = damage / 2;


   switch(damage){
    case 34..1000:
    hh = HIR+"S L A M M E D"+NORM;
    break;
    case 28..33:
    hh = HIR+"Slammed"+NORM;
    break;
    case 22..27:
    hh = RED+"Bashed"+NORM;
    break;
    case 16..21:
    hh = RED+"Struck"+NORM;
    break;
    case 12..15:
    hh = HIW+"Hit"+NORM;
    break;
    case 5..11:
    hh = HIW+"pounded"+NORM;
    break;
    case 1..4:
    hh = HIW+"brushed"+NORM;
    break;
    default:
    hh = "hit";
    break;
    }
   
   switch(random(4)+1){
   case 4:
   where = "head";
   break;
   case 3:
   where = "body";
   break;
   case 2:
   where = "arm";
   break;
   case 1:
   where = "stomach";
   break;
   }

 GOB->add_end(-3);
   tell_object(USER,
   HIR+"["+NORM+HIW+"XBASH"+NORM+HIR+"]"+NORM+" "+
   RED+"You "+hh+" "+ATTN+" with a Shield Bash to the "+where+"!"+NORM+"\n");
   
   tell_room(environment(USER),
   RED+USERN+" "+hh+" "+ATTN+" with a "+BOLD+"Shield Bash"+NORM+RED+" to the "+where+"!"+NORM+"\n", ({ USER }));
	msg = "";
	msg2 = "";
	msg3 = "";
	USER->spell_object(ATT, "XBash Attack", damage, spamount,
	msg, msg2, msg3);
	return 1;
}


shield_check(ob){
object inv;
int x;
int woo;
inv = all_inventory(ob);
   for(x = 0; x < sizeof(inv); x++){
     if(inv[x]->query_worn() && inv[x]->query_type() == "shield"){
      woo = inv[x]->armor_class() + inv[x]->query_weight();
	   return woo;
	   }	
   }
  return 0;
 } 
