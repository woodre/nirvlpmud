/*
 * DETECT_EVIL command for Ascension
 * detects all of evil alignment within the room
 * 
 */
#include "../def.h"

status main() {
  object ob;
  int det;
  string msg;

  write("You open your mind to the presence of evil...\n\n");
  ob = first_inventory(environment(this_player()));
  while(ob) {
    object oc;
    oc = ob;
    ob = next_inventory(ob);
    if(oc->query_alignment() < 0) {
       msg = "**EVIL** "+oc->short();
       if(IPTP->query_setting(COLOR)) tell_object(TP, BOLD+msg+OFF+"\n");
       else tell_object(TP, msg+"\n");
       det ++;
       }
    }
  if(!det) write("You detect no evil presence in this area.\n");
  return 1;
}
