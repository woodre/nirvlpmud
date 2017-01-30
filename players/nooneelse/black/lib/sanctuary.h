/*
  sanctuary.h
*/

#include "defs.h"

/* --- sanctuary (teleport to the vampire guild hall if hp <= 25) --- */
sanctuary(str) {
  int nbr;
  if (!str) {
    if (MY_FANGS->query_sanctuary_on())
      write("Sanctuary ON and set for "+MY_FANGS->query_sanctuary_hp()+"\n");
    else
      write("Sanctuary OFF and set for "+MY_FANGS->query_sanctuary_hp()+"\n");
    return 1;
  }
  str = str+"#";
  if (str=="on#") str = "on "+MY_FANGS->query_sanctuary_hp()+"#";
  if (str=="off#") str = "off "+MY_FANGS->query_sanctuary_hp()+"#";
  if (str && sscanf(str, "on %d#", nbr)!=1 && sscanf(str, "off %d#", nbr)!=1)
    if (MY_FANGS->query_sanctuary_on())
      str = "on "+str+"#";
    else
      str = "off "+str+"#";
  if (sscanf(str, "on %d#", nbr)==1) {
    MY_FANGS->set_sanctuary_on(1);
    MY_FANGS->set_sanctuary_hp(nbr);
    write("Sanctuary is ON and set for "+nbr+"\n");
    return 1;
  }
  if (sscanf(str, "off %d#", nbr)==1) {
    MY_FANGS->set_sanctuary_on(0);
    MY_FANGS->set_sanctuary_hp(nbr);
    write("Sanctuary is OFF and set for "+nbr+"\n");
    return 1;
  }
}
