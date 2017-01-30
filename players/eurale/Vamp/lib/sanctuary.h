/*
  sanctuary.h
*/

#include "/players/eurale/defs.h"

/* --- sanctuary (teleport to the vampire guild hall if hp <= 25) --- */
sanctuary(str) {
  int nbr;
  if (!str) {

if(EFANGS->query_sanctuary_on())
  write("Sanctuary ON and set for "+EFANGS->query_sanctuary_hp()+"\n");
else
  write("Sanctuary OFF and set for "+EFANGS->query_sanctuary_hp()+"\n");
return 1; }

if(TPL < 7 || TPGEXP < 667 || TP->query_attrib("int") < 12) {
  write("You lack the skills to use this ability.\n");
  return 1; }

str = str+"#";
if(str=="on#") str = "on "+EFANGS->query_sanctuary_hp()+"#";
if(str=="off#") str = "off "+EFANGS->query_sanctuary_hp()+"#";
if(str && sscanf(str, "on %d#", nbr)!=1 && sscanf(str, "off %d#", nbr)!=1)
  if(EFANGS->query_sanctuary_on())
      str = "on "+str+"#";
  else
      str = "off "+str+"#";

if(sscanf(str, "on %d#", nbr) == 1) {
  EFANGS->set_sanctuary_on(1);
  EFANGS->set_sanctuary_hp(nbr);
  write("Sanctuary turned "+BOLD+"ON"+NORM+" and set for "+BOLD+
        nbr+NORM+".\n");
return 1; }

if(sscanf(str, "off %d#", nbr)==1) {
  EFANGS->set_sanctuary_on(0);
  EFANGS->set_sanctuary_hp(nbr);
  write("Sanctuary turned "+BOLD+"OFF"+NORM+" and set for "+BOLD+
        nbr+NORM+".\n");
return 1; }

}
