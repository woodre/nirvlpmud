#include "/players/guilds/bards/def.h"

status main(string str) {

object ob,bracer;
  if (spell(-1000, 1, 0) == -1)
    return 0;
  if(!GOB->query_is_gc())
    return 0;
  if(!str)
    FAIL("Banish which bard from the alliance?\n");
  ob = find_living(str);
  if(!ob) FAIL("Target not found.\n");
  if(!present("bard_obj", ob)) {
    write("That person is not a Bard.\n");
    return 1;
  }
  if(!(bracer=present("alliancebracer", ob))) {
     write("That Bard is not an ally.\n");
     return 1; 
  }
  tell_object(ob, "You are removed from the Alliance.\n");
  destruct(bracer);
  "players/boltar/templar/daemon/Ally.c"->Delete(ob->query_real_name());
  write("You remove "+ob->query_real_name()+" from the alliance.\n");
  return 1;
}
