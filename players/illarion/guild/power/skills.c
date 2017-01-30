/* skills.c
 *
 * Lists the current level of skills and wether they're practiced enough
 * to be advanced.
 */

#include "/players/illarion/guild/def.h"

/* Documentation.  Framed by the help command */
string help() {
  return "Usage: skills\n"+
         "Cost: none\n\n"+
         "Lists your current level in each of your skills. The\n"+
         "guage beside your skill shows how close you are to\n"+
         "practicing it enough to advance to the next level.\n";
}

main(string arg) {
  object gob;
  mixed *skills;
  int i,s;
  gob=previous_object();
  skills=(mixed)gob->query_skills();
  write("     Name            Level  Practiced\n");
  s=sizeof(skills);
  for(i=0;i<s;i+=3) {
    write("  "+pad(""+skills[i],18)+pad(""+skills[i+1],-5)+
          "    "+DAEM->practice_scale(skills[i],skills[i+1],skills[i+2])+"\n");
  }
  return 1;
}