
static int weightaa,sets,reps,total,max;
static string excercise,full,partial; 
static int no_throw;
QNoThrow(){ return no_throw; }
SNoThrow(arg){ no_throw = arg; return 1; }

workout(){
   SNoThrow(1);
   write("What type of excercise would you like to do? ('done' to exit)\n");
   input_to("type");
   return 1;
}

type(str){
   if(str == "done"){ return 1; }
   if(str == "strength"){
      if(QRangerStrengthTemp() > 20000){
         write("You are too tired to do any strength work right now.\n");
         SNoThrow(0);
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("strength_excercise");
      return 1;
   }
   if(str == "aerobic"){
      if(QRangerEnduranceTemp() > 18000){
         write("You are too tired to do any aerobic workout right now.\n");
         SNoThrow(0);
         return 1;
      }
      if(QRangerEndurance() > 750000){
         write("You have trained to you maximum in this area.\n");
         SNoThrow(0);
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("aerobic_excercise");
      return 1;
   }
   if(str == "plyometric"){
      if(QRangerSpeedTemp() > 15000){
         write("You are too tired to do any plyometric work right now.\n");
         SNoThrow(0);
         return 1;
      }
      if(QRangerSpeed() > 500000){
         write("You have trained to you maximum in this area.\n");
         SNoThrow(0);
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("plyometric_excercise");
      return 1;
   }
   
   write("That is not a type of excercise you can do.\n");
   write("What type of excercise would you like to do?\n");
   input_to("type");
   return 1;
}
strength_excercise(str){
   full = "none";
   excercise = str;
   if(str == "done"){ return 1; }
   if(str == "bicep curl"){ full = "arms"; partial = "none"; max = 30*8;}
   if(str == "hack squat"){ full = "legs"; partial = "none"; max = 100*8;}
   if(str == "leg press"){ full = "legs"; partial = "none"; max = 90*8;}
   if(str == "calf press"){ full = "legs"; partial = "none"; max = 40*8;}
   if(str == "hamstring curl"){ full = "legs"; partial = "none"; max = 45*8;}
   if(str == "hip extension"){ full = "legs"; partial = "none"; max = 50*8;}
   if(str == "hip flexion"){ full = "legs"; partial = "none"; max = 40*8;}
   if(str == "forward lunge"){ full = "legs"; partial = "none"; max = 65*8;}
   if(str == "bench press"){ full = "chest"; partial = "arms"; max = 80*8;}
   if(str == "dumbell fly"){ full = "chest"; partial = "none"; max = 20*8;}
   if(str == "dip"){ full = "chest"; partial = "arms"; max = 10*8;}
   if(str == "military press"){ full = "arms"; partial = "back"; max = 20*8;}
   if(str == "seated cable row"){ full = "back"; partial = "waist"; max = 40*8;}
   if(str == "dumbell row"){ full = "back"; partial = "none"; max = 25*8;}
   if(str == "tricep press"){ full = "arms"; partial = "none"; max = 20*8;}
   if(str == "cable crossover"){ full = "chest"; partial = "back"; max = 25*8;}
   if(str == "crunch"){ full = "waist"; partial = "none"; max = 5*8;}
   if(str == "back extension"){ full = "waist"; partial = "none"; max = 5*8;}
   if(str == "lying leg raises"){ full = "waist"; partial = "none"; max = 5*8;}
   if(str == "lat pulldown"){ full = "back"; partial = "arms"; max = 40*8;}
   if(str == "kneeling cable crunch"){ full = "waist"; partial = "none"; max = 40*8;}
   if(full == "none"){
      write("That is not an excercise you can do.\n");
      write("What excercise would you like to do?\n");
      input_to("strength_excercise");
      return 1;
   }
   if(environment(this_player())->is_pool()){
      write("You can't do that while in the pool!\n");
      SNoThrow(0);
      return 1;
   }
   
   /*
   if(full == "legs"){
      if(query_temp(full) > 10000){
         write("You are too tired to work on you legs any more.\n");
         SNoThrow(0);
         return 1;
      }
      if(query_stat(full) > 200000*strength){
         write("You will be out of proportion is you keep doing this\n"+
            "type of excercise without working on the other areas of your body.\n");
         SNoThrow(0);      
         return 1;
      }
   }
   if(query_temp(full) > 8000){
      write("You are too tired to work on your "+full+" any more.\n");
      SNoThrow(0);      
      return 1;
   }
   if(query_stat(full) > 100000*strength){
      write("You will be out of proportion is you keep doing this\n"+
         "type of excercise without working on the other areas of your body.\n");
      write("Do an excersice that hits another part of you body.\n");
      SNoThrow(0);      
      return 1;
   }
   */
   write("How much weight (in lbs.) would you like to use?\n");
   input_to("strength_weight");
   return 1;
}

strength_weight(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", weightaa) !=1){
      write("You have to choose an amount.\n");
      write("How much weight (in lbs.) would you like to use?\n");
      input_to("strength_weight");
      return 1;
   }
   if(weightaa > max){
      write("You aren't able to lift that much weight with this excercise.\n");
      write("How much weight (in lbs.) would you like to use?\n");   
      input_to("strength_weight");
      return 1;
   }
   write("How many reps would you like to do?\n");
   input_to("strength_reps");
   return 1;
}

strength_reps(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", reps) !=1){
      write("You have to choose an amount.\n");
      write("How many reps would you like to do?\n");
      input_to("strength_reps");
      return 1;
   }
   if(reps == 0){
      write("You have to do at least 1 rep.\n");
      write("How many reps would you like to do?\n");
      input_to("strength_reps");
      return 1;
   }
   if(reps > 30){
      write("You can't do more than 30 reps per set.\n");
      write("How many reps would you like to do?\n");
      input_to("strength_reps");
      return 1;
   }
   write("How many sets would you like to do?\n");
   input_to("strength_sets");
   return 1;
}
strength_sets(num){
   if(num == "done"){ return 1; } 
   if(sscanf(num, "%df", sets) !=1){
      write("You have to choose an amount.\n");
      write("How many sets would you like to do?\n");
      input_to("strength_sets");
      return 1;
   }
   if(sets == 0){
      write("You have to do at least 1 set.\n");
      write("How many sets would you like to do?\n");
      input_to("strength_sets");
      return 1;
   }
   if(sets > 5){
      write("You can't do more than 5 sets.\n");
      write("How many sets would you like to do?\n");
      input_to("strength_sets");
      return 1;
   }
   if(sets*reps > 60){
      write("That is too many sets for the amount of reps you are doing.\n");
      write("How many sets would you like to do?\n");
      input_to("strength_sets");
      return 1;
   }
   total = sets*reps*weightaa;
   if(this_player()->query_money() < total){
      write("You don't have enough money to train that amount.\n");
      SNoThrow(0);      
      return 1;
   }
   this_player()->add_money(-total);
   ARangerStrength(total);
   ARangerStrengthTemp(total);
   write("For "+excercise+" you do "+sets+" sets of "+reps+" reps using "+weightaa+" lbs.\n");
   write("You feel stronger in the "+full+".\n");
   if(partial != "none"){
      write("You also feel a little stronger in the "+partial+".\n");
   }
   SNoThrow(0);      
   return 1;
}
aerobic_excercise(str){
   full = "none";
   excercise = str;
   if(str == "done"){ return 1; }
   if(str == "treadmill"){ full = "arms"; max = 30*8;}
   if(str == "aerobics"){ full = "legs"; max = 30*8;}
   if(str == "step aerobics"){ full = "legs"; max = 30*8;}
   if(str == "swimming"){ full = "legs"; max = 30*8;}
   if(str == "water running"){ full = "legs"; max = 30*8;}
   if(str == "stairmaster"){ full = "legs"; max = 30*8;}
   if(str == "rowing machine"){ full = "legs"; max = 30*8;}
   if(str == "fitness cycle"){ full = "legs"; max = 30*8;}
   if(str == "nordic track"){ full = "chest"; max = 30*8;}
   if(full == "none"){
      write("That is not an excercise you can do.\n");
      write("What excercise would you like to do?\n");
      input_to("aerobic_excercise");
      return 1;
   }
   if(excercise == "swimming"){
      if(!environment(this_player())->is_pool()){
         write("You have to be in the pool to swim.\n");
         SNoThrow(0);      
         return 1;
      }
   }
   if(excercise == "water running"){
      if(!environment(this_player())->is_pool()){
         write("You have to be in the pool to do water running.\n");
         SNoThrow(0);      
         return 1;
      }
   }
   if(excercise != "swimming" && excercise != "water running"){
      if(environment(this_player())->is_pool()){
         write("You can't do that while in the pool!\n");
         SNoThrow(0);      
         return 1;
      }
   }
   write("How many minutes would you like to workout?\n");
   input_to("aerobic_time");
   return 1;
}

aerobic_time(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", weightaa) !=1){
      write("You have to choose an amount.\n");
      write("How many minutes would you like to workout?\n");
      input_to("aerobic_time");
      return 1;
   }
   if(weightaa == 0){
      write("You have to workout at least 1 minute.\n");
      write("How many minutes would you like to workout?\n");  
      input_to("aerobic_time");
      return 1;
   }
   if(weightaa > max){
      write("You aren't able to workout that long.\n");
      write("How many minutes would you like to workout?\n");
      input_to("aerobic_time");
      return 1;
   }
   total = weightaa*100;
   if(this_player()->query_money() < total){
      write("You don't have enough money to train that amount.\n");
      SNoThrow(0);      
      return 1;
   }
   this_player()->add_money(-total);
   ARangerEndurance(total);
   ARangerEnduranceTemp(total);
   write("You do "+weightaa+" minutes of "+excercise+".\n");
   write("Your lungs feel stronger.\n");
   SNoThrow(0);      
   return 1;
}

