static int EXPCOST, CCOST, SCOST, MACOST;
static int SKILLRANK;
static status InTraining;
static string SKILLNAME, SKILLTYPE, TEACHER;
static string Skillname;
TrainRanger(teacher,skillname){
  int i;
 if(InTraining){
      return 0;
   }
Skillname = skillname;
   TEACHER = teacher;
         InTraining = 1;
   if(skillname == "random"){
      for (i=0;i<sizeof(UnlearnedSkills);i++){
         SKILLNAME = UnlearnedSkills[i];
         if(SKILLNAME != "dino" && SKILLNAME != "thunder" &&
          SKILLNAME != "ninja" && SKILLNAME != "zeo" &&
          SKILLNAME != "turbo" && SKILLNAME != "rescue"){
            CheckCost();
            if(CheckProperTeacher()){
               if(TrainRanger1()){ 
                  return 1;
               }
            }
         }
      }
   }
   SKILLNAME = skillname; 
if(SKILLNAME == "random"){ return 0; }
   CheckCost();
   if(CheckProperTeacher()){
      TrainRanger1();
   }
   return 1;
}

CheckCost(){
   if(SKILLNAME == "none"){ return; }
if(SKILLNAME == "random"){ return 0; }
   
   if(SKILLNAME == "white"){ EXPCOST = 3000; SKILLRANK = 0; 
      SKILLTYPE = "karate_level"; MACOST = 0; CCOST = 100; SCOST = 25; }
   
   if(SKILLNAME == "yellow"){ EXPCOST = 6000; SKILLRANK = 1; 
      SKILLTYPE = "karate_level"; MACOST = 100; CCOST = 1500; SCOST = 300; }
   
   if(SKILLNAME == "orange"){ EXPCOST = 12000; SKILLRANK = 2; 
      SKILLTYPE = "karate_level"; MACOST = 200; CCOST = 3500; SCOST = 600; }
   
   if(SKILLNAME == "red"){ EXPCOST = 24000; SKILLRANK = 3; 
      SKILLTYPE = "karate_level"; MACOST = 300; CCOST = 5500; SCOST = 900; }
   
   if(SKILLNAME == "green"){ EXPCOST = 48000; SKILLRANK = 4; 
      SKILLTYPE = "karate_level"; MACOST = 400; CCOST = 7500; SCOST = 1200; }
   
   if(SKILLNAME == "blue"){ EXPCOST = 95000; SKILLRANK = 5; 
      SKILLTYPE = "karate_level"; MACOST = 500; CCOST = 9500; SCOST = 1500; }
   
   if(SKILLNAME == "purple"){ EXPCOST = 192000; SKILLRANK = 6; 
      SKILLTYPE = "karate_level"; MACOST = 600; CCOST = 11500; SCOST = 1800; }
   
   if(SKILLNAME == "brown"){ EXPCOST = 384000; SKILLRANK = 7; 
      SKILLTYPE = "karate_level"; MACOST = 700; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "black"){ EXPCOST = 768000; SKILLRANK = 8; 
      SKILLTYPE = "karate_level"; MACOST = 800; CCOST = 15500; SCOST = 2400; }

   if(SKILLNAME == "1st degree"){ EXPCOST = 100000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST =1000; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "2nd degree"){ EXPCOST = 100000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 2000; CCOST = 13500; SCOST = 2100; }
  
   if(SKILLNAME == "3rd degree"){ EXPCOST = 200000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 3000; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "4th degree"){ EXPCOST = 200000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 4000; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "5th degree"){ EXPCOST = 300000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 5000; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "6th degree"){ EXPCOST = 300000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 6000; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "7th degree"){ EXPCOST = 400000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 7000; CCOST = 13500; SCOST = 2100; }
   
   if(SKILLNAME == "8th degree"){ EXPCOST = 400000; SKILLRANK = 9; 
      SKILLTYPE = "karate_extra_level"; MACOST = 8000; CCOST = 15500; SCOST = 2400; }
   
   if(SKILLNAME == "rwho"){ EXPCOST = 0; SKILLRANK = 0; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 0; SCOST = 0; }
   
   if(SKILLNAME == "study"){ EXPCOST = 500; SKILLRANK = 0; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 200; SCOST = 100; }
   
   if(SKILLNAME == "practice"){ EXPCOST = 700; SKILLRANK = 0; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 500; SCOST = 200; }
   
   if(SKILLNAME == "generate"){ EXPCOST = 0; SKILLRANK = 0; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 1; SCOST = 0; }
   
   if(SKILLNAME == "zord"){ EXPCOST = 5000; SKILLRANK = 10; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 1000; SCOST = 100; }
   
   if(SKILLNAME == "megazord"){ EXPCOST = 10000; SKILLRANK = 10; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "aid"){ EXPCOST = 500; SKILLRANK = 10;
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 1000; SCOST = 300; }
   
   if(SKILLNAME == "teleport"){ EXPCOST = 1500; SKILLRANK = 10; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "donate"){ EXPCOST = 500; SKILLRANK = 10; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 100; SCOST = 400; }
   
   if(SKILLNAME == "lead"){ EXPCOST = 2000; SKILLRANK = 10; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 300; SCOST = 200; }
   
   if(SKILLNAME == "weapon"){ EXPCOST = 50000; SKILLRANK = 20; 
      SKILLTYPE = "skill"; MACOST = 200; CCOST = 300; SCOST = 200; }
   
   if(SKILLNAME == "lamp"){ EXPCOST = 15000; SKILLRANK = 20; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 0; SCOST = 600; }
   
   if(SKILLNAME == "blaster"){ EXPCOST = 75000; SKILLRANK = 20; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 1000; SCOST = 500; }
   
   if(SKILLNAME == "armor"){ EXPCOST = 50000; SKILLRANK = 30; 
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 300; SCOST = 0; }
   
   if(SKILLNAME == "teach"){ EXPCOST = 10000; SKILLRANK = 40;
      SKILLTYPE = "skill"; MACOST = 0; CCOST = 0; SCOST = 20000; }
   
   if(SKILLNAME == "dino"){ EXPCOST = 1000; SKILLRANK = 1; 
      SKILLTYPE = "ranger_type"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "thunder"){ EXPCOST = 10000; SKILLRANK = 13; 
      SKILLTYPE = "ranger_type"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "ninja"){ EXPCOST = 200000; SKILLRANK = 25; 
      SKILLTYPE = "ranger_type"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "zeo"){ EXPCOST = 1000000; SKILLRANK = 36; 
      SKILLTYPE = "ranger_type"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "turbo"){ EXPCOST = 2000000; SKILLRANK = 49; 
      SKILLTYPE = "ranger_type"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "rescue"){ EXPCOST = 4000000; SKILLRANK = 59; 
      SKILLTYPE = "ranger_type"; MACOST = 0; CCOST = 25; SCOST = 25; }
   
   if(SKILLNAME == "shiho-nage"){ EXPCOST = 500; SKILLRANK = 0; 
      SKILLTYPE = "defense"; MACOST = 0; CCOST = 5; SCOST = 0; }
   
   if(SKILLNAME == "irimi-nage"){ EXPCOST = 500; SKILLRANK = 0; 
      SKILLTYPE = "defense"; MACOST = 30; CCOST = 60; SCOST = 0; }
   
   if(SKILLNAME == "kaiten-nage"){ EXPCOST = 600; SKILLRANK = 1; 
      SKILLTYPE = "defense"; MACOST = 100; CCOST = 200; SCOST = 0; }
   
   if(SKILLNAME == "kote-gaeshi"){ EXPCOST = 600; SKILLRANK = 1; 
      SKILLTYPE = "defense"; MACOST = 300; CCOST = 600; SCOST = 0; }
   
   if(SKILLNAME == "ikkyo"){ EXPCOST = 700; SKILLRANK = 2; 
      SKILLTYPE = "defense"; MACOST = 700; CCOST = 1400; SCOST = 0; }
   
   if(SKILLNAME == "nikyo"){ EXPCOST = 700; SKILLRANK = 2; 
      SKILLTYPE = "defense"; MACOST = 1200; CCOST = 2400; SCOST = 0; }
   
   if(SKILLNAME == "sankyo"){ EXPCOST = 800; SKILLRANK = 3; 
      SKILLTYPE = "defense"; MACOST = 2000; CCOST = 4000; SCOST = 0; }
   
   if(SKILLNAME == "yonkyo"){ EXPCOST = 900; SKILLRANK = 4; 
      SKILLTYPE = "defense"; MACOST = 3000; CCOST = 6000; SCOST = 0; }
   
   if(SKILLNAME == "koshi-nage"){ EXPCOST = 1000; SKILLRANK = 5; 
      SKILLTYPE = "defense"; MACOST = 4500; CCOST = 9000; SCOST = 0; }
   
   if(SKILLNAME == "tenchi-nage"){ EXPCOST = 1000; SKILLRANK = 5; 
      SKILLTYPE = "defense"; MACOST = 6500; CCOST = 13000; SCOST = 0; }
   
   if(SKILLNAME == "juji-garami"){ EXPCOST = 1200; SKILLRANK = 6; 
      SKILLTYPE = "defense"; MACOST = 9000; CCOST = 18000; SCOST = 0; }
   
   if(SKILLNAME == "aiki-otoshi"){ EXPCOST = 1200; SKILLRANK = 6; 
      SKILLTYPE = "defense"; MACOST = 14000; CCOST = 28000; SCOST = 0; }
   
   if(SKILLNAME == "sumi-otoshi"){ EXPCOST = 1400; SKILLRANK = 7; 
      SKILLTYPE = "defense"; MACOST = 18000; CCOST = 36000; SCOST = 0; }
   
   if(SKILLNAME == "kokyu-nage"){ EXPCOST = 1600; SKILLRANK = 8; 
      SKILLTYPE = "defense"; MACOST = 23000; CCOST = 46000; SCOST = 0; }
   
   if(SKILLNAME == "aiki-nage"){ EXPCOST = 2000; SKILLRANK = 9; 
      SKILLTYPE = "defense"; MACOST = 30000; CCOST = 60000; SCOST = 0; }
   
   if(SKILLNAME == "butterfly"){ EXPCOST = 900; SKILLRANK = 7; 
      SKILLTYPE = "offense"; MACOST = 5000; CCOST = 10000; SCOST = 0; }
   
   if(SKILLNAME == "throw"){ EXPCOST = 200; SKILLRANK = 2; 
      SKILLTYPE = "offense"; MACOST = 600; CCOST = 1200; SCOST = 0; }
   
   if(SKILLNAME == "laugh"){ EXPCOST = 300; SKILLRANK = 3; 
      SKILLTYPE = "offense"; MACOST = 1000; CCOST = 2000; SCOST = 0; }
   
   if(SKILLNAME == "death"){ EXPCOST = 2000; SKILLRANK = 8; 
      SKILLTYPE = "offense"; MACOST = 20000; CCOST = 40000; SCOST = 0; }
   
   if(SKILLNAME == "elbow"){ EXPCOST = 400; SKILLRANK = 4; 
      SKILLTYPE = "offense"; MACOST = 3000; CCOST = 9000; SCOST = 0; }
   
   if(SKILLNAME == "press"){ EXPCOST = 500; SKILLRANK = 5; 
      SKILLTYPE = "offense"; MACOST = 8000; CCOST = 16000; SCOST = 0; }
   
   if(SKILLNAME == "axe"){ EXPCOST = 700; SKILLRANK = 6; 
      SKILLTYPE = "offense"; MACOST = 12000; CCOST = 24000; SCOST = 0; }
   
   if(SKILLNAME == "punch"){ EXPCOST = 100; SKILLRANK = 1; 
      SKILLTYPE = "offense"; MACOST = 300; CCOST = 600; SCOST = 0; }
}   
  

