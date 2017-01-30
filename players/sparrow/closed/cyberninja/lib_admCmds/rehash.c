/*
 * REHASH command
 * update add_actions in action daemon
 */
#include "../DEFS.h"

status main() {
  int i;
  object *people;
  object ob;

  if(!IPTP->guild_manager()) return 0;
  write("Rehashing commands.\n");
  call_other(ACTIOND, "rehash");
  people = users();               
  for(i=0;i<sizeof(people);i++) { 
    ob = people[i];
    if(IPOB) move_object(IPOB, ob);
  }
  return 1;
}
