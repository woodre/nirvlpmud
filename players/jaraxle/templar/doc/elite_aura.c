
/* Used, adapted, and learned with permission from Maledicta. 
4/15/02.  */

#include "/players/jaraxle/define.h"
#define USER environment(shadwep) 
#define ATT USER->query_attack()

object shadwep;
int no_wear_out;
int elite;

add_shadow(object ob){
   shadwep = ob; 
   shadow(shadwep, 1); 
}

remove_shadow(){ 
   shadow(shadwep, 0); 
   destruct(this_object()); 
   return 0;
}

short()
{
   if(shadwep)
      return shadwep->short() +" ["+HIW+"glimmering"+NORM+"]";
}

do_special(owner)
{
   int i;
   i = random(4);
   if(!ATT) return shadwep->do_special();
   if(ATT->is_npc() && ATT->query_alignment() > 500){
      tell_room(environment(USER),capitalize(USER->query_name())+"'s holy enchantment explodes!\n");
      USER->add_hp(-10-random(11));
      shadow(shadwep, 0); 
      destruct(this_object());
      return 0; }
   if(i==1){
      if(ATT->is_npc())
/*
         ATT->hit_player("other|holy", 5+random(3));
*/
        ATT->hit_player(5+random(3));
      if(ATT->query_alignment() < 0 && USER->query_alignment() > 750){
         tell_room(environment(USER), capitalize(USER->query_name())+"'s shield flashes with "+HIW+"Holy Light"+NORM+"!\n");
         USER->add_hp(2+random(3));
      }
/*
      else ATT->hit_player("other|holy", 3+random(5));
*/
     else ATT->hit_player(3+random(5));
      tell_room(environment(USER),
         "\t"+HIW+"The Light of the Righteous"+NORM+" shines brightly off "+capitalize(USER->query_name())+"'s shield.\n");
      if(ATT) tell_room( environment(USER),
         "\t"+capitalize(ATT->query_name())+" is blinded by the "+HIW+"light"+NORM+"!\n");
      return shadwep->do_special();
   }
   return shadwep->do_special(); }
query_shadowed() { return 1; }
