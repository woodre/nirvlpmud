#include "../DEFS.h"

status main(string str) {
  /* way for players to clone up their speedters */
  if(!((status)IPTP->item_legs()) && !IPTP->guild_wiz()) return 0;
  if(present(LEGS_ID, TP)) {
    write("Your leg actuators are already activated.\n");
    return 1;
  }
  move_object(clone_object(OBJDIR + "/speed.c"), TP);
  tell_object(TP, "You have activated your leg actuators.\n");
  tell_room(environment(TP), TPN+"'s leg muscles tense up.\n"+
            "____________________ __________ _____ ___ __ _\n");
  return 1;
}
