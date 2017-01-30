#include "/players/catacomb/saiyan/def.h"

saiyan()
{
  write(HIY+"                  Saiyan Help                 "+HIW+"\n\n"+
      " Born originally on the planet Vegeta, saiyans\n"+
      "are a proud race of warriors.  Saiyans are sent\n"+
      "throughout the universe to destroy anyone who\n"+
      "opposes them.  Now they have reached Nirvana.  As\n"+
      "a saiyan you must uphold the proud name of the race."+BOLD+RED+"\n"+
      "       Your Saiyan powers are as follows:\n\n"+

      "   st,ste               Guild line talk and emote\n"+
      "   block                Turn off guild line\n"+
      "   saiyans              Guild who\n"+
      "   study <armor>        Use saiyan blood to examine armor\n"+
      "   S_emotes             Saiyan specific emotes\n"+
      "   powers               A list of your saiyan powers\n"+
      "   leave_saiyans        Leave the ranks of the saiyans\n"+NORM);
  return 1;
}
