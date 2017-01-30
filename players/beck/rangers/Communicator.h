SKarateLevel(arg){ KarateLevel = arg; return 1; }
QKarateLevel(){ return KarateLevel; }
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
ARangerStrength(arg){ RangerStrength += arg; }
QRangerStrength(){ return RangerStrength; }
ARangerSpeed(arg){ RangerSpeed += arg; }
QRangerSpeed(){ return RangerSpeed; }
ARangerEndurance(arg){ RangerEndurance += arg; }
QRangerEndurance(){ return RangerEndurance; }
ARangerStrengthTemp(arg){ RangerStrengthTemp += arg; }
QRangerStrengthTemp(){ return RangerStrengthTemp; }
ARangerSpeedTemp(arg){ RangerSpeedTemp += arg; }
QRangerSpeedTemp(){ return RangerSpeedTemp; }
ARangerEnduranceTemp(arg){ RangerEnduranceTemp += arg; }
QRangerEnduranceTemp(){ return RangerEnduranceTemp; }
SMorphed(){
   if(!Morphed)
      Morphed = 1;
   else {
      Morphed = 0;
   }
}
QMorphed(){ return Morphed;}
SNinja(){
   if(!Ninja)
      Ninja = 1;
   else {
      Ninja = 0;
   }
}
QNinja(){ return Ninja;}
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
SZord(arg){ Zord = arg; return 1; }
QZord(){ return Zord; }
SeeSkills(){
   int k;
   write("Skills you can use:\n");
   for(k=0; k<sizeof(Skills); k++){
      write(justify(Skills[k],20));
      write("\n");
   }
   return 1;
}
SeeOffense(){
   int k;
   write("Offensive Skills:\n");
   for(k=0; k<sizeof(Offense); k++){
      write(justify(Offense[k],20));
      write("\n");
   }
   return 1;
}
SeeDefense(){
   int k;
   write("Defensive Skills:\n");
   for(k=0; k<sizeof(Defense); k++){
      write(justify(Defense[k],20));
      write("\n");
   }
   return 1;
}
CheckOffense(str){
   if(member_array(str,Offense) != -1){
      return 1;
   }
   return 0;
}
CheckDefense(str){
   if(member_array(str, Defense) !=-1){
      return 1;
   }
   return 0;
}
CheckSkills(str){
   if(member_array(str, Skills) != -1){
      return 1;
   }
   return 0;
}
CheckUnlearnedSkills(str){
   if(member_array(str, UnlearnedSkills) != -1){
      return 1;
   }
   return 0;
}
