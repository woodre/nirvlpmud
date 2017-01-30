/*
*  Allows the ranger to teleport to certain locations.
*/
teleport_ranger(str){
   string destination;
   if(!str){write("Teleport where?\n"); return 1;}
   if(!PO->QMorphed()){
      if(PowerPoints < 80){
         write("There is not enough power to teleport you.\n");
         return 0;
      }
   }
   if(PowerPoints < 60){
      write("There is not enough power to teleport you.\n");
      return 0;
   }
   if(environment(TP)->realm() == "NT"){
      write("Lord Zed tells you:  I can't seem to pinpoint your location there.\n");
      return 0;
   }
   destination = "none";
   if(str=="church"){ destination = "teleport#/room/church.c"; }
   if(str=="castle"){ destination = "teleport#/players/beck/DarkRangers/Room/ZedChamber.c"; }
   if(str=="park"){ destination = "teleport#/players/beck/room/park5.c"; }
   if(destination != "none"){   
      tell_room(environment(this_player()),TPNAME+
         " becomes a mass of "+PO->COLOR+
         " light.\n"+"The light then rockets into the sky and disappears"+
         " out of sight.\n"+
         "");
      call_other(TP,"move_player",destination);
      tell_room(environment(TP),"A brilliant display of "+
         PO->COLOR+" light beams into the room.\n"+
         "");
      APowerPoints(-60);
      if(!PO->QMorphed()){
         APowerPoints(-20);
      }
      PO->ASkillExp(10);
      return 1;
   }
   write("Player to player teleports are currently disabled.\n");
   return 0;
   if(!find_living(str)){
      write("You can't teleport there.\n");
      return 0;
   }
   if(!present("DarkRangerCommunicator", find_living(str))){
      write("You can't teleport to that person.\n");
      return 0;
   }
   if(environment(find_living(str))->realm() == "NT"){
      write("Lord Zed tells you: I can't pinpoint that ranger's location for you.\n");
      return 0;
   }
   if(PowerPoints < 100){
      write("There is not enough Power to teleport you to that person.\n");
      return 0;
   }
   tell_room(environment(TP),TPNAME+
      " becomes a mass of "+PO->COLOR+
      " light.\n"+"The light then rockets into the sky and disappears"+
      " out of sight.\n"+
      "");
   move_object(this_player(), environment(find_living(str)));
   tell_room(environment(this_player()),"A brilliant display of "+
      PO->COLOR+" light beams into the room.\n"+
      "");
   command("look", this_player());
   APowerPoints(-100);
   PO->ASkillExp(10);
   return 1;
}
