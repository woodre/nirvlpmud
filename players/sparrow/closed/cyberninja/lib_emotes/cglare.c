/*  Emote:  cyber glare     by: Maledicta   */

#include "../DEFS.h"

status main(string str) {
  object targ;
  string eyes;
  eyes = (string)IPTP->query_stone();
  if(!eyes) return 0;

  switch(eyes)
  {
  case "diamond":  eyes = BOLD+WHITE+"Diamond "+OFF; break;
  case "emerald":  eyes = BOLD+GREEN+"Emerald "+OFF; break;
  case "onyx"   :  eyes = BOLD+"Onyx "+OFF; break;
  case "sapphire": eyes = BOLD+BLUE+"Sapphire "+OFF; break;
  case "pearl":    eyes = BOLD+CYAN+"Pearl "+OFF; break;
  case "ruby":     eyes = BOLD+RED+"Ruby "+OFF; break;
  case "jade":     eyes = GREEN+"Jade "+OFF; break;
  case "opal":     eyes = MAGENTA+"Opal "+OFF; break;
  case "glass":    eyes = WHITE+"Glass "+OFF; break;
  case "adamantium": eyes = WHITE+"Adama"+OFF+BOLD+"ntium "+OFF; break;
  default: eyes = ""; break;
  }

  if(!str) {
    write("Your "+eyes+"eyes narrow into a glare.\n");
    say(TPN+"'s "+eyes+"eyes narrow.\n");
    return 1; }

  targ = find_player(str);

  if(!targ || targ->query_invis()) {
    write(capitalize(str)+" is not online.\n");
    return 1; }
  if(environment(targ) == environment(TP)) {
    write("Your "+eyes+"eyes narrow into a glare at "+capitalize(str)+".\n");
    say(TPN+"'s "+eyes+"eyes narrow into a glare at "+capitalize(str)+".\n");
    return 1; }
  else {
    write("Your "+eyes+"eyes glare at "+capitalize(str)+" from afar.\n");
    tell_object(targ,TPN+"'s "+eyes+"eyes glare at you from afar.\n");
    return 1; }

return 1; }

