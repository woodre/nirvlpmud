inherit "obj/treasure";

#include "/players/jaraxle/ansi.h"

#define DAM random(6) + 18  /* Longbow  */

#define DAM2 random(4) + 17 /* Shortbow */

int ammo;

reset (arg) {

if(!arg){

  set_weight(1);

  ammo = 50;

    }

  }



query_value(){ return ammo * 1; }



short(){ return ammo+" Arrows"; }

long(){ 

write("These are long wooden arrows with steel tips. They are\n"+

      "for ammo with a bow. You must have them in your inventory\n"+

      "in order to use them.\n");

return 1;

}



id(str){ return str == "arrows"; }



query_ammo(){ return ammo; }



use_ammo(int i){

  if(ammo <= 1){

   tell_object(environment(),

   HIG+"You pull the last arrow and knock it.\n"+NORM);

   destruct(this_object());

   return DAM;

   }

  ammo -= 1;

  tell_object(environment(), 

  "You pull an arrow and knock it on the bow's string...\n");

  return DAM;

  }



use_ammo2(int i){

  if(ammo <= 1){

   tell_object(environment(),

   HIG+"You pull the last arrow and knock it.\n"+NORM);

   destruct(this_object());

   return DAM2;

   }

  ammo -= 1;

  tell_object(environment(), 

  "You pull an arrow and knock it on the bow's string...\n");

  return DAM2;

  }

