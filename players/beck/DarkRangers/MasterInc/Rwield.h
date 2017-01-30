Rwield(str){
   object weapon;
   int can_wield;
   can_wield = 0;
   if(!str){ 
      write("What do you want to wield?\n");
      return 1;
   }
   if(!present(str,TP)){
      write("You don't have "+str+" in your possesion.\n");
      return 1;
   }
   if(PO->QPowerWeapon()){
      write("You are already wielding a Power Weapon.\n");
      return 1;
   }
   if(PowerPoints < 40){
      write("There is not enough power to also use a weapon.\n");
      return 1;
   }
   weapon = present(str,TP);
   PO->NotWeapon();
   weapon->wield(str);
   if(weapon->query_wielded()){
      if(PO->PrevWeapon()){
         (PO->PrevWeapon())->restore_thing("players/beck/Rangers/CommInc/Weapon2");
         PO->SPrevWeapon(0);
      }
      can_wield = 1;
   }
   TP->wield(PO,1);
   if(can_wield){
      PO->SWeapon(weapon);
      weapon->restore_thing("players/beck/Rangers/CommInc/Weapon");
      APowerPoints(-40);
   }
   PO->NotWeapon();
   return 1;
}
