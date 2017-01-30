#include "/players/mythos/closed/guild/def.h"

id(str) { return str == "level_dest"; }

drop() {return 1;}

reset(arg) {
if(arg) return;
  call_out("check",3);
}

check() {
object ob;
int n;
if(ep) {
  if(environment(ep)) {
ob=all_inventory(environment(ep));
for(n=0;n<sizeof(ob);n++) {
  if((present(fear,ob[n]) && ob[n]->query_guild_rank() > 5) ||
  (present("bard_obj",ob[n]) &&
   present("bard_obj",ob[n])->query_bard_level() > 7)) {
  tell_room(environment(ep),ep->short()+" is banished!\n");
  destruct(ep); destruct(this_object());
  return 1;}
  }
  } }
call_out("check",3);
return 1;}
  
