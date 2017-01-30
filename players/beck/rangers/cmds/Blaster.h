call_blaster(){
   object room;
   object room2;
   int n;
   int damage;
   object attacker;
   if(PowerPoints < 50){
      write("Not enough power to use the blaster.\n");
      return 1;
   }
   if(!this_player()->query_attack()){
      write("You are not attacking anyone.\n");
      return 1;
   }
   n = 0;
   damage = 0;
   attacker = this_player()->query_attack();
   for(room = first_inventory(environment(this_player())); room; room = next_inventory(room)){
      if(present("RangerCommunicator", room)){
         if(present("RangerCommunicator", room)->QMorphed()){
            if(room->query_attack() == attacker){
               n = n + 1;
            }
         }
       }
   }
   if(n > 4){
      for(room2 = first_inventory(environment(this_player())); room2; room2 = next_inventory(room2)){
         if(present("RangerCommunicator", room2)){
            if(present("RangerCommunicator", room2)->QMorphed()){
               if(room2->query_attack() == attacker){
                  tell_room(environment(this_player()), capitalize(room2->query_real_name())+
                     " yells: Power "+
                     present("RangerCommunicator", room2)->QRangerWeapon()+"!\n");
                  damage += present("RangerCommunicator", room2)->QKarateLevel();
               }
            }
          }
      }
      tell_room(environment(this_player()), "The Power Rangers yell: Power Blaster...Power Up!\n");
      attacker->hit_player(damage);
      APowerPoints(-50);
      COMM->ACombatExp(10);
      COMM->ASkillExp(5);
      return 1;
   }
   write("There are not enough Power Rangers attacking the same person.\n");
   return 1;
}
