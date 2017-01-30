#include "/players/mythos/closed/guild/def.h"

int ref;
string who,reff;
object ftarg;

id(str) { return str == reff || str == "follow_ref"; }

set_reference(str) { reff = str;}
set_who(str) { who = str; ftarg = find_player(who); }

get() { return 0; }
drop() { return 1; }

reset(arg) {
  if(arg) return;
  call_out("checks",3);
}

checks() {
  if(!ftarg) { destruct(this_object()); return 1;}
  if(!present("follow_1",ftarg)) { destruct(this_object()); return 1;}
  if(present("follow_1",ftarg)->query_reference() != ref) {
    destruct(this_object());
    return 1;}
call_out("checks",3);
return 1;}
