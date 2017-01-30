#define WC 40
#define AC 20
inherit "/obj/monster";
#include "/players/beck/MortalKombat/MKWarrior.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("Goro");
   set_race("warrior");
   set_alias("goro");
   set_short("Goro, master of Mortal Kombat");
   set_long(
      "Goro is a master at Mortal Kombat.  He is a huge creature that stands\n"+
      "8 feet tall.  He has 2 sets of arms that seem like they could kill you\n"+
      "with one blow.  He seems determined to beat you into bloody defeat.\n");
   Reset();
}

attack(){
   int i;
   int ATTCHANCE;
   i = 3;
   ATTCHANCE = 75;
   ::attack();
   while(i){
      if(ATTCHANCE > random(100)){
         already_fight = 0;
         ::attack();
      }
      i--;  
   }
} 
 
  
