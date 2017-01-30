#include "../DEFS.h"
   
status main(string str) {
  /* ejects the user from the mech */
  /* mech is later destructed      */ 
  object ob;
  string pos;
  pos = (string)TP->query_possessive();
  write("You bail out of your mech.\n");
  say(TPN+" bails out of "+pos+" mech.\n");
  ob = ETP;
  ROBOD->comm(TPN+" bails out of "+capitalize((string)ETP->query_myname())+".");
  move_object(TP, ROOM);
  destruct(ob);
  return 1;
} 
