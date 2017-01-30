#include "/players/fred/ansi.h"
inherit "/obj/armor";

  reset(arg){
    if(arg) return;
    set_name("Mr. Hat");
    set_alias("hat");
    set_short("Mr. Hat");
    set_long(
     "Mr. Hat is Mr. Garrison's hand puppet.  He has a striped\n"+
     "top hat and a purple jacket.\n");
    set_ac(1);
    set_type("ring");
    set_weight(1);
    set_value(200);
}

do_special(owner) {
  if(random(10)) {
    string msg;
    switch(random(3)) {
      case 0: msg = "Mr. Hat takes the blow for "+owner->query_name()+"!\n"; break;
      case 1: msg = "Mr. Hat defends "+owner->query_name()+" with fierce devotion!\n"; break;
      case 2: msg = "Mr. Hat says: Take that!\nYou think you see "+owner->query_name()+"'s lips moving.\n"; break;
    }
    tell_room(environment(owner),msg);
    return 1;
  }
  return 0;
}
