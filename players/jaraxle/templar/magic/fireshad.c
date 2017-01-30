
#include "/players/jaraxle/define.h"
#define ATT USER->query_attack()
#define USER environment(shadwep) 

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
   return 1; 
}

short()
{
   if(shadwep)
     return shadwep->short() +" ["+HIW+"glimmering"+NORM+"]";
}

do_special(owner)
{
   int i;
   i = random(2);
    if(!ATT) return;
   if(ATT->query_alignment() > 500){
      tell_room(environment(USER),capitalize(USER->query_name())+"'s holy enchantment explodes!\n");
      USER->hit_player(10+random(11));
      shadow(shadwep, 0); 
      destruct(this_object());
      return 1; }
   if(i==1){
      if(ATT->is_npc())
         ATT->hit_player(5+random(3));
      if(ATT->query_alignment() < 0 && USER->query_alignment() > 750){
         tell_room(environment(USER), capitalize(USER->query_name())+"'s shield flashes with "+HIW+"Holy Light"+NORM+"!\n");
         USER->add_hp(2+random(3));
      }
      else ATT->hit_player(3+random(5));
      tell_room(environment(USER),
"\t"+HIW+"The Light of the Righteous"+NORM+" shines brightly off "+capitalize(USER->query_name())+"'s shield.\n"+
"\t"+capitalize(ATT->query_name())+" is blinded by the "+HIW+"light"+NORM+"!\n");
      return 0;}
   return 0;}

query_shadowed() { return 1; }
