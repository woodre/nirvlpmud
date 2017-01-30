#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()

inherit "obj/treasure";
  int x;

reset(arg) {
  if(arg) return;
  x=10;
  set_id("monitor");
  set_short("A monitor");
  set_long("Type 'mon'\n");
  set_weight(0);
  set_value(0);
}

init() {
  ::init();
  add_action("mon","mon");
  }
  
mon() {
object ob;
ob=environment(this_object());
  tell_object(ob,"\t"+BLU+"<< "+ob->query_mhp()+" - "+ob->query_hp()+" >>\n"+NORM);
  call_out("mon",3);
  return 1;}
