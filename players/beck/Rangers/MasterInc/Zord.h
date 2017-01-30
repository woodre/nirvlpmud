Zord(string type){
   string msg, shortmsg;
   object pet;
   if(!PO->QMorphed()){
      write("Zordon tells you: You must be morphed to summon your Battlezord.\n");
      return 1;
   }
   if(PO->QZord()){
      write("You already have summoned your Battlezord.\n");
      return 1;
   }
   if(!present("ViewingGlobe",environment(this_player()))){
      if(QPowerPoints(type) < (200+60*(PO->KARATE))){
         write("There is not enough power to use.\n");
         return 1;
      }
   }
   if(QPowerPoints(type) < (100+30*(PO->KARATE))){
      write("There is not enough power to use.\n");
      return 1;
   }
   if(TP->GLEVEL > 9){ msg = PO->DINO+" Dinozord Power"; shortmsg = PO->DINO+" Dinozord"; }
   if(TP->GLEVEL > 19){ msg = PO->DINO+", "+PO->ANIMAL+" Thunderzord Power"; shortmsg = PO->ANIMAL+" Thunderzord"; }
   if(TP->GLEVEL > 29){ msg = PO->ANIMAL+" Ninjazord Power"; shortmsg = PO->ANIMAL+" Ninjazord"; }
   if(TP->GLEVEL > 39){ msg = PO->ANIMAL+" Zeozord"; shortmsg = PO->ANIMAL+" Zeozord"; }   
   if(TP->GLEVEL > 49){ msg = "Turbo-Zord"; shortmsg = "Turbo-Zord"; }
   if(TP->GLEVEL > 59){ msg = "Rescue-Zord"; shortmsg = "Rescue-Zord"; }
   if(TP->GLEVEL > 69){ msg = "Astro-Zord"; shortmsg = "Astro-Zord"; }
   tell_room(environment(TP),TPNAME+" yells: "+msg+"\n");
   pet = clone_object("/players/beck/Rangers/RangerZord.c");
   pet->set_level(PO->KARATE);
   pet->set_hp(1+3*(TP->GLEVEL));
   pet->set_short("A "+shortmsg);
   pet->set_Owner(TP);
   pet->set_OwnerName(TPRNAME);
   if(TP->RangerNPC()){
      pet->set_OwnerName(TP->query_name());
   }
   pet->set_wc(2*PO->KARATE);
   pet->set_ac(random(8));
   pet->set_alt_name(PO->COLOR+"Zord");
   pet->set_message(shortmsg);
   move_object(pet, environment(this_player()));
   APowerPoints(-(100+30*(PO->KARATE)),type);
   if(!present("ViewingGlobe",environment(this_player()))){
      APowerPoints(-(100+30*(PO->KARATE)),type);
   }
   PO->SZord(1);
   tell_room(environment(TP),"A "+shortmsg+" arrives.\n");
   return 1;
}
