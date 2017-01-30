#include "/players/mythos/closed/ansi.h"
#define user environment(this_object())

id(str) {return str == "protection"; }
  int count;

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

init() {
  count=100;
  call_out("safety",10);
}

safety() {
count=count-1;
  if(count < 1) {tell_object(user,"You feel less protected...\n");
      destruct(this_object()); 
      return 1;}
  if((user->query_attack())->query_id() == "spirit") {
    (user->query_attack())->run_away();
    tell_object(user,"The spirit runs away!\n");
    }
    call_out("safety",10);
    return 1;}
