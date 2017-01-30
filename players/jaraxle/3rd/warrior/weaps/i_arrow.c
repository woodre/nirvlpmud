inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
call_out("melt_me", 10);
set_weight(0);
set_value(5);
}
short(){ return "An arrow [BROKEN]"; }
long(){ write("A broken, frosted arrow.\n"); }
id(str){ return str == "arrow" || str == "broken arrow"; }
query_save_flag(){      return 1;       }

melt_me(){
say("The broken arrow melts.\n");
destruct(this_object());
return 1; }
