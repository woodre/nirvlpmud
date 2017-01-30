call_blaster(){
   object room;
   object room2;
   int n;
   int damage;
   object attacker;
   if(power_points < 50){
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
      if(present("ranger_communicator", room)){
         if(present("ranger_communicator", room)->query_morphed()){
            if(room->query_attack() == attacker){
               n = n + 1;
            }
         }
      }
   }
   if(n > 4){
      for(room2 = first_inventory(environment(this_player())); room2; room2 = next_inventory(room2)){
         if(present("ranger_communicator", room2)){
            if(present("ranger_communicator", room2)->query_morphed()){
               if(room2->query_attack() == attacker){
                  tell_room(environment(this_player()), capitalize(room2->query_real_name())+
                     " yells: Power "+
                     present("ranger_communicator", room2)->query_ranger_weapon()+"!\n");
                  damage += present("ranger_communicator", room2)->query_karate_level();
               }
            }
          }
      }
      tell_room(environment(this_player()), "The Power Rangers yell: Power Blaster...Power Up!\n");
      attacker->hit_player(damage);
      add_power_points(-50);
      return 1;
   }
   write("There are not enough Power Rangers attacking the same person.\n");
   return 1;
}
