AidRanger(str){
   int cost;
   object attack;
   cost = 20;
   if(!str){
      write("You must specify a Power Ranger to aid.\n");
      return 1;
   }
   if(str == NAME){
      write("You do not need to aid yourself.\n");
      return 1;
   }
   if(!find_player(str)){
      write("Zordon tells you: "+capitalize(str)+" is not around\n");
      return 1;
   }
   if(find_player(str)->query_guild_name() != "rangers"){
      write("Zordon tells you: "+capitalize(str)+" is not a Power Ranger\n");
      return 1;
   }
   if(!find_living(str)->query_attack()){
      write("Zordon tells you: "+capitalize(str)+" is not in battle.\n");
      return 1;
   }
   if(!present(str, ENVTP)){
      if(COMM->QMorphed()){
         cost += 40;
      }
      else{
         cost += 70;
      }
      if(cost > PowerPoints){
         write("Zordon tells you: There is not enough Power.\n");
         return 1;
      }
      if(!teleport_ranger(str)){
         return 1;
      }
   }
   if(cost > PowerPoints){
      write("Zordon tells you: There is not enough Power.\n");
      return 1;
   }
   attack = present(str,ENVTP)->query_attack();
   if(!TP->valid_attack(attack)){
      write("Zordon tells you: You cannot attack that person.\n");
      return 1;
   }
   TP->attack_object(attack);
   PowerPoints -= 20;
   return 1;
}
