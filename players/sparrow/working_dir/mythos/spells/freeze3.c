#include "/players/mythos/closed/ansi.h"
int k, j;

id(str) {return str == "freeze.c"; }
set_dropped(n) { j = n; }

reset(arg) {
  if(arg) return;
  call_out("check",25+random(50));
}

drop() {return 1;}
init() {
  if(this_player() == environment(this_object())) {
  k = this_player()->query_ac();
  if(k - j > 10) { j = 10; }
  else { j = k - j; }
  if(j < 0) { j = 0; }
    this_player()->set_ac(j);
  }
  add_action("quiet");add_xverb("");
}

quiet() {
  write(BLU+"You are frozen!\n"+NORM); 
  return 1;}

check() {
 k = k + 1 + random(10); 
 if(environment(this_object())) {
 if(environment(environment(this_object()))) {
  environment(this_object())->set_ac(k);
  tell_room(environment(environment(this_object())),
  capitalize(environment(this_object())->query_name())+
            " is no longer frozen.\n"); } }
  destruct(this_object());
return 1;}
