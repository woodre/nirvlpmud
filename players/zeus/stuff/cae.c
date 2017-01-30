inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_long(
"This is a small white octagonally shaped pill.\n");
  set_weight(1);
  set_value(0);
}

short(){
  if(!environment()) return 0;
  if(this_player()->query_level() > 19 || this_player()->query_real_name() == "dustyrose")
    short_desc = "A small octagonal pill with a 'Z' etched in it";
  else
    short_desc = 0;
  return short_desc;
}
  id(str){ return str == "pill"; }

    drop(){ return 1; }

  init(){
  ::init();
  add_action("swallow_pill", "tell_zeus");
}

swallow_pill(string str){
  object z;
  if(!(z = find_player("zeus")))
    return(notify_fail("Zeus is not logged in.\n"), 0);
  if(!str)
  {
    write("Zeus loc: "+environment(z)->short()+"\n");
    return 1;
}
  tell_object(z, "Caelin tells you: "+str+"\n");
  write("You tell Zeus: "+str+"\n");

return 1;
}

