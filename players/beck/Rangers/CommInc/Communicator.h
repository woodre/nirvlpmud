SOldTitle(str){ OldTitle = str; }
QOldTitle(){ return OldTitle; }
SOldPretitle(str){ OldPretitle = str; }
QOldPretitle(){ return OldPretitle; }
SRangerColor(str){ RangerColor = str; }
QRangerColor(){ return RangerColor; }
SRangerDino(str){ RangerDino = str; }
QRangerDino(){ return RangerDino; }
SRangerAnimal(str){ RangerAnimal = str; }
QRangerAnimal(){ return RangerAnimal; }
SRangerWeapon(str){ RangerWeapon = str; }
QRangerWeapon(){ return RangerWeapon; }
SRangerNumber(str){ RangerNumber = str; }
QRangerNumber(){ return RangerNumber; }
SRangerAnsi(str){ RangerAnsi = str; }
QRangerAnsi(){ return RangerAnsi; }
QRandomNumber(){ return RandomNumber; }
QRangerTactic(){ return RangerTactic; }


SMorphed(){
   if(!Morphed)
      Morphed = 1;
   else {
      Morphed = 0;
   }
}
QMorphed(){ return Morphed;}


Muffles(){
   if(Muffles == 1){
      Muffles = 0;
      write("Your guild channel muffle is OFF.\n");
      return 1;
   }
   Muffles = 1;
   write("Your guild channel muffle is ON.\n");
   return 1;
}
QMuffles(){ return Muffles; }


QRangerAlign(){ return RangerAlign; }

NotArmor(arg){
   if(arg == 0){ NotArmor = "allowed"; }
   else if(arg == 1){ NotArmor = "notarmor"; }
   else NotArmor = "notarmor";
}

/*
PlayerShortObject(arg){
   if(arg == 0){ PlayerShortObject = "player_short_object"; }
   else if(arg == 1){ PlayerShortObject = "not_player_short"; }
   else PlayerShortObject = "not_player_short";
}
*/
SPlayerShort(arg){
   PlayerShort = arg;
}


SRangerTactic(arg){
   RangerTactic = arg;
}

QRangerType(){
   string type;
   if(QuerySkillLevel("morph") > 99){ type = "Wild Force"; }
   else if(QuerySkillLevel("morph") > 89){ type = "Time Force"; }
   else if(QuerySkillLevel("morph") > 79){ type = "Galaxy"; }
   else if(QuerySkillLevel("morph") > 69){ type = "Space"; }
   else if(QuerySkillLevel("morph") > 59){ type = "Rescue"; }
   else if(QuerySkillLevel("morph") > 49){ type = "Turbo"; }
   else if(QuerySkillLevel("morph") > 39){ type = "Zeo"; }
   else if(QuerySkillLevel("morph") > 29){ type = "Ninja"; }
   else if(QuerySkillLevel("morph") > 19){ type = "Thunder"; }
   else if(QuerySkillLevel("morph") > 9){ type = "Dino"; }
   else{ type = "Initiate"; }

   return type;
}

AID(string str){
   if(!ID)
      ID = ({});
   if(member_array(str, ID) == -1)
      ID += ({ str });
   
}

RID(string str){
   if(!ID)
      ID = ({});
   if(member_array(str, ID) != -1)
      ID -= ({ str });
}

kill_check(object ob){

   int team;

   team = TO->QuerySkillLevel("team");

   "/players/beck/Rangers/Commands/KillCheck.c"->kill_check(ob, TO, team);

   return;

}
   