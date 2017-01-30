inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define DAM random(8) + 18
int ammo;
reset (arg) {
if(!arg){
  set_weight(1);
  ammo = 50;
    }
  }

query_value(){ return ammo * 2; }

short(){ return ammo+" Crossbow Bolts"; }
long(){ 
write("These are bolts used for ammo in crossbows. To use them\n"+
      "you must leave them in your inventory.\n"+
      "You currently have "+ammo+" bolts.\n");
return 1;
}

id(str){ return str == "bolts"; }

query_ammo(){ return ammo; }

use_ammo(int i){
  if(ammo <= 1){
   tell_object(environment(),
   HIG+"You pull the last bolt and ready it.\n"+NORM);
   destruct(this_object());
   return DAM;
   }
  ammo -= 1;
  tell_object(environment(), 
  "You pull a bolt and place it on the crossbow...\n");
  return DAM;
  }
