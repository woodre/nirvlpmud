#include "/players/mythos/closed/guild/def.h"
object who, ob;
string names;
int start;
id(str) {return str == "cycle" || str == "fear_link";}

set_who(ob) { who = ob; names = who->short();}
query_who() { return who;}
set_start(n) { start = n;}
query_start() { return start;}

get() { return 0;}
drop() { return 1;}

begin() {
int old, fear_point;
int sap;
if(!ep) return 1;
if(!who) { tell_object(ep,"You no longer feed from "+names+"!\n"); destruct(this_object()); return 1;}
old = who->query_hp();
if(old < start) { fear_point = start - old;
tell_object(ep,"You gain strength from the fear of "+who->short()+".\n");}
else { fear_point = 0;}
start = old;
ep->add_hit_point(fear_point);
if(environment(who) != environment(ep)) {
      if(fear_point < 25) sap = 1; else sap = fear_point/5;
     ep->add_spell_point(-sap);
}
call_out("begin",1);
return 1;}
