/*
*  Allows the ranger to teleport to certain locations.
*/
teleport_ranger(str){
   string destination;
   if(!str){write("Teleport where?\n"); return 1;}
   if(!COMM->query_morphed()){
      if(power_points < 50){
         write("There is not enough power to teleport you.\n");
         return 1;
      }
   }
   if(power_points < 25){
      write("There is not enough power to teleport you.\n");
      return 1;
   }
   if(environment(this_player())->realm() == "NT"){
      write("Zordon tells you:  I can't seem to pinpoint your location there.\n");
      return 1;
   }
   destination = "none";
   if(str=="church"){ destination = "teleport#/room/church.c"; }
   if(str=="command center"){ destination = "teleport#/players/beck/room/headqtr.c"; }
   if(str=="park"){ destination = "teleport#/players/beck/room/park.c"; }
   if(destination != "none"){   
      tell_room(environment(this_player()),CAPNAME+
         " becomes a mass of "+COMM->COLOR+
         " light.\n"+"The light then rockets into the sky and disappears"+
         " out of sight.\n"+
         "");
      call_other(this_player(),"move_player",destination);
      tell_room(environment(this_player()),"A brilliant display of "+
         COMM->COLOR+" light beams into the room.\n"+
         "");
      add_power_points(-25);
      if(!COMM->query_morphed()){
         add_power_points(-25);
      }
      return 1;
   }
   if(!find_living(str)){
      write("You can't teleport there.\n");
      return 1;
   }
   if(!present("ranger_communicator", find_living(str))){
      write("You can't teleport to that person.\n");
      return 1;
   }
   if(environment(find_living(str))->realm() == "NT"){
      write("Zordon tells you: I can't pinpoint that ranger's location for you.\n");
      return 1;
   }
   tell_room(environment(this_player()),CAPNAME+
      " becomes a mass of "+COMM->COLOR+
      " light.\n"+"The light then rockets into the sky and disappears"+
      " out of sight.\n"+
      "");
   move_object(this_player(), environment(find_living(str)));
   tell_room(environment(this_player()),"A brilliant display of "+
      COMM->COLOR+" light beams into the room.\n"+
      "");
   command("look", this_player());
   add_power_points(-25);
   if(!COMM->query_morphed()){
      add_power_points(-25);
   }
   return 1;
}
