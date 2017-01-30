AidRanger(str, string type){
   int cost;
   object attack;
   cost = 20;
   if(!str){
      write("You must specify a "+type+" to aid.\n");
      return 1;
   }
   if(str == TPRNAME){ 
      write("You do not need to aid yourself.\n");
      return 1;
   }
   if(!find_player(str)){
      write(capitalize(str)+" is not around\n");
      return 1;
   }
   if(type == "Power Ranger" && find_player(str)->query_guild_name() != "rangers"){
      write("Zordon tells you: "+capitalize(str)+" is not a Power Ranger\n");
      return 1;
   }
   if(type == "Dark Ranger" && find_player(str)->query_guild_name() != "dark rangers"){
      write("Lord Zed tells you: "+capitalize(str)+" is not a Dark Ranger\n");
      return 1;
   }

   if(!find_living(str)->query_attack()){
      write(capitalize(str)+" is not in battle.\n");
      return 1;
   }
   if(!present(str, ENVTP)){
      if(PO->QMorphed()){
         cost += 40;
      }
      else{
         cost += 70;
      }
      if(cost > QPowerPoints(type)){
         write("There is not enough Power.\n");
         return 1;
      }
      if(!teleport_ranger(str)){
         return 1;
      }
   }
   if(cost > QPowerPoints(type)){
      write("There is not enough Power.\n");
      return 1;
   }
   attack = present(str,ENVTP)->query_attack();
   if(!TP->valid_attack(attack)){
      write("You cannot attack that person.\n");
      return 1;
   }
   TP->attack_object(attack);
   APowerPoints(-20,type);
   return 1;
}
