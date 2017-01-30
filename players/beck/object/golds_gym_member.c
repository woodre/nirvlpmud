#define MEMBERDIR "players/beck/save/golds_gym/"

int arms,legs,back,waist,chest,aerobic,plyometric,strength,speed,endurance;
static int weight,sets,reps,total,max;
static string excercise,full,partial; 
static int arms_temp,legs_temp,back_temp,waist_temp,chest_temp,speed_temp;
static int aerobic_temp,plyometric_temp,strength_temp,endurance_temp;
static int in_pool,no_throw;
id(str) { return str=="gym_membership" || str=="membership"; }

short() { return "A Gold's Gym Membership"; }
long(){ 
   write("This is your Golds Gym Membership card.\n"+
   "Type 'member' to see what it can do for you.\n"+
   "");
}
query_auto_load(){ return "/players/beck/object/golds_gym_member:";} 
init_arg(){
   if(restore_object(MEMBERDIR+this_player()->query_real_name()))
      write("Reading your workouts from your training log.\n");
   else{ save_membership(); }
   return;
}
init(){   
   add_action("flex","flex");
   add_action("pose","pose");
   add_action("member","member");
   add_action("quit","quit");
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

save_membership() {
   save_object(MEMBERDIR+this_player()->query_real_name());
   write("Writing your workouts in your training log...\n");
   return 1;
}

restore_membership() {
   restore_object(MEMBERDIR+this_player()->query_real_name());
   write("Reading your workouts from your training log...\n");
   return 1;
}

flex(){
   write("You flex your muscles to everyone in the room.\n");
   say(capitalize(this_player()->query_real_name())+" begins to flex.\n"+
      "");
   return 1;
}

pose() {
   write("You pose to all the other in the room.\n"+
   "");
   say(capitalize(this_player()->query_real_name())+" starts to pose before you:\n"+
   "First flexing the biceps and chest, then tightening the abs,\n"+
   "and finally flexing the quads and calves.\n"+
   "");
   return 1;
}

member(arg) {
   if(!arg){ 
      write("Congratulations on becoming a Golds Gym Member.\n"+
      "With membership you are allowed to use anything in Golds Gym\n"+
      "located in downtown Angel Grove.\n"+
      "When you enter the gym look at the equipment located there to see\n"+
      "what you can do.\n"+
      "To see atmosphere commands you can use type 'member poses'\n"+
      "To see your evaluation sheet type 'member stats'\n"+
      "");
      return 1;
   }
   if(arg == "poses") {
      write("These are some new commands for you to try out to impress others.\n"+
      "\n"+
      "Pose       Flex\n"+
      "");
      return 1;
   }
   if(arg == "stats") {
      write("Here is a chart of your performance taken from your training log.\n"+
      "Measurements:\n"+
      "   Arms: "+(4+(query_stat("arms")/25000))+" inches.\n"+
      "\n"+
      "Fitness\n"+
      "   40 meter sprint: "+(8-(query_stat("plyometric")/125000))+" seconds.\n"+
      "   Mile: "+(7-(query_stat("aerobic")/250000))+" minutes "+
      (59-(query_stat("plyometric")/8500))+" seconds.\n"+
      "   Marathon: "+(8-(query_stat("aerobic")/125000))+" hours.\n"+
      "");
      return 1;
   }
   return 1;
}
query_no_throw(){ return no_throw; }
set_in_pool(){ in_pool = 1; }
set_out_pool(){ in_pool = 0; }
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
   no_throw = 1;
   write("What type of excercise would you like to do? ('done' to exit)\n");
   input_to("type");
   return 1;
}

