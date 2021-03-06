#include "/players/jaraxle/ansi.h"
#define USER environment(shadwep) 

object shadwep;
int no_wear_out;
int enchant_total;

add_shadow(object ob){
   shadwep = ob; 
   shadow(shadwep, 1); 
}

remove_shadow(){ 
   shadow(shadwep, 0); 
   destruct(this_object()); 
   return 1; 
}

short(){ return shadwep->short()+" "+HIC+"< "+HIW+"BLESSED"+HIC+" > "+NORM; }

hit(attacker){
   int dam_tot;
   dam_tot = 0;
   
   dam_tot += shadwep->hit(attacker);
   
   if(enchant_total >= 500){
      tell_object(USER, "Your "+HIW+"empowerment"+BLK+" fades"+NORM+".\n");
      remove_shadow();
   }

   if(USER && !random(3) && USER->query_alignment() >200){
      tell_room(environment(USER),
         HIW+USER->query_name()+"'s weapon flashes with Holy Might!"+NORM+"\n");
      dam_tot += random(4) + 1;
   }
   enchant_total +=random(2);
  return dam_tot, "other|water";
say("/n "+dam_tot+" /n");
}

query_shadowed() { return 1; }
