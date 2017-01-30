/*
 * Ascension, by Dune and Snow
 * Channel daemon
 */
#include "../def.h"

announce(string str) {
/* For announcements over channel */
  int i;
  object people, ob;
  string msg;
  people = users();
  for(i=0;i<sizeof(people);i++) {
    ob = people[i];
    if(IPOB) {
      msg = "(+)HEAVENS(+) "+str;
      if(ob->query_setting(COLOR)) 
        tell_object(ob, BOLD+msg+OFF+"\n");
      else
        tell_object(ob, msg+"\n");
      }
    }
  return 1;
}

