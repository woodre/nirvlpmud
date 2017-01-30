#include "../../defs.h"
int owc,oac;
int ac_times,wc_times;

id(str) { return str == "necro_stat_change"; }

drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  ac_times = 0;
}

add_ac_times(arg) { ac_times = ac_times + arg; }
query_ac_times() { return ac_times; }

add_wc_times(arg) { wc_times = wc_times + arg; }
query_wc_times() { return wc_times; }

set_orgac(i){ oac = i;}
set_orgwc(i){ owc = i;}
query_orgac(){ return oac; }
query_orgwc(){ return owc; }

restore(){
object ob;
   ob = environment(this_object());
   if(ob){
     if(ob->is_npc()){
       tell_room(environment(ob),BOLD+ob->query_name()+" regains full strength and awareness.\n"+OFF);
       ob->set_ac(oac);
       ob->set_wc(owc);
       destruct(this_object());
     }
   }
}

set_time(i){ call_out("restore",i); }