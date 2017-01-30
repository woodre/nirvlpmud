/*
  bury_hole.h
*/

#include "defs.h"

/* -------- Bury a hole (hide it) ---------- */
bury_hole(str) {
  object hole;
  if(!str || str != "hole") return 0;
  hole=present("hole", MY_ROOM);
  if(!hole) {
    write("There is no hole here to hide!\n");
    return 1;
  }
  hole->set_hidden(1);
  hole->set_owner(MY_NAME);
  write("You hide the hole.\n");
  MY_FANGS->tell_my_room(MY_NAME_CAP+" conceals a hole and looks happy.");
  return 1;
}