plyometric_excercise(str){
   full = "none";
   excercise = str;
   if(str == "done"){ return 1; }
   if(str == "double leg hops"){ full = "arms"; max = 20*8;}
   if(str == "split pike jumps"){ full = "legs";  max = 20*8;}
   if(str == "depth jumps"){ full = "legs";  max = 15*8;}
   if(str == "standing long jumps"){ full = "legs";  max = 10*8;}
   if(str == "standing jumps"){ full = "legs"; max = 30*8;}
   if(str == "lateral box jumps"){ full = "legs"; max = 20*8;}
   if(full == "none"){
      write("That is not an excercise you can do.\n");
      write("What excercise would you like to do?\n");
      input_to("plyometric_excercise");
      return 1;
   }
   if(environment(this_player())->is_pool()){
      write("You can't do that while in the pool!\n");
      SNoThrow(0);      
      return 1;
   }
   
   write("How many reps would you like to do?\n");
   input_to("plyometric_reps");
   return 1;
}

plyometric_reps(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", reps) !=1){
      write("You have to choose an amount.\n");
      write("How many reps would you like to do?\n");
      input_to("plyometric_reps");
      return 1;
   }
   if(reps == 0){
      write("You have to do at least 1 rep.\n");
      write("How many reps would you like to do?\n");
      input_to("plyometric_reps");
      return 1;
   }
   if(reps > max){
      write("You can't do that many reps per set.\n");
      write("How many reps would you like to do?\n");
      input_to("plyometric_reps");
      return 1;
   }
   write("How many sets would you like to do?\n");
   input_to("plyometric_sets");
   return 1;
}
plyometric_sets(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", sets) !=1){
      write("You have to choose an amount.\n");
      write("How many sets would you like to do?\n");
      input_to("plyometric_sets");
      return 1;
   }
   if(sets == 0){
      write("You have to do at least 1 set.\n");
      write("How many sets would you like to do?\n");
      input_to("plyometric_sets");
      return 1;
   }
   if(sets > 5){
      write("You can't do more than 5 sets.\n");
      write("How many sets would you like to do?\n");
      input_to("plyometric_sets");
      return 1;
   }
   if(sets*reps > 60){
      write("That is too many sets for the amount of reps you are doing.\n");
      write("How many sets would you like to do?\n");
      input_to("plyometric_sets");
      return 1;
   }
   total = sets*reps*100;
   if(this_player()->query_money() < total){
      write("You don't have enough money to train that amount.\n");
      SNoThrow(0);      
      return 1;
   }
   this_player()->add_money(-total);
   ARangerSpeed(total);
   ARangerSpeedTemp(total);
   write("You do "+sets+" sets of "+reps+" reps of "+excercise+".\n");
   write("You feel more powerful.\n");
   SNoThrow(0);      
   return 1;
}

