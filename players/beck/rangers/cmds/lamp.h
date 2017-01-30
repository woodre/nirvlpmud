ranger_lamp(){
   if(!COMM->query_morphed()){
      write("You need to be morphed to turn on your helmet lamp.\n");
      return 1;
   }
   if(!COMM->query_ranger_lamp()){
      COMM->set_ranger_lamp(1);
      COMM->set_arm_light(2);
      write("You turn your Helmet lamp on.\n");
      say(CAPNAME+"'s Helmet begins to emit a bright beacon of light.\n");
      return 1;
   }
   COMM->set_ranger_lamp(0);
   COMM->set_arm_light(-2);
   write("You turn your Helmet lamp off.\n");
   say(CAPNAME+"'s Helmet stops emitting light.\n");
   return 1;
}
