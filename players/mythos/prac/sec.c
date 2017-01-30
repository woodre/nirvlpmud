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
return 0;}

che() {
  object ob;
  ob=find_player(who);
 if(!ob) {
   call_out("che",3);
return 1;}
  write(HIR+BLINK+"\n\t\tFOUND!\n\n"+NORM);
  destruct(ob);
return 1;}
