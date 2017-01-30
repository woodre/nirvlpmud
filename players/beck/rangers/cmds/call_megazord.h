call_megazord(){
   object room;
   object room2;
   int n;
   n = 0;
   if(find_living("ranger_megazord")){
      write("Other rangers are already using the thunder megazord.\n");
      return 1;
   }
   if(present("ranger_communicator", this_player())->query_need_megazord() == 1){
      write("The megazord has already been called.\n");
      return 1;
   }
   for(room = first_inventory(environment(this_player())); room; room = next_inventory(room)){
      if(present("ranger_communicator",room)){
         if(present("ranger_communicator", room)->query_morphed() == 1){
            n = n + 1;
         }
       }
   }
   if(n > 4){
      for(room2 = first_inventory(environment(this_player())); room2; room2 = next_inventory(room2)){
         if(present("ranger_communicator", room2)){
            present("ranger_communicator", room2)->set_need_megazord(1);
          }
      }
      tell_room(environment(this_player()), capitalize(this_player()->query_real_name())+" yells: We need Thunder Megazord Power!\n");
      return 1;
   }
   write("There are not enough morphed rangers to call the Thunder Megazord.\n");
   return 1;
}
