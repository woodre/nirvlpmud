
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

short()
{
    if(shadwep)
       return shadwep->short() + " "+HIY+"^"+HIR+"enchanted"+HIY+"^"+NORM;
}

do_special(attacker){
int dam_tot;
dam_tot = 0;

dam_tot += shadwep->hit(attacker);

if(USER && !random(3) && USER->query_alignment() >  1){
   tell_room(environment(USER),
   HIR+USER->query_name()+"'s weapon erupts into flames!"+NORM+"\n");
   dam_tot += random(4) + 1;
  }
return dam_tot;
}

query_shadowed() { return 1; }
