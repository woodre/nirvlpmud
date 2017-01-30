Zord(){
   string msg, shortmsg;
   object pet;
   if(!COMM->QMorphed()){
      write("Zordon tells you: You must be morphed to summon your Battlezord.\n");
      return 1;
   }
   if(COMM->QZord()){
      write("You already have summoned your Battlezord.\n");
      return 1;
   }
   if(!present("ViewingGlobe",environment(this_player()))){
      if(PowerPoints < (200+60*(COMM->KARATE))){
         write("There is not enough power to use.\n");
         return 1;
      }
   }
   if(PowerPoints < (100+30*(COMM->KARATE))){
      write("There is not enough power to use.\n");
      return 1;
   }
   if(TP->GLEVEL > 9){ msg = COMM->DINO+" Dinozord Power"; shortmsg = COMM->DINO+" Dinozord"; }
   if(TP->GLEVEL > 19){ msg = COMM->DINO+", "+COMM->ANIMAL+" Thunderzord Power"; shortmsg = COMM->ANIMAL+" Thunderzord"; }
   if(TP->GLEVEL > 29){ msg = COMM->ANIMAL+" Ninjazord Power"; shortmsg = COMM->ANIMAL+" Ninjazord"; }
   if(TP->GLEVEL > 39){ msg = COMM->ANIMAL+" Zeozord"; shortmsg = COMM->ANIMAL+" Zeozord"; }   
   if(TP->GLEVEL > 49){ msg = "Turbozord"; shortmsg = "Turbozord"; }
   if(TP->GLEVEL > 59){ msg = "Rescue-zord"; shortmsg = "Rescue-zord"; }
   tell_room(environment(TP),CAPNAME+" yells: "+msg+"\n");
   pet = clone_object("/players/beck/rangers/RangerZord.c");
   pet->set_level(COMM->KARATE);
   pet->set_hp(1+2*(TP->GLEVEL));
   pet->set_short("A "+shortmsg);
   pet->set_Owner(this_player());
   pet->set_OwnerName(NAME);
   if(TP->RangerNPC()){
      pet->set_OwnerName(TP->query_name());
   }
   pet->set_wc(3+COMM->KARATE);
pet->set_ac(random(4));
   pet->set_alt_name(COMM->COLOR+"Zord");
   pet->set_message(shortmsg);
   move_object(pet, environment(this_player()));
   APowerPoints(-(100+30*(COMM->KARATE)));
   if(!present("ViewingGlobe",environment(this_player()))){
      APowerPoints(-(100+30*(COMM->KARATE)));
   }
   COMM->SZord(1);
   tell_room(environment(TP),"A "+shortmsg+" arrives.\n");
   return 1;
}
