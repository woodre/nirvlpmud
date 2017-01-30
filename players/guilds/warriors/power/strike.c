/*
Strike
Attack Spell

  Skill lvl        1        2        3         4        5
  Damage         r(10)+5  r(12)+6  r(14)+7   r(16)+8  r(20)+10   
  Cost            10       12       14        16       20
May gain a bonus if weapon used is a proficiency wep

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
		"You are already using a skill.\n");
		return 1;
	}
   if(!USER->query_weapon()){ 
      tell_object(USER, "You do not have a weapon wielded!\n");
      return 1;
      }
   
	if(!USER->query_attack()){
		tell_object(USER, "You are not fighting!\n");
		return 1;
	}
    if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     } 
   ob = USER->query_weapon();

   sklvl = GOB->get_skill(16);
   if(sklvl == 1){ cost = 10; }
   else if(sklvl == 2){ cost = 12; }
   else if(sklvl == 3){ cost = 14; }
   else if(sklvl == 4){ cost = 16; }
   else cost = 20;  

   if(present("warrior_strike_bonus", USER)){
      cost -= 7;
      }

	if(USER->query_sp() < cost){
		tell_object(USER,
		"You are too weak to strike.\n");
		return 1;
	}
	
	spamount = cost;
   if(sklvl == 1) damage = random(10) + 5;
   else if(sklvl == 2) damage = random(12) + 6;
   else if(sklvl == 3) damage = random(14) + 7;
   else if(sklvl == 4) damage = random(16) + 8; 
   else if(sklvl == 5) damage = random(20) + 10;

  if(GOB->blunt_check(ob)){
    if(GOB->get_skill(1)) bonus = random(GOB->get_skill(1)/2);
    } 
else if(GOB->edged_check(ob)){
    if(GOB->get_skill(2)) bonus = random(GOB->get_skill(2)/2);
    }
else if(GOB->polearm_check(ob)){
    if(GOB->get_skill(3)) bonus = random(GOB->get_skill(3)/2);
    }
else if(GOB->exotic_check(ob)){
    if(GOB->get_skill(5)) bonus = random(GOB->get_skill(5)/2);
    }
else if(GOB->small_check(ob)){
    if(GOB->get_skill(6)) bonus = random(GOB->get_skill(6)/2);
    }

if(bonus) damage += bonus + 1;

switch(random(20) + 1){
  case 20:
  hr = USERN+" lunges forward...\n";
  hm = "You lunge forward...\n";
  break;
  case 19:
  hr = USERN+" sidesteps and drives "+UPOS+" "+WEPN+" upward...\n";
  hm = "You sidestep and drive your "+WEPN+" upward...\n";
  break; 
  case 18:
  hr = USERN+" fakes left and swings "+UPOS+" "+WEPN+" to the right...\n";
  hm = "You fake left and swing your "+WEPN+" to the right...\n";
  break;
  case 17:
  hr = USERN+" fakes right and swings "+UPOS+" "+WEPN+" to the left...\n";
  hm = "You fake right and swing your "+WEPN+" to the left...\n";
  break;
  case 16:
  hr = USERN+" backsteps and swings "+UPOS+" "+WEPN+" down hard...\n";
  hm = "You backstep and swing your "+WEPN+" down hard...\n";
  break;
  case 15:
  hr = USERN+" twists back and swings "+UPOS+" "+WEPN+" to the side...\n";
  hm = "You twist back and swing your "+WEPN+" to the side...\n";
  break;
  case 14:
  hr = USERN+" drives "+UPOS+" "+WEPN+" forward in a mighty thrust...\n";
  hm = "You drive your "+WEPN+" forward in a mighty thrust...\n";
  break;
  case 13:
  hr = USERN+" ducks down and lunges up with "+UPOS+" "+WEPN+"...\n";
  hm = "You duck down and lunge up with your "+WEPN+"...\n";
  break;
  case 12:
  hr = USERN+" swings "+UPOS+" "+WEPN+" in a lazy arc...\n";
  hm = "You swing your "+WEPN+" in a lazy arc...\n";
  break;
  case 11:
  hr = USERN+" swings "+UPOS+" "+WEPN+" in a quick arc...\n";
  hm = "You swing your "+WEPN+" in a quick arc...\n";
  break;
  case 10:
  hr = USERN+" shoulder-rolls and brings "+UPOS+" "+WEPN+" into a jab...\n";
  hm = "You shoulder-roll and bring your "+WEPN+" into a jab...\n";
  break;
  case 9:
  hr = USERN+" eases into a solid strike...\n";
  hm = "You ease into a solid strike...\n";
  break;
  case 8:
  hr = USERN+" wades into battle and delivers a series of quick swings...\n";
  hm = "You wade into battle and deliver a series of quick swings...\n";
  break;
  case 7:
  hr = USERN+" leads high and works into a low attack...\n";
  hm = "You lead high and work into a low attack...\n";
  break;
  case 6:
  hr = USERN+" leads low and works into a high attack...\n";
  hm = "You lead low and work into a high attack...\n";
  break;
  case 5:
  hr = USERN+" swings from left to right with "+UPOS+" "+WEPN+"...\n";
  hm = "You swing from left to right with your "+WEPN+"...\n";
  break;
  case 4:
  hr = USERN+" swings from right to left with "+UPOS+" "+WEPN+"...\n";
  hm = "You swing from right to left with your "+WEPN+"...\n";
  break;
  case 3:
  hr = USERN+" leaps foward and drives "+UPOS+" "+WEPN+" into a fast attack...\n";
  hm = "You leap forward and drive your "+WEPN+" into a fast attack...\n";
  break;
  case 2:
  hr = USERN+" traces the air with an 'X' shaped attack...\n";
  hm = "You trace the air with an 'X' shaped attack...\n";
  break;
  case 1:
  hr = USERN+" makes a series of quick jabs and finishes with a lunge...\n";
  hm = "You make a series of quick jabs and finish with a lunge...\n";
  break;
  }

  switch(damage){
   case 30..10000:
   hh = HIR+"BLASTED"+NORM+BOLD;
   break;
   case 26..29:
   hh = RED+"Blasted"+NORM+BOLD;
   break;
   case 22..25:
   hh = HIW+"Massacred"+NORM+BOLD;
   break;
   case 17..21:
   hh = HIW+"Struck"+NORM+BOLD;
   break;
   case 6..16:
   hh = "Hit";
   break;
   case 1..5:
   hh = "Grazed";
   break;
   case 0:
   hh = "Grazed";
   break;
   default:
   hh = "Hit";
   break;
   }
   
switch(random(10) + 1){
		case  10: where = "head"; break;
		case    9: where = "hand"; break;
		case    8: where = "arm"; break;
		case    7: where = "leg"; break;
		case    6: where = "thigh"; break;
		case    5: where = "neck"; break;
		case    4: where = "shoulder"; break;
		case    3: where = "stomach"; break;
		case    2: where = "chest"; break;
		case    1: where = "chest"; break;
	}

tell_room(environment(USER),
HIR+hr+NORM+BOLD+USERN+" "+hh+" "+ATTN+" in the "+where+"!"+NORM+"\n", ({USER}));
tell_object(USER,
HIR+"["+NORM+RED+"Strike"+BOLD+"]"+NORM+"\n"+
BOLD+hm+"You "+hh+" "+ATTN+" in the "+where+"!"+NORM+"\n");   
	msg = "";
	msg2 = "";
	msg3 = "";
   GOB->ast(16);
   GOB->set_delay(1);
	USER->spell_object(ATT, "Strike Attack", damage, spamount,
	msg, msg2, msg3);
	return 1;
}
