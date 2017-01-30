/* Updated by Rumplemintz to work with LD.  At the same time I recoded it so
 * that we don't have to keep updating the year... silly.
 *
 */

#if 0  /* Original code */
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
      "vitestal",
      "vital",
      "verte",
      "vitesticle",
      "wicket",
      "shinshi",
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
/* Updated to work through 2099 - illarion Jan 05
      sscanf(ctime(time()),"%s200%s",jnk1,YEAR);
*/
/* will have to be updated year by year */
      deathlog=read_bytes("/log/DEATHS",size-Hacksize,Hacksize);
      rm(LOGFILE);
      while(sscanf(deathlog,"%s\n%s",worktext,deathlog)==2) {
         string deathtime,playname,playkill,playgold;
         int playexp;
         string playcolor;
         spar = 0;
          if(sscanf(worktext,"%s 2010 %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5
          ||sscanf(worktext,"%s 2011 %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5
          ||sscanf(worktext,"%s 2012 %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5
          ||sscanf(worktext,"%s 2013 %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5    
          ) {
            if(playexp < 12812)   playcolor=NORM;
            else if(playexp < 134998)  playcolor=GRN;
            else if(playexp < 820028)  playcolor=HIY;
            else if(playexp < 11111111) playcolor=RED;
            else if(playexp < 65000000) playcolor=HIR;
            else playcolor=HIM;
/* Player levels below 5 are not shown on obituary notice, nor is guest -Snow 10/99 */
            if (!("/obj/user/testchar-d"->query_owner(playname)) &&
                member_array(playname, exclusion) == -1 && playexp > 5000) {
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
#else /* New code below - Rumplemintz */

#include <ansi.h>    /* No need for a special ansi file... */

/* Instead of writing yet another logfile, let's just parse the existing one
   and get the information we're wanting, then build a string
 */

static int logsize;
string *exclusion;    /* Exclusion list for characters we don't want
                         to show up on the list */

void reset(int arg) {
  if (arg)
    return;
  logsize = 0;

  exclusion = ({ /* Players above no longer play... empty the list */
    "guest",
  });
}

varargs string deathlog(string str) { /* Optional year as argument */
  int size, Hacksize, spar;
  string Result;  /* What we'll send back */

  string Day, Month, Date, Hour, Minute, Seconds, Year;
  sscanf(ctime(),"%s %s %d %d:%d:%d %s",
                 Day, Month, Date, Hour, Minute, Seconds, Year);

  size = file_size("/log/DEATHS");
  if (size > 0) {
    string jnk1, deathlog, stuff;
    string worktext;
    if (size > 3000)
      Hacksize = 3000;
    else
      Hacksize = size;

    if (!str)
      str = Year;

    deathlog = read_bytes("/log/DEATHS", size-Hacksize, Hacksize);
    Result = "";
    while(sscanf(deathlog, "%s\n%s", worktext, deathlog) == 2) {
      string deathtime, playname, playkill, playgold;
      int playexp;
      string playcolor;
      string deathyear;
      spar = 0;
      if (sscanf(worktext,"%s " + str + " %s %d exp %s gold killed by %s.",
                 deathtime, playname, playexp, playgold, playkill)
          == 5) {
        switch(playexp) {
        case 0..12811: playcolor=NORM; break;
        case 12812..134997: playcolor=GRN; break;
        case 134998..820027: playcolor=HIY; break;
        case 820028..11111110: playcolor=RED; break;
        case 11111111..65000000: playcolor=HIR; break;
        default: playcolor=HIM;
        }
        if (!("/obj/user/testchar-d"->query_owner(playname)) &&
            member(exclusion, playname) == -1 &&
            playexp > 5000) {
          playname = playcolor + capitalize(playname) + NORM +
                     pad("",3+(11-strlen(playname)),' ');
          sscanf(deathtime,"%s %s", jnk1, deathtime);
          if (jnk1 == "Spar->") {
            spar = 1;
            sscanf(deathtime, "%s %s", jnk1, deathtime);
          }
          if (spar)
            Result += BOLD + " * " + NORM;
          else
            Result += "     ";
          Result += playname + deathtime + "     " + capitalize(playkill) +
                    ".\n";
        }
      }
    }
  }
  return Result;
}
#endif

