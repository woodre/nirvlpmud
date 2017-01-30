inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
call_out("dest_me", 30);
set_weight(0);
set_value(5);
}
short(){ return "An arrow [BROKEN]"; }
long(){ write("A broken arrow with a chipped stone tip.\n"); }
id(str){ return str == "arrow" || str == "broken arrow"; }
query_save_flag(){      return 1;       }
dest_me(){
destruct(this_object());
return 1; }

