#include "/players/guilds/warriors/sdefine.h"

main(string str, object gob, object player)
{ 

object target, comp;
int spamount; 
int cost;
int flvl;
        if(USER->query_ghost()) return 0;
        if(!GOB->get_skill(70)){
          if(USER->test_dark()){
          return 1;
          }
        } 
        if(USER->query_attack())
   		target = USER->query_attack();
	     else if(!USER->query_attack()){
	   	tell_object(USER,
		   "You can only do this in combat!\n");
		   return 1;
         }
	  if(!present(target, environment(USER))){
		  tell_object(USER,
		  "You don't see them here!\n");
		  return 1;
	     }
     if(!target->query_npc()){
        tell_object(USER,
        "You cannot do this to players!\n");
        return 1;
        }
     if(!USER->query_weapon() && !GOB->query_monk()){
        tell_object(USER,
        "You must be wielding a weapon to do that!\n");
        return 1;
        }
     cost = target->query_hp()/3;
     if(cost > USER->query_sp()){
	     tell_object(USER,
	     "You are too weak to finish them off!\n");
	     return 1;
        }
   flvl = GOB->get_skill(41);

if(USER->query_attack() && ATT->query_hp() < 50 + flvl*10){
if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
tell_object(USER,
    HIR+"          ~ [ "+HIW+"F"+RED+" ] ~ [ "+HIW+"A"+RED+" ] ~"+
    " [ "+HIW+"T"+RED+" ] ~ [ "+HIW+"A"+RED+" ] ~ [ "+HIW+"L"+RED+" ] ~"+NORM+HIW+"\n\n");
if(!GOB->query_monk()){
    switch(random(4) + 1){
    case 4:
    tell_room(environment(USER),
    USERN+" rushes forward and crushes the throat of "+ATTN+" with "+UPOS+" "+WEPN+"!\n"+
    ATTN+" falls over dead, eyes wide in horror...\n");
    break;
    case 3:
    tell_room(environment(USER),
    USERN+" leaps at "+ATTN+" and severs "+ATTN+"'s spinal cord with "+UPOS+" "+WEPN+"!\n"+
    ATTN+" screams out in pain and falls dead...\n");
    break;
    case 2:
    tell_room(environment(USER),
    USERN+" sweeps under "+ATTN+"'s attack and crushes "+ATT->POS+" chest cavity!\n"+
    ATTN+" falls to the ground gasping futilely for breath...\n");
    break;
    case 1:
    tell_room(environment(USER),
    USERN+" smashes "+ATTN+" skull in with "+UPOS+" "+WEPN+"!\n"+
    ATTN+" falls with a dull thud...\n");
    break;
    }
}
else{
switch(random(4) + 1){
    case 4:
    tell_room(environment(USER),
    USERN+" rushes forward and crushes the throat of "+ATTN+" with "+UPOS+" bare hands!\n"+
    ATTN+" falls over dead, eyes wide in horror...\n");
    break;
    case 3:
    tell_room(environment(USER),
    USERN+" leaps at "+ATTN+" and severs "+ATTN+"'s spinal cord with "+UPOS+" bare hands!\n"+
    ATTN+" screams out in pain and falls dead...\n");
    break;
    case 2:
    tell_room(environment(USER),
    USERN+" sweeps under "+ATTN+"'s attack and crushes "+ATT->POS+" chest cavity!\n"+
    ATTN+" falls to the ground gasping futilely for breath...\n");
    break;
    case 1:
    tell_room(environment(USER),
    USERN+" smashes "+ATTN+" skull in with "+UPOS+" bare hands!\n"+
    ATTN+" falls with a dull thud...\n");
    break;
    }
}
    GOB->ast(41);
    GOB->ast(41);
    tell_object(USER, NORM+"\n");
    USER->add_spell_point(-cost);
    target->heal_self(-(target->query_hp()));
    target->hit_player(USER->query_level() * 100);
    return 1;
  }
 tell_object(USER, "Your opponent is still too strong.\n");
       	return 1;
 }
 tell_object(USER, "Your opponent is still too strong.\n");
       	return 1;
}
