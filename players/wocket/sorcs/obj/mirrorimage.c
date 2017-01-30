#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

object masterobj;
string mastername;
reset(arg){
  ::reset(arg);
  if(arg) return;
  set_alias(mastername);
  set_name("mirror");
  set_short("blahblahblah");
  set_wc(0);
  set_hp(50);
  set_ac(0);
  call_out("follow_master",4);
}

follow_master(){
if(!masterobj) destruct(this_object());
if(environment(this_object()) != environment(masterobj)){
  move_object(this_object(),environment(masterobj));
  say(capitalize(mastername)+" arrives.\n");
}
call_out("follow_master",4);
}
second_life(){
say(BOLD+"The mirror  S H A T T E R S .\n"+NORM); 
destruct(present("corpse",environment(this_player())));
return 0;}

set_master(ob){
  masterobj = ob;
  mastername = ob->query_real_name();
  set_short(ob->short());
  set_alias(mastername);
  set_long("A mirror image of "+capitalize(mastername)+".\n");
}
is_player(){ return 1; }
query_npc(){ return 0; }
query_interactive(){ return 1; }