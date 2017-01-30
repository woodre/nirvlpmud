
/* Used, adapted, and learned with permission from Maledicta. 
4/15/02.  */

#include "/players/maledicta/ansi.h"
#define USER environment(shadwep) 

object shadwep;
int no_wear_out;

add_shadow(object ob){
   shadwep = ob; 
   shadow(shadwep, 1); 
}

remove_shadow(){ 
   shadow(shadwep, 0); 
   destruct(this_object()); 
   return 1; 
}

short(){ return shadwep->short()+" "+YEL+"~"+HIY+"("+HIM+"Enchanted"+HIY+")"+NORM+YEL+"~"+NORM; }
long(){ write(shadwep->query_long()+"This armor has been "+HIY+"("+HIM+"Enchanted"+HIY+")"+NORM+" by a Knights Templar.\n"); }

hit(attacker){
int dam_tot;
   dam_tot = 0;
   
   dam_tot += shadwep->hit(attacker);
   
   if(USER && !random(3)){
      tell_room(environment(USER),
         HIY+USER->query_name()+"'s armor flashes!"+NORM+"\n");
      dam_tot += random(4) + 1;
   }
   return dam_tot;
}

query_shadowed() { return 1; }
