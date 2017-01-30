unmorph_ranger(){
   if(!COMM){
      write("Only a Power Ranger is allowed to unmorph.\n");
      return 1;
   }
   if(!COMM->query_morphed()){
      return 0;
   }
   write("You return to your boring, everyday self.\n");
   this_player()->set_title(COMM->query_old_title());
   this_player()->set_pretitle(COMM->query_old_pretitle());
   if(COMM->query_ranger_lamp()){
COMM->set_ranger_lamp(0);
      COMM->set_arm_light(-2);
   }
   COMM->morph_off();
   return 1;
}
