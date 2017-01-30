morph_ranger(){
   object ok;
   if(!COMM->query_morphed()){
      if(power_points < 100){
         write("There is not enouph power for you to morph.\n");
         return 1;
      }
      add_power_points(-100);
      tell_room(environment(this_player()),CAPNAME+" shouts: It's Morphin' Time!\n"+CAPNAME+" shouts: "+COMM->ANIMAL+"!\n");
      COMM->set_old_pretitle(this_player()->query_pretitle());
      COMM->set_old_title(this_player()->query_title());
      this_player()->set_pretitle("|");
      if(member_array(this_player()->query_real_name(), LEADERS) != -1){
         this_player()->set_pretitle("Power Ranger Team Leader: ");
      }
      this_player()->set_title("The "+esc+COMM->ANSI+COMM->COLOR+OFF+" Ranger");
      COMM->morph_on();
      return 1;
   }
   if(COMM->query_morphed()){
      write("You are already morphed.\n");
         return 1;
   }
   return 0;
}
