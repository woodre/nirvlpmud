Zord(){
   string msg, shortmsg;
   object pet;
   if(!PO->QMorphed()){
      write("Lord Zed tells you: You must be morphed to summon your Battlezord.\n");
      return 1;
   }
   if(PO->QZord()){
      write("You already have summoned your Battlezord.\n");
      return 1;
   }
   if(!present("ViewingWindow",environment(this_player()))){
      if(PowerPoints < (200+60*(PO->KARATE))){
         write("There is not enough power to use.\n");
         return 1;
      }
   }
   if(PowerPoints < (100+30*(PO->KARATE))){
      write("There is not enough power to use.\n");
      return 1;
   }
   if(TP->GLEVEL > 9){ msg = PO->DINO+" Servant"; shortmsg = PO->DINO+" Servant"; }
   if(TP->GLEVEL > 19){ msg = PO->DINO+", "+PO->ANIMAL+" Warrior"; shortmsg = PO->ANIMAL+" Warrior"; }
   if(TP->GLEVEL > 29){ msg = PO->ANIMAL+" Ninja"; shortmsg = PO->ANIMAL+" Ninja"; }
   if(TP->GLEVEL > 39){ msg = PO->ANIMAL+" General"; shortmsg = PO->ANIMAL+" General"; }   
   if(TP->GLEVEL > 49){ msg = "Shadow-Zord"; shortmsg = "Shadow-Zord"; }
   if(TP->GLEVEL > 59){ msg = "Stellar-Zord"; shortmsg = "Stellar-Zord"; }
   if(TP->GLEVEL > 69){ msg = "Dimensional-Zord"; shortmsg = "Dimensional-Zord"; }
   tell_room(environment(TP),TPNAME+" yells: "+msg+"\n");
   pet = clone_object("/players/beck/DarkRangers/RangerZord.c");
   pet->set_level(PO->KARATE);
   pet->set_hp(1+2*(TP->GLEVEL));
   pet->set_short("A "+shortmsg);
   pet->set_Owner(TP);
   pet->set_OwnerName(TPRNAME);
   if(TP->RangerNPC()){
      pet->set_OwnerName(TP->query_name());
   }
   pet->set_wc(3+PO->KARATE);
   pet->set_ac(random(4));
   pet->set_alt_name(PO->COLOR+"Zord");
   pet->set_message(shortmsg);
   move_object(pet, environment(this_player()));
   APowerPoints(-(100+30*(PO->KARATE)));
   if(!present("ViewingWindow",environment(this_player()))){
      APowerPoints(-(100+30*(PO->KARATE)));
   }
   PO->SZord(1);
   tell_room(environment(TP),"A "+shortmsg+" arrives.\n");
   return 1;
}
