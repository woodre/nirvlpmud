#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"

RangerPower(string str, string type){
   object attack;
  /* write() changed to notify_fail() here */
 /* verte 6.6.01 bleh! */
   if(!TP->query_attack()){
      notify_fail("You are not attacking anyone.\n");
      return 0;
   }
   if(MASTER->QPowerPoints(type) < 20){ 
      write("There is not enough power in the guild to aid you.\n");
      return 1;
   }
   attack = TP->query_attack();
   TP->attack_object(attack);
   attack->attack_object(TP);
   tell_room(environment(TP),TPNAME+
      " finds the courage to fight "+attack->NAME+" harder.\n");
   MASTER->APowerPoints(-20,type);
   return 1;
}

QRangerInfo(){ return 1; }

RangerInfo(){
   write("Lead allows you take the lead in battle and prevent other people from\n"+
         "taking enemy hits.\n"+
         "Lead consumes 20 Power Points.\n"+
         "");
   return 1;
}