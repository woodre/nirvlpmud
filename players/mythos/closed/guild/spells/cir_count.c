#include "/players/mythos/closed/guild/def.h"
int con;

id(str) { return str == "count"; }
drop() {return 1;}
get() { return 0;}

set_count(n) { con = n; 
tell_object(environment(this_object()),"Count is:"+con+"\n"+
            "Type 'final' for the execution of the circle!\n");}
query_count() { return con; }

init() {
  add_action("final","final");
}

final() {
object ob, ob2;
int power, before, k;
power = this_player()->query_sp();
this_player()->add_spell_point(-power + 1);
ob = all_inventory(environment(this_player()));
for(k=0;k<sizeof(ob);k++) {
  if(present("cir_ask",ob[k])) { 
  write_file("/players/mythos/closed/guild/circle",ctime(time())+" "+
    ob[k]->query_real_name()+" ");
  write_file("/players/mythos/closed/guild/circle",environment(ob[k]));
  write_file("/players/mythos/closed/guild/circle","\n");
  before = ob[k]->query_sp();
  power = power + before;
  ob[k]->add_spell_point(-before);
  tell_object(ob[k],"Suddenly all your energy is drained! You are very tired.\n");
  destruct(present("cir_ask",ob[k])); }
  }
if(con < 5) { write("The spell fails!\n");
this_player()->add_hit_point(-random(100));}
else {
  ob2 = clone_object("/players/mythos/closed/guild/spells/circle.c");
  ob2->set_power(power);
  ob2->set_pcheck(dpp);
  move_object(ob2,environment(this_player())); }
  destruct(this_object());
return 1;}

