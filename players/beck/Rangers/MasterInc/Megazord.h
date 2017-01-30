RangerMegazord(str,string type){
   string *rangers;
   string *msg;
   string ranger1, ranger2, ranger3, ranger4, ranger5; 
   int i,j;
   object comm;
   object MegRanger;
   rangers = ({});
   msg = ({});
   if(!str){
      write("You must specify 4 rangers to use in the megazord\n");
      return 1;
   }
   if(!COMM->QMorphed()){
      write("You must be morphed to call the Thunder Megazord.\n");
      return 1;
   }
   if(sscanf(str, "%s,%s,%s,%s", ranger1, ranger2, ranger3, ranger4) != 4) {
      write("You must choose 4 other people to call the megazord.\n");
      return 1;
   }
   if(find_living("RangerMegazord")){
      write("The Thunder Megazord has already been called by other Rangers.\n");
      return 1;
   } 
   if(QPowerPoints(type) < 1000){
      write("There are not enough power points to call the Thunder Megazord.\n");
      return 1;
   }
   rangers += ({ ranger1 });
   rangers += ({ ranger2 });
   rangers += ({ ranger3 });
   rangers += ({ ranger4 });
   for(i = 0; i<sizeof(rangers); i++){
      if(!present(rangers[i], environment(TP))){
         write(rangers[i]+" is not here.\n");
         return 1;
       }
      MegRanger = present(rangers[i], environment(TP));
      if(!present("RangerCommunicator",MegRanger)){
         write(rangers[i]+" is not a Power Ranger.\n");
         return 1;
       }
      comm = present("RangerCommunicator",MegRanger);
      if(!comm->QMorphed()){
         write(rangers[i]+" is not morphed.\n");
         return 1;
       }
      if(MegRanger->GLEVEL > 9 && MegRanger->GLEVEL < 20){ msg += ({ comm->DINO+" Dinozord Power" }); }
      if(MegRanger->GLEVEL > 19 && MegRanger->GLEVEL < 30){ msg += ({ comm->DINO+", "+comm->ANIMAL+" Thunderzord Power" }); }
      if(MegRanger->GLEVEL > 29 && MegRanger->GLEVEL < 40){ msg += ({ comm->ANIMAL+" Ninjazord Power" }); }
      if(MegRanger->GLEVEL > 39 && MegRanger->GLEVEL < 50){ msg += ({ comm->ANIMAL+" Zeozord" }); }   
      if(MegRanger->GLEVEL > 49 && MegRanger->GLEVEL < 60){ msg += ({ "Turbozord" }); }
      if(MegRanger->GLEVEL > 59 && MegRanger->GLEVEL < 70){ msg += ({ "Rescue-zord" }); }
      if(MegRanger->GLEVEL > 69 && MegRanger->GLEVEL < 80){ msg += ({ "Astro-zord" }); }

   }
   move_object("/players/beck/Rangers/ThunderMegazord.c", environment(this_player()));
   if(TP->GLEVEL > 9 && TP->GLEVEL < 20){ msg += ({ COMM->DINO+" Dinozord Power" }); }
   if(TP->GLEVEL > 19 && TP->GLEVEL < 30){ msg += ({ COMM->DINO+", "+COMM->ANIMAL+" Thunderzord Power" }); }
   if(TP->GLEVEL > 29 && TP->GLEVEL < 40){ msg += ({ COMM->ANIMAL+" Ninjazord Power" });  }
   if(TP->GLEVEL > 39 && TP->GLEVEL < 50){ msg += ({ COMM->ANIMAL+" Zeozord" }); }   
   if(TP->GLEVEL > 49 && TP->GLEVEL < 60){ msg += ({ "Turbozord" }); }
   if(TP->GLEVEL > 59 && TP->GLEVEL < 70){ msg += ({ "Rescue-zord" });  }
   if(TP->GLEVEL > 69 && TP->GLEVEL < 80){ msg += ({ "Astro-zord" });  }
   rangers += ({ NAME });
   for(j=0; j<sizeof(rangers); j++){
      tell_room(environment(TP),capitalize(rangers[j])+" yells: "+msg[j]+"\n");
      if(rangers[j] != NAME){
         call_other(present(rangers[j], environment(TP)),"move_player","megazord#/players/beck/Rangers/ThunderMegazord.c");
       }
   }
   call_other(TP,"move_player","megazord#/players/beck/Rangers/ThunderMegazord.c");
   tell_room(environment(environment(this_player())),"The Power Rangers yell: Thunder Megazord...Power Up!\n");
   APowerPoints(-1000,type);
   return 1;
}
