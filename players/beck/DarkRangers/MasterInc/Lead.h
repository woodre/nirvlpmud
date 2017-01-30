lead_battle(){
   object attack;
   if(!TP->query_attack()){
      write("You are not attacking anyone.\n");
      return 1;
   }
   if(PowerPoints < 20){
      write("There is not enough power in the guild to aid you.\n");
      return 1;
   }
   attack = TP->query_attack();
   TP->attack_object(attack);
   attack->attack_object(TP);
   tell_room(environment(TP),TPNAME+
      " finds the courage to fight "+attack->NAME+" harder.\n");
   APowerPoints(-20);
   PO->ASkillExp(10);
   PO->ACombatExp(10);
   return 1;
}
