
/* Used, adapted, and learned with permission from Maledicta. 
4/15/02.  */

#include "/players/maledicta/ansi.h"
#define USER environment(shadwep) 

object enc_obj;
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

query_real_arm_short() {
   string x;
   if(!shadwep) return;
   x=shadwep->query_name();
   if(!x) x = shadwep->query_type();
}

long(){ write(shadwep->query_long()+"This armor has been "+HIY+"("+HIM+"Enchanted"+HIY+")"+NORM+" by a Knights Templar.\n"); }


query_shadowed() { return 1; }

drop()
{
   if(environment() == this_player())
      write(HIY + "The enchantment upon your " + query_real_arm_short() + " has ended.\n" + NORM);
   shadow(shadwep, 0);
   if(enc_obj) enc_obj->stop();
   shadwep->drop();
   return destruct(this_object());
}

set_enc_obj(x) { enc_obj=x; }

query_shad_wep() { return shadwep; }
