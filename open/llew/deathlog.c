#include "/players/llew/closed/ansi.h"
#define LOGFILE "/players/llew/Other/misc/deathlog"

static int logsize;
string *exclusion;

reset(arg)
{
   if (arg) return;
   logsize = 0;

   /*  Add names here to exclude from showing on the deathlog.  Test characters for example. */
   exclusion = ({
      "guest",
      "llewboto",
      "labrat",
      "painjr",
   });
}

deathlog() {
  
   int size, Hacksize;
   int spar;
   string YEAR;
   size=file_size("/log/DEATHS");
   if (size == logsize)  return 1;
   if(size > 0) {
      string jnk1;
      string deathlog,worktext;
      if(size > 3000) Hacksize=3000;
      else Hacksize=size;
  /*  This will need to be updated in 2000  */
/* Updated to 2000 -Snow 1/00 */
      sscanf(ctime(time()),"%s200%s",jnk1,YEAR);
      deathlog=read_bytes("/log/DEATHS",size-Hacksize,Hacksize);
      rm(LOGFILE);
      while(sscanf(deathlog,"%s\n%s",worktext,deathlog)==2) {
         string deathtime,playname,playkill,playgold;
         int playexp;
         string playcolor;
         spar = 0;
         if(sscanf(worktext,"%s 200"+YEAR+" %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5) {
            if(playexp < 12812)   playcolor=NORM;
            else if(playexp < 134998)  playcolor=GRN;
            else if(playexp < 820028)  playcolor=HIY;
            else if(playexp < 2500000) playcolor=RED;
            else if(playexp < 65000000) playcolor=HIR;
            else playcolor=HIM;
/* Player levels below 5 are not shown on obituary notice, nor is guest -Snow 10/99 */
            if (member_array(playname, exclusion) == -1 && playexp > 5000) {
               playname=playcolor+capitalize(playname)+NORM+pad("",3+(11-strlen(playname)),' ');
               sscanf(deathtime,"%s %s",jnk1,deathtime);
               if (jnk1 == "Spar->")
               {
                  spar = 1;
                  sscanf(deathtime, "%s %s", jnk1, deathtime);
               }
               if (spar) write_file(LOGFILE, BOLD + "  *  " + NORM);
               else write_file(LOGFILE, "     ");
               write_file(LOGFILE,playname+deathtime+"     "+capitalize(playkill)+".\n");
            }
         }
      }
   }   
   logsize = size;
   return 1;
}
