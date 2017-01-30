#include "../DEFS.h"
   
status main(string str) {
  /* allows pilot to look at things in the room */
  object ob, eob;
  ob = ETP;
  move_object(TP, ROOM);
  if(!str) {
    call_other(TP, "look");
    move_object(TP, ob);
    return 1;
  }
  else
  {
  command("look "+str, TP);
  move_object(TP, ob);
  }
  return 1;
}
