#include "/players/maledicta/ansi.h"

get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

reset(){ 
  call_out("end_it", 6);
  }

id(str){ return str == "wc_mod" || str == "generic_wc_bonus"; }

gen_wc_bonus(){
  return -1; 
  }

end_it(){ destruct(this_object()); }