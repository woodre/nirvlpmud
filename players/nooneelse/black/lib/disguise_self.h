/*
  disguise_self.h
*/

#include "defs.h"

/* -------- Disguise self (show cape & fangs or not) ---------- */
disguise_self(str) {
  if (str=="on") {
    MY_FANGS->set_disguise_on(1);
    write("Disguise is now on.  "+
          "(Other players won't see the vampire's cloak & fangs.)\n");
    return 1;
  }
  if (str=="off") {
    MY_FANGS->set_disguise_on(0);
    write("Disguise is now off.  "+
          "(Other players now see the vampire's cloak & fangs.)\n");
    return 1;
  }
}
