#include "../defs.h"
int cmd(string str) {
  if(!str) {
    notify_fail("Usage: login [church|guildhall]\n");
    return 0;
  }
  if(str=="guildhall")
   TP->set_home(ROOMDIR+"lounge.c");
  else if(str=="church")
    TP->set_home(0);
  else if(str=="workroom" && TP->query_level() >= 21)
    TP->set_home("/players/"+TP->query_real_name()+"/workroom.c");
  else {
    write("That is not an approved login room.\n");
    return 1;
  }
  write("You set your login to '"+str+"'.\n");
  return 1;
}
