lead_battle(string type){
   object attack;
  /* write() changed to notify_fail() here */
 /* verte 6.6.01 bleh! */
   if(!TP->query_attack()){
      notify_fail("You are not attacking anyone.\n");
      return 0;
   }
   if(QPowerPoints(type) < 20){ 
      write("There is not enough power in the guild to aid you.\n");
      return 1;
   }
   attack = TP->query_attack();
   TP->attack_object(attack);
   attack->attack_object(TP);
   tell_room(environment(TP),TPNAME+
      " finds the courage to fight "+attack->NAME+" harder.\n");
   APowerPoints(-20,type);
   PO->ASkillExp(10);
   PO->ACombatExp(10);
   return 1;
}
