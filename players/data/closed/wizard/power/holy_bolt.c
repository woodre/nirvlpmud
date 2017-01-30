/* Holy Bolt [12.18.00]  Does damage to undead types, and heals 
   players hit with it. cost is skill lvl *2 +5 and does equal
   damage or heals in hps for the same amount. NOTE: This is a
   selfless power, in other words, you cannot heal yourself with
   it but only other players!  Will only hurt undead type!  */

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{

object target;
int dose;
dose = GOB->query_skills(93);

   if(USER->query_ghost()) return 1;
   if(!GOB->check_align("good")){
      tell_object(USER, "You are not good!\n");
      return 1;
      }
   if(GOB->query_hdelay()){
      tell_object(USER, "You have already cast it this round!\n");
      return 1;
      }
   if(USER->query_sp() < 5 + (dose * 2) || GOB->query_end() < 10){
      tell_object(USER,"You are too weak to cast.\n");
      return 1;
      }  
    
   if(!str && USER->query_attack())
		target = USER->query_attack();
	else if(str)
		target = present(str, environment(USER));

	else if(!str && !USER->query_attack()){
            tell_object(USER,"hbolt who?\n");
		return 1;
            }
     if(!target && str){
		tell_object(USER,
		"You don't see "+str+" here.\n");
		return 1;
	      }
     if(!present(target, environment(USER))){
		tell_object(USER,
      	"You don't see them here!\n");
		return 1;
	      }
     if(target == USER){
            tell_object(USER, "You cannot cast holy bolt at yourself!\n");
            return 1;
            }
     if(!living(target)){
		tell_object(USER,
		"You cannot hbolt that!\n");
		return 1;
	      }
      
GOB->set_hdelay(1);
USER->add_spell_point(-(5 + (dose * 2)));
GOB->add_end(-10);
if(target->is_npc() && undead_check(target)){
 tell_object(USER, 
 HIB+"["+HIW+"HolyBolt"+HIB+"]"+NORM+" You summon forth holy energies to strike the undead.\n"+
 target->query_name()+" is slammed in the chest!\n");
 tell_room(environment(USER),
 USERN+" fires a blue bolt of holy energy at "+target->query_name()+"!\n", ({USER}));
 target->heal_self(-(5 + (dose * 2)));
 if(target->query_attack() != USER){
 target->attack_object(USER);
 }
 return 1;
 }
else if(target->is_player()){
 tell_object(USER, 
 HIB+"["+HIW+"HolyBolt"+HIB+"]"+NORM+" You summon forth holy energies.\n"+
 target->query_name()+" is slammed in the chest and heals!\n");
 tell_room(environment(USER),
 USERN+" fires a blue bolt of holy energy at "+target->query_name()+"!\n", ({USER}));
 target->add_hit_point(random(6) + (dose * 2));
 }
else{
 tell_object(USER,
 HIB+"["+HIW+"HolyBolt"+HIB+"]"+NORM+" You summon forth holy energies.\n"+
 target->query_name()+" is slammed in the chest and ignores the strike!\n");
 tell_room(environment(USER),
 USERN+" fires a blue bolt of holy energy at "+target->query_name()+"!\n", ({USER}));
 return 1;
 }
return 1;
}

undead_check(ob){
if(call_other(ob,"id", "undead") || call_other(ob, "id", "skeleton") ||
   call_other(ob, "id", "spirit") || call_other(ob, "id", "wraith") ||
   call_other(ob, "id", "dracula") || call_other(ob, "id", "vampire") ||
   call_other(ob, "id", "zombie") || call_other(ob, "id", "banshee") ||
   call_other(ob, "id", "ghost") || call_other(ob, "id", "revenant") ||
   call_other(ob, "id", "mummy") || call_other(ob, "id", "dracolich") ||
   call_other(ob, "id", "lich") || call_other(ob, "id", "ghoul") ||
   call_other(ob, "id", "frankenstein") || call_other(ob, "id", "corpse"))
   return 1;
else return 0;
}
