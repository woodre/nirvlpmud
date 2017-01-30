#include "/players/mythos/closed/ansi.h"

id(str) {return str == "sec"; }
string who;
short() {return "check"; }

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

init() {
  add_action("secure","secure");
}

secure(str) {
  sscanf(str,"%s",who);
  call_out("che",3);
return 1;}

che() {
  object ob, ob1;
  ob1=environment(this_object());
  ob=find_player(who);
  if(!ob) {
    call_out("che",3);
  return 1;}
  else {
  tell_object(ob1,HIR+"\n\t\tFOUND!\n\n"+NORM);
  destruct(ob);
  call_out("che",3);
  return 1;}
return 1;}
