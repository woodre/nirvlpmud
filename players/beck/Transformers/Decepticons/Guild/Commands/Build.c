#include "/players/beck/Defs.h"
#include "/players/beck/Transformers/Decepticons/Defs.h"

DecepticonCommand(str){
   object structure;
   object enhance;
   string enhancename;
   if(!str){
      write("You must pick a structure to build.\n");
      return 1;
   }
   if(ENV(TP)->realm() == "NT"){
      write("You are not allowed to build a structure here.\n");
      return 1;
   } 
   if(str == "base"){
      if(PO->QBase()){
         write("You already have built a base.\n");
         return 1;
      }
      structure = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/Base.c");
      structure->SOwnerName(capitalize(TP->RNAME));
      PO->SBase("/"+file_name(ENV(TP)));
      BASEDAEMON->ACurrBase(capitalize(TP->RNAME), structure);
      move_object(structure, ENV(TP));
      BASEDAEMON->ABase(capitalize(TP->RNAME), "/"+file_name(ENV(TP)));
      cp("/players/beck/Transformers/Decepticons/Guild/Object/Base.c", "/players/beck/Test/Beck_Base.c");
      return 1;
   }
   else if (str == "security system"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Security System";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement("Security System","/players/beck/Transformers/Decepticons/Guild/Object/SecuritySystem.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/SecuritySystem.c");
      
   }
   else if (str == "missile launcher"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Missile Launcher";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement("Missile Launcher","/players/beck/Transformers/Decepticons/Guild/Object/MissileLauncher.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/MissileLauncher.c");
      
   }
   else if (str == "ion pulse cannon"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Ion Pulse Cannon";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement(enhancename,"/players/beck/Transformers/Decepticons/Guild/Object/IonPulseCannon.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/IonPulseCannon.c");
      
   }
   else if (str == "solar collector"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Solar Collector";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
if(structure->QEnhancementNum(enhancename) > 3){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement(enhancename,"/players/beck/Transformers/Decepticons/Guild/Object/SolarCollector.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/SolarCollector.c");
      
   }
   else if (str == "processing plant"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Processing Plant";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement(enhancename,"/players/beck/Transformers/Decepticons/Guild/Object/ProcessingPlant.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/ProcessingPlant.c");
      
   }
   else if (str == "xenon refractor shield"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Xenon Refractor Shield";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement(enhancename,"/players/beck/Transformers/Decepticons/Guild/Object/XenonRefractorShield.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/XenonRefractorShield.c");
      
   }
   else if (str == "spy satellite"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Spy Satellite";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement("Spy Satellite","/players/beck/Transformers/Decepticons/Guild/Object/SpySatellite.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/SpySatellite.c");
      
   }
   else if (str == "communications tower"){
      if(!PO->QBase()){
         return 1;
         }
      enhancename = "Communications Tower";
      structure = BASEDAEMON->QCurrBase(TP->RNAME);
      if(structure->QEnhancementNum(enhancename)){
         write("You have already built a "+enhancename+".\n");
         return 1;
         }
      structure->AEnhancement("Communications Tower","/players/beck/Transformers/Decepticons/Guild/Object/CommunicationsTower.c");
      enhance = clone_object("/players/beck/Transformers/Decepticons/Guild/Object/CommunicationsTower.c");
      
   }
   else{
      write("That is not a structure you can build.\n");
      return 1;
   }
   enhance->SBase(structure);
   enhance->SName(enhancename+" "+structure->QEnhancementNum(enhancename));
   enhance->RestoreEnhancement();
   structure->ACurrEnhancement(enhance);
   move_object(enhance,structure);
   write("You have built a new "+enhancename+".\n");
   return 1;
}  
