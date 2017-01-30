/*************************************************************************
 *  Function to convert Golds Gym training to ranger function.                                                                     *
 *                                                                       *
 *                                                                       *
 *************************************************************************/

convert_gym_stats(){
   if(!present("gym_membership",this_player())){
      write("You have to be a member of Golds Gym to use this.\n");
      return 1;
   }
   if(COMM->query_strength() < 5){
      if(COMM->query_strength() < present("gym_membership",this_player())->query_stat("strength")){
         COMM->set_strength(present("gym_membership",this_player())->query_stat("strength"));
         write("You increase your Strength.\n");
         return 1;
      }
   }
   if(COMM->query_speed() < 2){
      if(COMM->query_speed() < present("gym_membership",this_player())->query_stat("speed")){
         COMM->set_speed(present("gym_membership",this_player())->query_stat("speed"));
         write("You increase your Speed.\n");
         return 1;
      }
   }
   if(COMM->query_endurance() < 5){
      if(COMM->query_endurance() < present("gym_membership",this_player())->query_stat("endurance")){
         COMM->set_endurance(present("gym_membership",this_player())->query_stat("endurance"));
         write("You increase your Endurance.\n");
         return 1;
      }
   }
   if(COMM->query_strength() == 5 && COMM->query_speed() == 2 && COMM->query_endurance() == 3){
      write("You have reached the maximum amount you are all allowed to train.\n");
      return 1;
   }
   write("You need to go to Golds Gym and workout more.\n");
   return 1;
}
