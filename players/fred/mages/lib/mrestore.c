#include "/players/fred/mages/defs.h"

mrestore(ob){
 object name;
 if(!ob) ob = ENV()->query_real_name();
 name = find_player(ob);
 if(!name) return 0;
 tell_object(name,
  BOLD+BLK+"Restoring Black Circle...\n"+NORM);
 restore_object("players/fred/mages/member/"+ob);
 ENV()->set_guild_name("black circle");
 return 1;
}
