string numberAddCommas(int numberInt) {
   string tmp,number;
   int x,loopCount;
   
   loopCount = 0;
   tmp = "";
   number = "" + numberInt + "";
   
   for(x = strlen(number)-1; x >= 0; x--) {
      loopCount++;
      tmp += extract(number,x,x);
      if(loopCount % 3 == 0 && x > 0)
         tmp += ",";
   }
   
   number = "";
   
   for(x = strlen(tmp)-1; x >= 0; x--)
      number += extract(tmp,x,x);
   
   return number;
}
