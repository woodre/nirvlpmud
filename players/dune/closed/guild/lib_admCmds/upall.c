#include "../DEFS.h"

status main(string str) {
  /* Note: for commands, use rehash instead! */
  /* command to update all guild objects     */
  int b;
  object ob;
  object * ninjas;
  ninjas = users();

  if(!IPTP->guild_manager()) return 0;
  write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(b=0; b<sizeof(ninjas); b+=1)  {
    ob = ninjas[b];
    if(IPOB)  {
       IPOB->save_me();
       destruct(IPOB);
       move_object(clone_object(GUILDOBJ), ob);
       write(pad((string)ob->query_name(),15));
       write(" updated.\n");
    }
  }
  write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}
