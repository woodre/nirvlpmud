Rwear(str){
   object armor;
   if(!str){ 
      write("What do you want to wear?\n");
      return 1;
   }
   if(!present(str,TP)){
      write("You don't have "+str+" in your possesion.\n");
      return 1;
   }
   if(PowerPoints < 20){
      write("There is not enough power to also wear armor.\n");
      return 1;
   }
   armor = present(str,TP);
   if(armor->query_type() != "ring" && armor->query_type() != "shield"){
      write("You can not wear that type of armor.\n");
      return 1;
   }
   armor->set_ac(0);
   PO->NotArmor();
   armor->wear(str);
   if(armor->query_worn()){
      APowerPoints(-20);
   }
   PO->NotArmor();
   return 1;
}
