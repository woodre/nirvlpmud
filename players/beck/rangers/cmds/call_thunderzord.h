call_thunderzord(str){
   object room;
   object room2;
   int n;
   if(power_points < 100){
      write("There are not enough power points to call a thunderzord.\n");
      return 1;
   }
   n = 0;
   if(!COMM->query_need_megazord()){
      write("You have no need.\n");
      return 1;
   }
   if(COMM->query_has_thunderzord()){
      write("You have already called your Thunderzord.\n");
      return 1;
   }
   for(room = first_inventory(environment(this_player())); room; room = next_inventory(room)){
      if(present("ranger_communicator", room)){
         if(present("ranger_communicator", room)->query_has_thunderzord() == 1){
            n = n + 1;
         }
       }
   }
   if(n > 3){
      tell_room(environment(this_player()), capitalize(this_player()->query_real_name())+
         " yells: "+present("ranger_communicator", this_player())->query_ranger_animal()+
         ", "+present("ranger_communicator", this_player())->query_ranger_thunderzord()+
         " Thunderzord Power!\n");
      move_object("/players/beck/rangers/thunder_megazord.c", environment(this_player()));
      for(room2 = first_inventory(environment(this_player())); room2; room2 = next_inventory(room2)){
         if(present("ranger_communicator", room2)){
            if(present("ranger_communicator", room2)->query_has_thunderzord() == 1){
               present("ranger_communicator", room2)->set_need_megazord(0);
               present("ranger_communicator", room2)->set_has_thunderzord(0);
               call_other(room2,"move_player","megazord#/players/beck/rangers/thunder_megazord.c");
               command("look", room2);
               room2 = first_inventory(environment(this_player()));
            }
         }
      }
      add_power_points(-100);
      COMM->set_need_megazord(0);
      call_other(this_player(),"move_player","megazord#/players/beck/rangers/thunder_megazord.c");
      tell_room(environment(environment(this_player())),"The Power Rangers yell: Thunder Megazord...Power Up!\n");
      return 1;
   }
   COMM->set_has_thunderzord(1);
   tell_room(environment(this_player()), CAPNAME+
      " yells: "+COMM->ANIMAL+", "+COMM->THUNDER+" Thunderzord Power!\n");
   add_power_points(-100);
   return 1;
}
