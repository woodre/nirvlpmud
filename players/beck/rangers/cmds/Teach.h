TeachRanger(str){
   string person, power;
   object trainee;
   if(!str){
      write("Please use format 'teach <person> <skillname>'.\n");
      return 1;
   }
   if(sscanf(str, "%s %s", person, power) == 2) {
      if(!COMM->CheckSkills(power)){
         write(power+" is not a skill you can teach.\n");
         return 1;
      }
      if(!present(person, environment(this_player()))){
         write("That person is not here.\n");
         return 1;
      }
      trainee = present(person, environment(this_player()));
      if(!present("RangerCommunicator",trainee)){
         write(person+" is not a Power Ranger.\n");
         return 1;
      }
      present("RangerCommunicator",trainee)->TrainRanger(CAPNAME,power);
write("You try and teach "+power+" to "+person+".\n");
      return 1;
   }
   write("Please use format 'teach <person> <skillname>'.\n");
   return 1;
}