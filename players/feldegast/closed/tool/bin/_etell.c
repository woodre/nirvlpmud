#include "/players/feldegast/defines.h"

do_cmd(arg) {
  string who,what;
  if(!arg) {
    notify_fail("Tell who what?\n");
    return 0;
  }
  sscanf(arg,"%s %s",who,what);
  if (!find_player(who)) {
    write("That player is not on right now.\n");
    return 1;
  }
  if (!what) {
    write("What do you want to say?\n");
  }
  tell_object(find_player(who),HIB+format(TPRN+" tells you,\""+NORM+what+HIB+"\"",70)+NORM);
  find_player(who)->add_tellhistory(format(TPRN+" tells you,\""+what+"\"",70));
  write(HIB+"You tell "+who+",\""+NORM+what+HIB+"\"\n"+NORM);
  return 1;
}



