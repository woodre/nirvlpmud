#include <ansi.h>

int count;
int time_len;

id(string str) {
   return str == "walker_guts";
}

long() {
  if( this_player() && this_player()->query_level() > 20 )
    write("Guts call out time: "+time_len+" has been called "+count+" times.\n");
}

reset(arg){
  call_out("time_out", 10);
  if(arg) return;
}

extra_look() {
  if (this_player() == environment())
    return "You have gruesome "+HBRED+HIY+"Walker guts"+NORM+" slung over your shoulders";
  else {
    return environment()->query_name() +
      " has gruesome "+HBRED+HIY+"Walker guts"+NORM+" slung over " +environment()->query_possessive() + " shoulders";
  }
}

time_out() {
  
  if( !environment() || !environment()->is_player() )
    destruct(this_object());
    
  switch(count++) {
    case 1:
      tell_object(environment(), "Bits of the "+HBRED+HIY+"Walker guts"+NORM+" fall to the ground as they start to decay.\n");
      break;
    case 2:
      tell_object(environment(), "The "+HBRED+HIY+"Walker guts"+NORM+" putrid smell intensifies and makes you gag.\n");
      break;
    case 3:
      tell_object(environment(), "The "+HBRED+HIY+"Walker guts"+NORM+" fall away as they decay away to nothing.\n");
      destruct(this_object());
      break;
  }
  call_out("time_out", time_len);
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

set_time_len(int amt ) { time_len = amt; }

query_time_len() { return time_len; }