#include "defs.h"

main(string str){
  if(!str){ 
    if(previous_object()->query_mon_on()) {
      set_monitor( 0 );
      return 1;
    }
    else {
      set_monitor( 1 );
      return 1;
    }
  }
  if(str == "on"){
    set_monitor( 1 );
    return 1; }
  if(str == "off"){
    set_monitor( 0 );
    return 1; }

  write("monitor: on or off.\n");
  return 1;
}

set_monitor(int x) {
  previous_object()->set_mon_on(x);
  if( x ) {
    tell_object(USER, "Monitor now on.\n");
  }
  else {
    tell_object(USER, "Monitor now off.\n");
  }
}
