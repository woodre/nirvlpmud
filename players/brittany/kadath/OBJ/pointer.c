#include "/open/ansi.h" 

inherit "/obj/treasure";

reset(arg){
if(arg)return;

set_id("pointer");
set_weight(1000);
}

init(){
::init();
add_action("turn","turn");
}

turn(str){
  if(!str || str != "pointer"){
  notify_fail("Turn what?\n");
  return 0; }
  write("The pointer turns, and CLICK!   the door creaks open.\n\n"+
   ""+HIR+"The Great One appears"+NORM+"\n");
move_object(clone_object("/players/brittany/kadath/NPC/carter.c"),this_environment());
  destruct(this_object());
  return 1; }
