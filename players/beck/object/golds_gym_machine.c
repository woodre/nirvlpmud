#include "/players/beck/rangers/Defs.h"
id(str){
   return str == "machines" || str == "golds_gym_machine";
}

short(){
   return "Various Workout and Fitness Machines";
}
long(){
   write("These are various machines desgined to increase your fitness.\n"+
      "You see stairmasters, treadmills, and several other aerobic and\n"+
      "resistance excercise machines all around.  To see what machines\n"+
      "and more specifically what kind of excercises you can do type 'list'.\n"+
      "To workout type 'workout'.  You will answer questions.\n"+
      "");
}
init(){
   add_action("list","list");
   add_action("workout","workout");
}
list(){
   write(""+
      "*****************************GOLDS GYM**********************************\n"+
      "This is a list of excercises you can do here at Golds Gym.\n"+
      "The headers are the TYPE of excercise you are doing.\n"+
      "Cost for all strength excercise is 1 coin per lb. per rep per set.\n"+
      "(Total cost is weight*reps*sets  100 lbs. * 10 reps * 3 sets = 3000 coins)\n"+
      "Cost for aerobic excercise is 100 coins per minute.\n"+
      "Cost for plyometric excercise is 100 coins * reps * sets.\n"+
      "\n"+
      "Strength\n"+                        
      "   Leg Press   Hack Squat   Hamstring Curl   Forward Lunge\n"+
      "   Hip Extension   Hip Flexion   Calf Press\n"+                      
      "   Bench Press   Dumbell Fly   Dip   Cable Crossover\n"+
      "   Military Press   Seated Cable Row   Dumbell Row   Lat Pulldown\n"+
      "   Bicep Curl   Tricep Press   Back Extension\n"+
      "   Crunch   Lying Leg Raise   Kneeling Cable Crunch\n"+
      "Aerobic\n"+
      "   Treadmill   Stairmaster   Aerobics   Step Aerobics   Swimming\n"+
      "   Nordic Track   Rowing Machine   Fitness Cycle   Water Running\n"+
      "Plyometric\n"+
      "   Double Leg Hops   Split Pike Jumps   Depth Jumps\n"+
      "   Standing Jumps   Standing Long Jumps   Lateral Box Jumps\n"+
      "");
   return 1;
}

int arms,legs,back,waist,chest,aerobic,plyometric,strength,speed,endurance;
static int weight,sets,reps,total,max;
static string excercise,full,partial; 
static int arms_temp,legs_temp,back_temp,waist_temp,chest_temp,speed_temp;
static int aerobic_temp,plyometric_temp,strength_temp,endurance_temp;
static int in_pool,no_throw;



set_stat(arg,num){
   if(arg == "strength") strength = num;
   if(arg == "speed") speed = num;
   if(arg == "endurance") endurance = num;
   if(arg == "arms") arms = num;
   if(arg == "legs") legs = num;
   if(arg == "chest") chest = num;
   if(arg == "back") back = num;
   if(arg == "waist") waist = num;
   if(arg == "plyometric") plyometric = num;
   if(arg == "aerobic") aerobic = num;
   return 1;
}
set_temp(arg,num){
   if(arg == "strength") strength_temp = num;
   if(arg == "speed") speed_temp = num;
   if(arg == "endurance") endurance_temp = num;
   if(arg == "arms") arms_temp = num;
   if(arg == "legs") legs_temp = num;
   if(arg == "chest") chest_temp = num;
   if(arg == "back") back_temp = num;
   if(arg == "waist") waist_temp = num;
   if(arg == "plyometric") plyometric_temp = num;
   if(arg == "aerobic") aerobic_temp = num;
   return 1;
}

query_stat(arg){
   if(arg == "strength") return strength;
   if(arg == "speed") return speed;
   if(arg == "endurance") return endurance;
   if(arg == "arms") return arms;
   if(arg == "legs") return legs;
   if(arg == "chest") return chest;
   if(arg == "back") return back;
   if(arg == "waist") return waist;
   if(arg == "plyometric") return plyometric;
   if(arg == "aerobic") return aerobic;
}
query_temp(arg){
   if(arg == "strength") return strength_temp;
   if(arg == "speed") return speed_temp;
   if(arg == "endurance") return endurance_temp;
   if(arg == "arms") return arms_temp;
   if(arg == "legs") return legs_temp;
   if(arg == "chest") return chest_temp;
   if(arg == "back") return back_temp;
   if(arg == "waist") return waist_temp;
   if(arg == "plyometric") return plyometric_temp;
   if(arg == "aerobic") return aerobic_temp;
}

workout(){
   if(present("DarkRangerCommunicator",TP)){
      present("DarkRangerCommunicator",TP)->workout();
      return 1;
   }
   else{
      COMM->workout();
   }
   /*
   COMM->SNoThrow(1);
   write("What type of excercise would you like to do? ('done' to exit)\n");
   input_to("type");
   */
   return 1;
}

