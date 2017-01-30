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
