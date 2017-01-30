double_kick(str){
   object other;
   object attacker;
   int damage;
   int strength1;
   int strength2;
   if(!this_player()->query_attack()){
      write("You aren't attacking anyone.\n");
      return 1;
   }
   if(!present(str, environment(this_player()))){
      write(str+" is not here.\n");
      return 1;
   }
   other = present(str, environment(this_player()));
   if(!present("ranger_communicator",other)){
      write(str+" is not a power ranger.\n");
      return 1;
   }
   if(other == this_player()){
      write("Trying to play with yourself?\n");
      return 1;
   }
   if(power_points < 20){
      write("There is not enough power to use.\n");
      return 1;
   }
   attacker = this_player()->query_attack();
   tell_room(environment(this_player()), CAPNAME+" yells: 'Hiya', and leaps toward "+attacker->query_name()+"\n");
   tell_room(environment(this_player()),capitalize(str)+" yells: 'Hiya', and leaps toward "+attacker->query_name()+"\n");
   tell_room(environment(this_player()),CAPNAME+" and "+capitalize(str)+" kick "+attacker->query_name()+" in the chest.\n");
   add_power_points(-20);
   damage = COMM->query_karate_level();
   damage += present("ranger_communicator",other)->query_karate_level();
   strength1 = COMM->query_strength();
   strength2 = present("ranger_communicator", other)->query_strength();
   damage += random(strength1);
   damage += random(strength2);
   attacker->hit_player(damage);
   return 1;
}