type(str){
   if(str == "done"){ return 1; }
   if(str == "strength"){
      if(COMM->QRangerStrengthTemp() > 20000){
         write("You are too tired to do any strength work right now.\n");
         COMM->SNoThrow(0);
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("strength_excercise");
      return 1;
   }
   if(str == "aerobic"){
      if(COMM->QRangerEnduranceTemp() > 18000){
         write("You are too tired to do any aerobic workout right now.\n");
         COMM->SNoThrow(0);
         return 1;
      }
      if(COMM->QRangerEndurance() > 750000){
         write("You have trained to you maximum in this area.\n");
         COMM->SNoThrow(0);
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("aerobic_excercise");
      return 1;
   }
   if(str == "plyometric"){
      if(COMM->QRangerSpeedTemp() > 15000){
         write("You are too tired to do any plyometric work right now.\n");
         COMM->SNoThrow(0);
         return 1;
      }
      if(COMM->QRangerSpeed() > 500000){
         write("You have trained to you maximum in this area.\n");
         COMM->SNoThrow(0);
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
      COMM->SNoThrow(0);
      return 1;
   }
   
   /*
   if(full == "legs"){
      if(query_temp(full) > 10000){
         write("You are too tired to work on you legs any more.\n");
         COMM->SNoThrow(0);
         return 1;
      }
      if(query_stat(full) > 200000*strength){
         write("You will be out of proportion is you keep doing this\n"+
            "type of excercise without working on the other areas of your body.\n");
         COMM->SNoThrow(0);      
         return 1;
      }
   }
   if(query_temp(full) > 8000){
      write("You are too tired to work on your "+full+" any more.\n");
      COMM->SNoThrow(0);      
      return 1;
   }
   if(query_stat(full) > 100000*strength){
      write("You will be out of proportion is you keep doing this\n"+
         "type of excercise without working on the other areas of your body.\n");
      write("Do an excersice that hits another part of you body.\n");
      COMM->SNoThrow(0);      
      return 1;
   }
   */
   write("How much weight (in lbs.) would you like to use?\n");
   input_to("strength_weight");
   return 1;
}

strength_weight(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", weight) !=1){
      write("You have to choose an amount.\n");
      write("How much weight (in lbs.) would you like to use?\n");
      input_to("strength_weight");
      return 1;
   }
   if(weight > max){
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
   total = sets*reps*weight;
   if(this_player()->query_money() < total){
      write("You don't have enough money to train that amount.\n");
      COMM->SNoThrow(0);      
      return 1;
   }
   this_player()->add_money(-total);
   COMM->ARangerStrength(total);
   COMM->ARangerStrengthTemp(total);
   write("For "+excercise+" you do "+sets+" sets of "+reps+" reps using "+weight+" lbs.\n");
   write("You feel stronger in the "+full+".\n");
   if(partial != "none"){
      write("You also feel a little stronger in the "+partial+".\n");
   }
   COMM->SNoThrow(0);      
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
   if(str == "rowing machine"){ full = "legs"; max = 30*strength;}
   if(str == "fitness cycle"){ full = "legs"; max = 30*strength;}
   if(str == "nordic track"){ full = "chest"; max = 30*strength;}
   if(full == "none"){
      write("That is not an excercise you can do.\n");
      write("What excercise would you like to do?\n");
      input_to("aerobic_excercise");
      return 1;
   }
   if(excercise == "swimming"){
      if(!environment(this_player())->is_pool()){
         write("You have to be in the pool to swim.\n");
         COMM->SNoThrow(0);      
         return 1;
      }
   }
   if(excercise == "water running"){
      if(!environment(this_player())->is_pool()){
         write("You have to be in the pool to do water running.\n");
         COMM->SNoThrow(0);      
         return 1;
      }
   }
   if(excercise != "swimming" && excercise != "water running"){
      if(environment(this_player())->is_pool()){
         write("You can't do that while in the pool!\n");
         COMM->SNoThrow(0);      
         return 1;
      }
   }
   write("How many minutes would you like to workout?\n");
   input_to("aerobic_time");
   return 1;
}

aerobic_time(num){
   if(num == "done"){ return 1; }
   if(sscanf(num, "%df", weight) !=1){
      write("You have to choose an amount.\n");
      write("How many minutes would you like to workout?\n");
      input_to("aerobic_time");
      return 1;
   }
   if(weight == 0){
      write("You have to workout at least 1 minute.\n");
      write("How many minutes would you like to workout?\n");  
      input_to("aerobic_time");
      return 1;
   }
   if(weight > max){
      write("You aren't able to workout that long.\n");
      write("How many minutes would you like to workout?\n");
      input_to("aerobic_time");
      return 1;
   }
   total = weight*100;
   if(this_player()->query_money() < total){
      write("You don't have enough money to train that amount.\n");
      COMM->SNoThrow(0);      
      return 1;
   }
   this_player()->add_money(-total);
   COMM->ARangerEndurance(total);
   COMM->ARangerEnduranceTemp(total);
   write("You do "+weight+" minutes of "+excercise+".\n");
   write("Your lungs feel stronger.\n");
   COMM->SNoThrow(0);      
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
      COMM->SNoThrow(0);      
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
      COMM->SNoThrow(0);      
      return 1;
   }
   this_player()->add_money(-total);
   COMM->ARangerSpeed(total);
   COMM->ARangerSpeedTemp(total);
   write("You do "+sets+" sets of "+reps+" reps of "+excercise+".\n");
   write("You feel more powerful.\n");
   COMM->SNoThrow(0);      
   return 1;
}

