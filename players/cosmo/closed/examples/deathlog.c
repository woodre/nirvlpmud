/*  This whole thing is inefficient, but /log/DEATHS sucks. */
#include "/players/llew/closed/ansi.h"

deathlog() {
  
   int size,Hacksize;
   string YEAR;
   size=file_size("/log/DEATHS");
   if(size > 0) {
      string jnk1;
      string deathlog,worktext;
      if(size > 3000) Hacksize=3000;
      else Hacksize=size;
  /*  This will need to be updated in 2000  */
      sscanf(ctime(time()),"%s199%s",jnk1,YEAR);
      deathlog=read_bytes("/log/DEATHS",size-Hacksize,Hacksize);
      rm("/players/llew/Other/misc/deathlog");
      while(sscanf(deathlog,"%s\n%s",worktext,deathlog)==2) {
         string deathtime,playname,playkill,playgold;
         int playexp;
         string playcolor;
         if(sscanf(worktext,"%s 199"+YEAR+" %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5) {
            if(playexp < 12812)   playcolor=NORM;
            else if(playexp < 134998)  playcolor=GRN;
            else if(playexp < 820028)  playcolor=HIY;
            else if(playexp < 2500000) playcolor=RED;
            else playcolor=HIR;
            if(playname != "guest") {
               playname=playcolor+capitalize(playname)+NORM+pad("",3+(11-strlen(playname)),' ');
               sscanf(deathtime,"%s %s",jnk1,deathtime);
               write_file("/players/llew/Other/misc/deathlog","     "+playname+deathtime+"     "+capitalize(playkill)+".\n");
            }
         }
      }
   }   
   return 1;
}
