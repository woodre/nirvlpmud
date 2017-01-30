call_battlezord(){
   object pet;
   if(!COMM->query_morphed()){
      write("Zordon tells you: You must be morphed to summon your Battlezord.\n");
      return 1;
   }
   if(COMM->query_has_battlezord()){
      write("You already have summoned your Battlezord.\n");
      return 1;
   }
   if(!present("viewing_globe",environment(this_player()))){
      if(power_points < (200+60*(COMM->query_karate_level()))){
         write("There is not enough power to use.\n");
         return 1;
      }
   }
   if(power_points < (100+30*(COMM->query_karate_level()))){
      write("There is not enough power to use.\n");
      return 1;
   }
tell_room(environment(this_player()),CAPNAME+" yells: "+COMM->COLOR+" Ranger Battlezord!\n");
   pet = clone_object("/players/beck/rangers/ranger_battlezord.c");
   pet->set_level(1+COMM->query_karate_level());
   pet->set_hp(80+10*(COMM->query_karate_level()));
   pet->set_short("A "+COMM->COLOR+" Battlezord");
   pet->set_Owner(this_player());
   pet->set_OwnerName(NAME);
   pet->set_wc(8+COMM->query_karate_level());
   pet->set_ac(2+COMM->query_karate_level());
   move_object(pet, environment(this_player()));
   add_power_points(-(100+30*(COMM->query_karate_level())));
   if(!present("viewing_globe",environment(this_player()))){
      add_power_points(-(100+30*(COMM->query_karate_level())));
   }
   COMM->set_has_battlezord(1);
   tell_room(environment(this_player()),"A "+COMM->COLOR+" Battlezord arrives.\n");
   return 1;
}
