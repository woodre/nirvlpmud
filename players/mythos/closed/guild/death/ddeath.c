#include "/players/mythos/closed/ansi.h"

query_auto_load() {
    return "/players/mythos/closed/guild/death/ddeath.c:"; }
    
id(str) {return str == "deathmark"; }

drop() {return 1;}
get() {return 0;}

init() {
if(environment(this_object())) {
  if(environment(this_object())->is_player() && 
  this_player() == environment(this_object())) {
    write("Death has its hold upon you!\n"); 
    move_object(this_player(),"/players/mythos/closed/guild/death/death.c");
    call_out("sets",3);
    } }
}

sets() {
  environment(this_object())->set_home("/players/mythos/closed/guild/death/death.c");
  environment(this_object())->save_me();
return 1;}