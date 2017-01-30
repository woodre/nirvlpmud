Blast(string type){
   int n; 
   int damage;
   object attacker;
   if(!COMM->QMorphed()){
      write("You don't even have a blaster while unmorphed.\n");
      return 1;
   }
   if(QPowerPoints(type) < (TP->GLEVEL*2)){
      write("Not enough power to use your blaster.\n");
      return 1;
   }
   if(COMM->QRangerPoints() < (TP->GLEVEL*2)){
      write("You have not donated enough power to use this.\n");
      return 1;
   }
   if(!this_player()->query_attack()){
      write("You are not attacking anyone.\n");
      return 1;
   }
   attacker = TP->query_attack();
   if(attacker->is_player() && !present(GLOBE,ENV(TP))){
      write("You can not use blast on a player here.\n");
      return 1;
   }
   APowerPoints(-(TP->GLEVEL*2),type);
   COMM->ARangerPoints(-(TP->GLEVEL*2));
   tell_object(TP,"[ "+BOLD+RED+"BLASTER"+OFF+" ] You shoot "+attacker->NAME+" with your Blaster.\n");
   tell_object(attacker,TP->NAME+" shoots you with a blaster.\n");
   attacker->hit_player((TP->GLEVEL)/2);
   COMM->ACombatExp(15);
   COMM->ASkillExp(10);
   return 1;
}