type(str){
   if(str == "done"){ return 1; }
   if(str == "strength"){
      if(query_temp("strength") > 20000){
         write("You are too tired to do any strength work right now.\n");
         no_throw = 0;
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("strength_excercise");
      return 1;
   }
   if(str == "aerobic"){
      if(query_temp("aerobic") > 18000){
         write("You are too tired to do any aerobic workout right now.\n");
         no_throw = 0;
         return 1;
      }
      if(query_stat("aerobic") > 750000){
         write("You have trained to you maximum in this area.\n");
         no_throw = 0;
         return 1;
      }
      write("What excercise would you like to do?\n");
      input_to("aerobic_excercise");
      return 1;
   }
   if(str == "plyometric"){
      if(query_temp("plyometric") > 15000){
         write("You are too tired to do any plyometric work right now.\n");
         no_throw = 0;
         return 1;
      }
      if(query_stat("plyometric") > 500000){
         write("You have trained to you maximum in this area.\n");
         no_throw = 0;
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
   if(str == "bicep curl"){ full = "arms"; partial = "none"; max = 30*strength;}
   if(str == "hack squat"){ full = "legs"; partial = "none"; max = 100*strength;}
   if(str == "leg press"){ full = "legs"; partial = "none"; max = 90*strength;}
   if(str == "calf press"){ full = "legs"; partial = "none"; max = 40*strength;}
   if(str == "hamstring curl"){ full = "legs"; partial = "none"; max = 45*strength;}
   if(str == "hip extension"){ full = "legs"; partial = "none"; max = 50*strength;}
   if(str == "hip flexion"){ full = "legs"; partial = "none"; max = 40*strength;}
   if(str == "forward lunge"){ full = "legs"; partial = "none"; max = 65*strength;}
   if(str == "bench press"){ full = "chest"; partial = "arms"; max = 80*strength;}
   if(str == "dumbell fly"){ full = "chest"; partial = "none"; max = 20*strength;}
   if(str == "dip"){ full = "chest"; partial = "arms"; max = 10*strength;}
   if(str == "military press"){ full = "arms"; partial = "back"; max = 20*strength;}
   if(str == "seated cable row"){ full = "back"; partial = "waist"; max = 40*strength;}
   if(str == "dumbell row"){ full = "back"; partial = "none"; max = 25*strength;}
   if(str == "tricep press"){ full = "arms"; partial = "none"; max = 20*strength;}
   if(str == "cable crossover"){ full = "chest"; partial = "back"; max = 25*strength;}
   if(str == "crunch"){ full = "waist"; partial = "none"; max = 5*strength;}
   if(str == "back extension"){ full = "waist"; partial = "none"; max = 5*strength;}
   if(str == "lying leg raises"){ full = "waist"; partial = "none"; max = 5*strength;}
   if(str == "lat pulldown"){ full = "back"; partial = "arms"; max = 40*strength;}
   if(str == "kneeling cable crunch"){ full = "waist"; partial = "none"; max = 40*strength;}
   if(full == "none"){
      write("That is not an excercise you can do.\n");
      write("What excercise would you like to do?\n");
      input_to("strength_excercise");
      return 1;
   }
   if(in_pool == 1){
      write("You can't do that while in the pool!\n");
      no_throw = 0;
      return 1;
   }
   
   if(full == "legs"){
      if(query_temp(full) > 10000){
         write("You are too tired to work on you legs any more.\n");
         no_throw = 0;
         return 1;
      }
      if(query_stat(full) > 200000*strength){
         write("You will be out of proportion is you keep doing this\n"+
         "type of excercise without working on the other areas of your body.\n");
         no_throw = 0;      
         return 1;
      }
   }
   if(query_temp(full) > 8000){
      write("You are too tired to work on your "+full+" any more.\n");
      no_throw = 0;      
      return 1;
   }
   if(query_stat(full) > 100000*strength){
      write("You will be out of proportion is you keep doing this\n"+
      "type of excercise without working on the other areas of your body.\n");
      write("Do an excersice that hits another part of you body.\n");
      no_throw = 0;      
      return 1;
   }
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
      no_throw = 0;      
      return 1;
   }
   this_player()->add_money(-total);
   set_stat(full,query_stat(full)+total);
   set_stat(partial,query_stat(partial)+(total/3));
   set_temp(full,query_temp(full)+total);
   set_temp(partial,query_temp(partial)+(total/3));
   save_membership();
   write("For "+excercise+" you do "+sets+" sets of "+reps+" reps using "+weight+" lbs.\n");
   write("You feel stronger in the "+full+".\n");
   if(partial != "none"){
      write("You also feel a little stronger in the "+partial+".\n");
   }
   if(strength == 1){
      if(arms > 100000 && chest > 100000  && waist > 100000 && legs > 200000 && back > 100000){
         strength = 2;
      }
   }
   if(strength == 2){
      if(arms > 200000 && chest > 200000  && waist > 200000 && legs > 400000 && back > 200000){
         strength = 3;
      }
   }
   if(strength == 3){
      if(arms > 300000 && chest > 300000  && waist > 300000 && legs > 600000 && back > 300000){
         strength = 4;
      }
   }
   if(strength == 4){
      if(arms > 400000 && chest > 400000  && waist > 400000 && legs > 800000 && back > 400000){
         strength = 5;
      }
   }
   if(strength == 5){
      if(arms > 500000 && chest > 500000  && waist > 500000 && legs > 1000000 && back > 500000){
         write("Your gains are minimal you are near your maximum strength.\n");
      }
   }
   no_throw = 0;      
   return 1;
}
aerobic_excercise(str){
   full = "none";
   excercise = str;
   if(str == "done"){ return 1; }
   if(str == "treadmill"){ full = "arms"; max = 30*endurance;}
   if(str == "aerobics"){ full = "legs"; max = 30*endurance;}
   if(str == "step aerobics"){ full = "legs"; max = 30*endurance;}
   if(str == "swimming"){ full = "legs"; max = 30*endurance;}
   if(str == "water running"){ full = "legs"; max = 30*endurance;}
   if(str == "stairmaster"){ full = "legs"; max = 30*endurance;}
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
      if(in_pool == 0){
         write("You have to be in the pool to swim.\n");
         no_throw = 0;      
         return 1;
      }
   }
   if(excercise == "water running"){
      if(in_pool == 0){
         write("You have to be in the pool to do water running.\n");
         no_throw = 0;      
         return 1;
      }
   }
   if(excercise != "swimming" && excercise != "water running"){
      if(in_pool == 1){
         write("You can't do that while in the pool!\n");
         no_throw = 0;      
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
      no_throw = 0;      
      return 1;
   }
   this_player()->add_money(-total);
   set_stat("aerobic",query_stat("aerobic")+total);
   set_temp("aerobic",query_temp("aerobic")+total);
   save_membership();
   write("You do "+weight+" minutes of "+excercise+".\n");
   write("Your lungs feel stronger.\n");
   if(endurance == 1){
      if(aerobic > 250000){
         endurance = 2;
      }
   }
   if(endurance == 2){
      if(aerobic > 500000){
         endurance = 3;
      }
   }
   if(endurance == 3){
      if(aerobic > 750000){
         write("You aerobic gains are minimal, you are almost at maximum lung efficiency.\n");
      }
   }
   no_throw = 0;      
   return 1;
}

plyometric_excercise(str){
   full = "none";
   excercise = str;
   if(str == "done"){ return 1; }
   if(str == "double leg hops"){ full = "arms"; max = 20*speed;}
   if(str == "split pike jumps"){ full = "legs";  max = 20*speed;}
   if(str == "depth jumps"){ full = "legs";  max = 15*speed;}
   if(str == "standing long jumps"){ full = "legs";  max = 10*speed;}
   if(str == "standing jumps"){ full = "legs"; max = 30*speed;}
   if(str == "lateral box jumps"){ full = "legs"; max = 20*speed;}
   if(full == "none"){
      write("That is not an excercise you can do.\n");
      write("What excercise would you like to do?\n");
      input_to("plyometric_excercise");
      return 1;
   }
   if(in_pool == 1){
      write("You can't do that while in the pool!\n");
      no_throw = 0;      
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
      no_throw = 0;      
      return 1;
   }
   this_player()->add_money(-total);
   set_stat("plyometric",query_stat("plyometric")+total);
   set_temp("plyometric",query_temp("plyometric")+total);
   save_membership();
   write("You do "+sets+" sets of "+reps+" reps of "+excercise+".\n");
   write("You feel more powerful.\n");
   if(speed == 1){
      if(plyometric > 250000){
         speed = 2;
      }
   }
   if(speed == 2){
      if(plyometric > 500000){
         write("You are almost as powerful as you can get.  Your gains now are minimal.\n");
      }
   }
   no_throw = 0;      
   return 1;
}

quit(){
   save_membership();
   return;
}
