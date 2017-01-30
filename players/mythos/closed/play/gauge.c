#include "/players/mythos/closed/ansi.h"
string who;
id(str) { return str == "gauge"; }

reset(arg) {
  if(arg) return;
   who = ({"mythos","braxana","priest","servant","meshitsukai"});
  set_heart_beat(1);
}

drop() {  des(); return 1; }

heart_beat() {
  if(!environment(this_object())) { des(); return 1; }
mon(environment(this_object()));
}

des() { destruct(this_object()); return 1; }

mon(object targ) {
int i,j;
string msg;
object me;
  if(!targ) { des(); return 1; }
  if(!living(targ)) { des(); return 1; }
  j = 0;
msg = BLU+"-- "+NORM+targ->query_real_name();
msg += "  hp:"+RED+targ->query_hp()+NORM+"/"+targ->query_mhp();
msg += " sp:"+targ->query_sp()+"/"+targ->query_msp();
msg += " wc:/ac:"+BLU+targ->query_wc()+".."+targ->query_ac();
msg += NORM;
msg += " align:"+targ->query_alignment();
if(targ->query_attack()) {
msg += " att:"+(targ->query_attack())->query_real_name()+" <";
msg += (targ->query_attack())->query_hp()+"/"+(targ->query_attack())->query_mhp()+"..";
msg += (targ->query_attack())->query_sp()+"/"+(targ->query_attack())->query_msp()+">";
}
msg += "\n";
  for(i=0;i<sizeof(who);i++) {
    me = find_player(who[i]);
  if(me) { j = 1; tell_object(me,msg); }
  }
  if(!j) des();
return 1; }
