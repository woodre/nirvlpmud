MorphNinja(){
   string msg;
   if(COMM->QMorphed()){
      write("You can not become a Ninja while Morphed.\n");
      return 0;
   }
   if(!COMM->QNinja()){
      if(PowerPoints < 40){
         write("There is not enouph power for you to morph.\n");
         return 1;
      }
      APowerPoints(-40);
      msg = CAPNAME+" yells: "+COMM->COLOR+" Ninja Power!\n"; 
      tell_room(ENVTP, msg);
      COMM->SOldPretitle(this_player()->query_pretitle());
      COMM->SOldTitle(this_player()->query_title());
      this_player()->set_pretitle("|");
      this_player()->set_title("The "+COMM->COLOR+" Ninja");
      COMM->ASkillExp(50);
      COMM->SNinja();
      return 1;
   }
   if(COMM->QNinja()){
      write("You are already a ninja.\n");
      return 1;
   }
   return 0;
}
