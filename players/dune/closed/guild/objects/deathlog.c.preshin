/*  Llew of Nirvana coded this  */
/*  This whole thing is inefficient, but /log/DEATHS sucks. */
#include "../DEFS.h"
#define DEATHLOG OBJDIR+"/deaths.txt"

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
      sscanf(ctime(time()),"%s200%s",jnk1,YEAR);
      deathlog=read_bytes("/log/DEATHS",size-Hacksize,Hacksize);
      rm(DEATHLOG);
      while(sscanf(deathlog,"%s\n%s",worktext,deathlog)==2) {
         string deathtime,playname,playkill,playgold;
         int playexp;
         string playcolor;
         if(sscanf(worktext,"%s 200"+YEAR+" %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5) {
            if(playexp < 12812)   playcolor=OFF;
        else if(playexp < 134998) playcolor=GREEN;
        else if(playexp < 820028) playcolor = BOLD+YELLOW;
        else if(playexp < 2500000) playcolor = RED;
        else playcolor = BOLD+RED;
            if(playname != "guest") {
               playname=playcolor+capitalize(playname)+OFF+pad("",3+(11-strlen(playname)),' ');
               sscanf(deathtime,"%s %s",jnk1,deathtime);
               write_file(DEATHLOG, "     "+playname+deathtime+"     "+capitalize(playkill)+".\n");
            }
         }
      }
   }   
   return 1;
}
