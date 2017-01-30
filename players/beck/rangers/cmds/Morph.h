MorphRanger(){
   int cost;
   int i;
   string title;
   string name;
   string msg;
   if(COMM->QNinja()){
      write("You can not Morph while you are a Ninja.\n");
      return 1;
   }
   if(!COMM->QMorphed()){
      if(TP->GLEVEL > 9){ msg = CAPNAME+" yells: "+COMM->DINO+"!\n"; cost = 100; }
      if(TP->GLEVEL > 29){ msg = CAPNAME+" yells: "+COMM->COLOR+" Ranger Power!\n"; cost = 150; }
      if(TP->GLEVEL > 39){ msg = CAPNAME+" yells: Zeo Ranger "+COMM->NUMBER+", "+COMM->COLOR+"!\n"; cost = 200; }
      if(TP->GLEVEL > 49){ msg = "Shift into Turbo!\n"; cost = 250; }
      if(PowerPoints < cost){
         write("There is not enouph power for you to morph.\n");
         return 1;
      }
      APowerPoints(-cost);
      "obj/user/one_chan.c"->chan_msg(""+
         "The sky lights up a bright "+COMM->COLOR+".\n"+
         "A bolt of lightning flashes down and strikes at "+
         environment(TP)->short()+".\n"+
         "When the smoke clears, the "+COMM->COLOR+" Ranger appears.\n"+
         "","junk");
      tell_room(ENVTP, CAPNAME+" yells: It's Morphin' Time!\n"+msg);
      COMM->SOldPretitle(this_player()->query_pretitle());
      COMM->SOldTitle(this_player()->query_title());
      this_player()->set_pretitle("|");
      if(member_array(this_player()->query_real_name(), LEADERS) != -1){
         this_player()->set_pretitle("Power Ranger Team Leader: ");
      }
      title = BS;
      for(i=0; i<strlen(NAME); i++){
         title += BS;
      }
/*  The following was Ok'd by Boltar under conditions that all other actions are still noted as being the players
*/
      TP->set_title(title+"The "+COMM->COLOR+" Ranger");
/* The following was deemed illegal and cannot be used - Beck
      present("soul",TP)->setmin(title+"The "+COMM->COLOR+" Ranger arrives");
      present("soul",TP)->setmout(title+"The "+COMM->COLOR+" Ranger leaves");
*/
      COMM->ASkillExp(30);
      COMM->SMorphed();
      return 1;
   }
   if(COMM->QMorphed()){
      write("You are already morphed.\n");
      return 1;
   }
   return 0;
}
