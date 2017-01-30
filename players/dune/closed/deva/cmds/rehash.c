/*
 * REHASH command for Ascension
 * update add_actions in action daemon
 */
#include "../def.h"

status main() {
    int i;
    object *people;
    object ob;

    needrank(10);
    write("Rehashing commands.\n");
    ACTIOND->rehash();
    people = users();               
    for(i=0;i<sizeof(people);i++) { 
      ob = people[i];
      if(IPOB) move_object(IPOB, ob);
      }
    return 1;
}