CheckProperTeacher(){ 
   if(!CheckUnlearnedSkills(SKILLNAME)){
      InTraining = 0;
      return 0;
   }
   if(SKILLTYPE == "karate_level"){
      if(SKILLRANK != KarateLevel){ InTraining = 0; return 0; }
      if(TEACHER != "Tommy"){ InTraining = 0; return 0; }
   }
   if(SKILLTYPE == "defense" && TEACHER != "Morihei"){ InTraining = 0; return 0; }
   if(SKILLTYPE == "offense" && TEACHER != "Protege"){ InTraining = 0; return 0; }
   if(SKILLTYPE == "skill" && Skillname == "random" && TEACHER == "Protege"){
      InTraining = 0; return 0;
   }
   if(SKILLTYPE == "skill" && Skillname == "random" && TEACHER == "Morihei"){
      InTraining = 0; return 0;
   }
return 1;
}   

TrainRanger1(){
   int level, level_exp;
   if(ENVOB->query_guild_name() != GUILDNAME){ InTraining = 0; return 0; }
   if(ENVOB->GLEVEL < SKILLRANK){InTraining = 0; return 0; }
   if(RangerCombatExp < CCOST){ InTraining = 0; return 0; }
   if(RangerMartialArtsExp < MACOST){ InTraining = 0; return 0; }
   if(RangerSkillExp < SCOST){ InTraining = 0; return 0; }
   level = ENVOB->query_level();
   if(level == 1){ level_exp = 0; }
   if(level == 2){ level_exp = 1014; }
   if(level == 3){ level_exp = 1771; }
   if(level == 4){ level_exp = 2332; }
   if(level == 5){ level_exp = 5885; }
   if(level == 6){ level_exp = 12812; }
   if(level == 7){ level_exp = 26662; }
   if(level == 8){ level_exp = 39993; }
   if(level == 9){ level_exp = 59995; }
   if(level == 10){ level_exp = 90000; }
   if(level == 11){ level_exp = 134998; }
   if(level == 12){ level_exp = 195591; }
   if(level == 13){ level_exp = 295592; }
   if(level == 14){ level_exp = 492294; }
   if(level == 15){ level_exp = 620026; }
   if(level == 16){ level_exp = 820028; }
   if(level == 17){ level_exp = 1040028; }
   if(level == 18){ level_exp = 1367106; }
   if(level == 19){ level_exp = 2000000; }
   if((ENVOB->EXP - level_exp) < EXPCOST){ InTraining = 0; return 0; }
   call_out("TrainMessage1",0);
   command("rangertrainfinal",ENVOB);
   return 1;
}
TrainMessage1(){
   tell_object(ENVOB, TEACHER+" tells you:\n"+MASTER->TrainingMessage(SKILLNAME)+"\n");
   return 1;
}
TrainRanger1_5()
{
   input_to("TrainRanger2");
   return 1;
}

