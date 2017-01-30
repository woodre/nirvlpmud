int EXPCOST;
int GEXP;

train_ranger(name,type,cost,guild,gold){
   if(ENV->query_guild_name() != "rangers"){ return 0; }
   if(ENV->query_money() < gold){
      tell_object(ENV, "You don't have enough gold.\n");
      return 0;
   }
   if(type == "karate_level"){
      if(query_karate_level() == 0){ EXPCOST = 5900; GEXP = 200; }
      if(query_karate_level() == 1){ EXPCOST = 11000; GEXP = 400; }
      if(query_karate_level() == 2){ EXPCOST = 30000; GEXP = 800; }
      if(query_karate_level() == 3){ EXPCOST = 78000; GEXP = 1600; }
      if(query_karate_level() == 4){ EXPCOST = 120000; GEXP = 3200; }
      if(query_karate_level() == 5){ EXPCOST = 210000; GEXP = 6400; }
      if(query_karate_level() == 6){ EXPCOST = 360000; GEXP = 12800; }
      if(query_karate_level() == 7){ EXPCOST = 500000; GEXP = 25600; }
      if(query_karate_level() == 8){ EXPCOST = 810000; GEXP = 51200; }
      if(query_karate_level() == 9){ EXPCOST = 1000000; GEXP = 90000; }
      if(query_karate_level() > 9){
         write("You've trained to your maximum strength.\n");
         return 0;
      }
      if(skill_exp()){
         set_karate_level(query_karate_level() + 1);
         ENV->add_exp(-EXPCOST);
         ENV->add_guild_exp(EXPCOST);
         ENV->add_guild_rank(1);
         ENV->add_money(-gold);
         tell_object(ENV,"You have succcesfully completed your test and may advance to the \n"+
         "level of your training.\n");
         save_ranger();
         init();
         return 1;
      }
   }
   if(type == "skill"){
      EXPCOST = cost;
      GEXP = guild;
      if(skill_exp()){
         if(add_skill(name)){
            tell_object(ENV, 
            "You have learned "+name+".  This will help your all-around skills.\n");
            ENV->add_exp(-EXPCOST);
            ENV->add_guild_exp(EXPCOST);
            ENV->add_money(-gold);
            save_ranger();
            init();
            return 1;
         }
      }  
   }
   if(type == "offense"){
      EXPCOST = cost;
      GEXP = guild;
      if(skill_exp()){
         if(add_offense(name)){
            tell_object(ENV, 
            "You have learned "+name+".  This will help your offensive combat.\n");
            ENV->add_guild_exp(EXPCOST);
            ENV->add_exp(-EXPCOST);
            ENV->add_money(-gold);
            save_ranger();
            init();
            return 1;
         }
      } 
   }
   if(type == "defense"){
      EXPCOST = cost;
      GEXP = guild;
      if(skill_exp()){
         if(add_defense(name)){
            tell_object(ENV, 
            "You have learned "+name+".  This will help your defensive combat.\n");
            ENV->add_exp(-EXPCOST);
            ENV->add_guild_exp(EXPCOST);
            ENV->add_money(-gold);
            save_ranger();
            init();
            return 1;
         }
      }
   }
   return 0;
}

skill_exp(){
   int level;
   int exp;
   int level_exp;
   exp = ENV->query_exp();
   level = ENV->query_level();
   if(level > 19){ EXPCOST = 0; GEXP = 0; return 1; }  
   if(skill_practice < GEXP){
      tell_object(ENV,"You do not have enough overall practice yet.\n");
      return 0;
   }
   if(level == 1){ level_exp = 0; }
   if(level == 2){ level_exp = 1014; }
   if(level == 3){ level_exp = 1771; }
   if(level == 4){ level_exp = 2332; }
   if(level == 5){ level_exp = 5885; }
   if(level == 6){ level_exp = 12812; }
   if(level == 7){ level_exp = 26662; }
   if(level == 8){ level_exp = 39993; }
   if(level == 9){ level_exp = 59995; }
   if(level == 10){ level_exp = 90000; }
   if(level == 11){ level_exp = 134998; }
   if(level == 12){ level_exp = 195591; }
   if(level == 13){ level_exp = 295592; }
   if(level == 14){ level_exp = 492294; }
   if(level == 15){ level_exp = 620026; }
   if(level == 16){ level_exp = 820028; }
   if(level == 17){ level_exp = 1040028; }
   if(level == 18){ level_exp = 1367106; }
   if(level == 19){ level_exp = 2000000; }
   if((exp - level_exp) > EXPCOST){ return 1;}
   tell_object(ENV,"You don't have enough experience yet.\n");
   return 0;
}
