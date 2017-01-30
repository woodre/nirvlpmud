metal_armor(){
   if(!COMM->query_morphed()){
      write("You can't use your metallic armor while unmorphed.\n");
      return 1;
   }
   if(present("ranger_communicator", this_player())->query_metal_armor() == 0){
      present("ranger_communicator", this_player())->metal_armor_on();
      tell_room(environment(this_player()),CAPNAME+" yells: Mettalic Armor!\n"+CAPNAME+" yells: Power Up!\n");
      return 1;
   }
   present("ranger_communicator", this_player())->metal_armor_off();
   write("You turn your metallic armor off.\n");
   return 1;
}
metal_weapon(){
   if(!COMM->query_morphed()){
      write("You can't use your weapon while unmorphed.\n");
      return 1;
   }
   if(present("ranger_communicator",this_player())->query_metal_weapon() == 0){
      present("ranger_communicator", this_player())->metal_weapon_on();
      tell_room(environment(this_player()),CAPNAME+" yells: Power "+COMM->WEAPON+"!\n");
      return 1;
   }
   present("ranger_communicator", this_player())->metal_weapon_off();
   write("You put your weapon away.\n");
   return 1;
}
