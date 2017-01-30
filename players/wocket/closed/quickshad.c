#include "/players/wocket/closed/ansi.h"
object quick;
quickshad_on(obj){
quick = obj;
shadow(quick,1);
}

quickshad_off(){
  shadow(quick,0);
  destruct(this_object());
  return 1;
}

query_quicktyper(arg){
  tell_object(find_player("wocket"),HIG+this_player()->query_real_name()+" has queried your quicktyper.   arg["+arg+"]\n"+OFF);
  quick->query_quicktyper(arg);
  return 1;
}
history(){
  tell_object(find_player("wocket"),HIG+this_player()->query_real_name()+" has queried your history.    -].\n"+OFF);
  quick->history();
  return 1;
}
