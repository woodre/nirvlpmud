MorphRanger(){
   int cost;
   int i;
   string title;
   string name;
   string msg;
   if(PO->QNinja()){
      write("You can not Morph while you are a Ninja.\n");
      return 1;
   }
   if(!PO->QMorphed()){
      if(TP->GLEVEL > 9){ msg = TPNAME+" yells: "+PO->DINO+"!\n"; cost = 100; }
      if(TP->GLEVEL > 29){ msg = TPNAME+" yells: "+PO->COLOR+" Warrior Power!\n"; cost = 150; }
if(TP->GLEVEL > 39){ msg = TPNAME+" yells: "+PO->COLOR+" General Power!\n"; cost = 200; }
      if(TP->GLEVEL > 49){ msg = "Fade to Shadow!\n"; cost = 250; }
      if(TP->GLEVEL > 69){ msg = TPNAME+" yells: Let's Rocket!\n"; cost = 300; }
      if(PowerPoints < cost){
         write("There is not enouph power for you to morph.\n");
         return 1;
      }
      APowerPoints(-cost);
      /*
      "obj/user/one_chan.c"->chan_msg(""+
         "The sky lights up a bright "+PO->COLOR+".\n"+
         "A bolt of lightning flashes down and strikes at "+
         environment(TP)->short()+".\n"+
         "When the smoke clears, the "+PO->COLOR+" Ranger appears.\n"+
         "","junk");
      */
      tell_room(ENVTP, TPNAME+" yells: It's Morphin' Time!\n"+msg);
      PO->SOldPretitle(TP->query_pretitle());
      PO->SOldTitle(TP->query_title());
      TP->set_pretitle("|");
      if(member_array(TP->RNAME, LEADERS) != -1){
         this_player()->set_pretitle("Dark Ranger Team Leader: ");
      }
      title = BS;
      for(i=0; i<strlen(TPNAME); i++){
         title += BS;
      }
      /*  The following was Ok'd by Boltar under conditions that all other actions are still noted as being the players
      */
      TP->set_title(title+"The Dark "+PO->COLOR+" Ranger");
      /* The following was deemed illegal and cannot be used - Beck
      present("soul",TP)->setmin(title+"The "+COMM->COLOR+" Ranger arrives");
      present("soul",TP)->setmout(title+"The "+COMM->COLOR+" Ranger leaves");
      */
      PO->ASkillExp(30);
      PO->SMorphed();
      return 1;
   }
   if(PO->QMorphed()){
      write("You are already morphed.\n");
      return 1;
   }
   return 0;
}
