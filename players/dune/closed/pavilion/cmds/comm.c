#include "../DEFS.h"

status main(string str) {
  /* talk to other mechs over a channel */
  string name;
  object *everyone;
  object pilot, ob;  
  int i;
  if(!str) {
    write("Usage: comm <message>\n");
    return 1;
  }
  name = capitalize((string)ETP->query_myname());
  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    ob = everyone[i];
    pilot = IPOB;
    if(pilot)
      tell_object(ob, "[["+name+"]] "+str+"\n");
  }
  return 1;
}
