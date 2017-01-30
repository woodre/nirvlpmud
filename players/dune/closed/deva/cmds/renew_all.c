/*
 * RENEW_ALL command for Ascension
 * renew everyone's guild object
 */
#include "../def.h"

status main() {
  int i;
  object *people;
  object ob;

  needrank(11);
  people = users();
  write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(i=0;i<sizeof(people);i++)  {
    ob = people[i];
    if(IPOB) {
      IPOB->save_me();
      destruct(IPOB);
      move_object(clone_object(GUILDOBJ), ob);
      write(pad(((string)ob->query_name()),15)+" updated.\n");
      tell_object(ob, "Your spirit has been updated.\n");
      }
    }
  write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}
