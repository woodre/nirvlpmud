/*
  sanctuary.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --- sanctuary (teleport to the alchemist guild hall if hp <= set amount) --- */
sanctuary(str) {
  int nbr;

  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("feather") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (feather).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (!str) {
    if (MY_POUCH->query_sanctuary_on())
      write(NORM+CYN+"Sanctuary ON and set for "+MY_POUCH->query_sanctuary_hp()+"\n"+NORM);
    else
      write(NORM+CYN+"Sanctuary OFF and set for "+MY_POUCH->query_sanctuary_hp()+"\n"+NORM);
    return 1;
  }
  str = str+"#";
  if (str=="on#") str = "on "+MY_POUCH->query_sanctuary_hp()+"#";
  if (str=="off#") str = "off "+MY_POUCH->query_sanctuary_hp()+"#";
  if (str && sscanf(str, "on %d#", nbr)!=1 && sscanf(str, "off %d#", nbr)!=1)
    if (MY_POUCH->query_sanctuary_on())
      str = "on "+str+"#";
    else
      str = "off "+str+"#";
  if (sscanf(str, "on %d#", nbr)==1) {
    MY_POUCH->set_sanctuary_on(1);
    MY_POUCH->set_sanctuary_hp(nbr);
    write(NORM+CYN+"Sanctuary is ON and set for "+nbr+"\n"+NORM);
    MY_POUCH->subtract_quantity("feather", 1);
    MY_PLAYER->add_spell_point(- 50);
    return 1;
  }
  if (sscanf(str, "off %d#", nbr)==1) {
    MY_POUCH->set_sanctuary_on(0);
    MY_POUCH->set_sanctuary_hp(nbr);
    write(NORM+CYN+"Sanctuary is OFF and set for "+nbr+"\n"+NORM);
    return 1;
  }
}