TrainRanger2(str){
   if(str == "yes"){
      RUnlearnedSkills(SKILLNAME);
      if(SKILLTYPE == "skill"){
         ASkills(SKILLNAME);
         if(SKILLNAME == "rwho"){
            ASkills("rt");
            ASkills("rte");
         }
         if(SKILLNAME == "practice"){
            ASkills("offense");
            ASkills("defense");
         }
      }
      if(SKILLTYPE == "offense"){
         AOffense(SKILLNAME);
      }
      if(SKILLTYPE == "defense"){
         ADefense(SKILLNAME);
      }
      if(SKILLTYPE == "karate_level"){
         KarateLevel += 1;
         ENVOB->add_guild_rank(1);
         if(SKILLNAME == "white"){
            AUnlearnedSkills("yellow");
            AUnlearnedSkills("kaiten-nage");
            AUnlearnedSkills("kote-gaeshi");
            AUnlearnedSkills("punch");
         }
         if(SKILLNAME == "yellow"){
            AUnlearnedSkills("orange");
            AUnlearnedSkills("throw");
            AUnlearnedSkills("ikkyo");
            AUnlearnedSkills("nikyo");
         }
         if(SKILLNAME == "orange"){
            AUnlearnedSkills("red");
            AUnlearnedSkills("laugh");
            AUnlearnedSkills("sankyo");
         }
         if(SKILLNAME == "red"){
            AUnlearnedSkills("green");
            AUnlearnedSkills("elbow");
            AUnlearnedSkills("yonkyo");
         }
         if(SKILLNAME == "green"){
            AUnlearnedSkills("blue");
            AUnlearnedSkills("koshi-nage");
            AUnlearnedSkills("tenchi-nage");
            AUnlearnedSkills("press");
         }
         if(SKILLNAME == "blue"){
            AUnlearnedSkills("purple");
            AUnlearnedSkills("axe");
            AUnlearnedSkills("juji-garami");
            AUnlearnedSkills("aiki-otoshi");
         }
         if(SKILLNAME == "purple"){
            AUnlearnedSkills("brown");
            AUnlearnedSkills("butterfly");
            AUnlearnedSkills("sumi-otoshi");
         }
         if(SKILLNAME == "brown"){
            AUnlearnedSkills("black");
            AUnlearnedSkills("kokyu-nage");
            AUnlearnedSkills("death");
         }
         if(SKILLNAME == "black"){
            AUnlearnedSkills("aiki-nage");
            
         }
      }
      if(SKILLTYPE == "karate_extra_level"){
         
         
         if(SKILLNAME == "1st degree"){
            AUnlearnedSkills("2nd degree");
         }
         if(SKILLNAME == "2nd degree"){
            AUnlearnedSkills("3rd degree");
         }
         if(SKILLNAME == "3rd degree"){
            AUnlearnedSkills("4th degree");
         }
         if(SKILLNAME == "4th degree"){
            AUnlearnedSkills("5th degree");
         }
         if(SKILLNAME == "5th degree"){
            AUnlearnedSkills("6th degree");
         }
         if(SKILLNAME == "6th degree"){
            AUnlearnedSkills("7th degree");
         }
         if(SKILLNAME == "7th degree"){
            AUnlearnedSkills("8th degree");
         }
      }
      if(SKILLTYPE == "ranger_type"){
         MASTER->RangerMessage("all","Zordon says: "+ENVOB->query_name()+" has become a "+
         capitalize(SKILLNAME)+" Ranger");
         ARangerTypes(SKILLNAME);
         ENVOB->add_guild_rank(10);
         if(SKILLNAME == "ninja"){
            ASkills("ninja");
            AUnlearnedSkills("armor");
            AUnlearnedSkills("zeo");
         }
         if(SKILLNAME == "zeo"){
            AUnlearnedSkills("turbo");
            AUnlearnedSkills("teach");
            GLOBE->Number1();
         }
         if(SKILLNAME == "dino"){
            AUnlearnedSkills("thunder");
            ASkills("morph");
            ASkills("unmorph");
            AUnlearnedSkills("zord");
            AUnlearnedSkills("megazord");
            AUnlearnedSkills("lead");
            AUnlearnedSkills("teleport");
            AUnlearnedSkills("donate");
            AUnlearnedSkills("aid");
            GLOBE->Color1();
         }
         if(SKILLNAME == "thunder"){
            AUnlearnedSkills("ninja");
            ASkills("jet");
            AUnlearnedSkills("lamp");
            AUnlearnedSkills("weapon");
            AUnlearnedSkills("blaster");
            GLOBE->Animal1();
         }
         if(SKILLNAME == "turbo"){
            AUnlearnedSkills("rescue");
         }
      }
      if(EXPCOST > 0){
         ENVOB->add_exp(-EXPCOST);
      }
      ENVOB->add_guild_exp(EXPCOST);
      InTraining = 0;
      SaveRanger();
      init();
      write_file("/players/beck/Rangers/Log/TRAINING",ENVOB->query_name()+
      " has trained "+SKILLNAME+" for "+EXPCOST+" exp. "+ctime(time())+"\n");
      return 1;
   }
   tell_object(ENVOB, "Well you can learn some other time then.\n");
   InTraining = 0;
   return 1;
}

