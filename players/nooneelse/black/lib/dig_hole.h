/*
  dig_hole.h
*/

#include "defs.h"

/* -------- Dig a hole (to hide stuff in) ---------- */
dig_hole(str) {
  object hole;
  if(!str || str != "hole") return 0;
  if (present("guild hole", MY_ROOM)) {
    write("Hmmm.  You stop digging because the ground seems to be soft as\n"+
          "if there's already a hole concealed here.\n");
    return 1;
  }
  write("You dig a hole in the ground.\n");
  MY_FANGS->tell_my_room(MY_NAME_CAP+" digs a hole in the ground.");
  hole=clone_object(GUILD_HOLE);
  move_object(hole, MY_ROOM);
  hole->self_destruct_timer(60);
  return 1;
}