RandomUnlearnedSkills(){
   int i;
   i = sizeof(UnlearnedSkills);
   i = random(i);
   return UnlearnedSkills[i];
}
ACombatExp(arg){ RangerCombatExp += arg; }
QCombatExp(){ return RangerCombatExp; }

AMartialExp(arg){ RangerMartialArtsExp += arg; }
QMartialExp(){ return RangerMartialArtsExp; }
AMartialExpTemp(arg){ RangerMartialArtsExpTemp += arg; }
QMartialExpTemp(){ return RangerMartialArtsExpTemp; }

ASkillExp(arg){ RangerSkillExp += arg; }
QSkillExp(){ return RangerSkillExp; }
SSkills(arg){ Skills = ({ arg }); return 1; }
ASkills(arg){
   int i;
   for(i=0; i<sizeof(Skills); i++){
      if(Skills[i] == arg){
         return 0;
       }
   }
   Skills += ({ arg });
   return 1;
}
SDefense(arg){ Defense = ({ arg }); return 1; }
ADefense(arg){
   int i;
   for(i=0;i<sizeof(Defense); i++){
      if(Defense[i] == arg){
         return 0;
       }}
   Defense += ({ arg });
   return 1;
}
SOffense(arg){ Offense = ({ arg }); return 1; }
AOffense(arg){
   int i;
   for(i=0;i<sizeof(Offense); i++){
      if(Offense[i] == arg){
         return 0;
       }}
   Offense += ({ arg });
   return 1;
}
SRangerTypes(arg){ RangerTypes = ({ arg }); return 1; }
ARangerTypes(arg){
   int i;
   for(i=0;i<sizeof(RangerTypes); i++){
      if(RangerTypes[i] == arg){
         return 0;
       }}
   RangerTypes += ({ arg });
   return 1;
}
SUnlearnedSkills(arg){ UnlearnedSkills = ({ arg }); return 1; }
AUnlearnedSkills(arg){
   int i;
   for(i=0;i<sizeof(UnlearnedSkills); i++){
      if(UnlearnedSkills[i] == arg){
         return 0;
       }}
   UnlearnedSkills += ({ arg });
   return 1;
}
RUnlearnedSkills(arg){
   UnlearnedSkills -= ({ arg });
   return 1;
}
