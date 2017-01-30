#include <ansi.h>

get(){ return 1; }
drop(){ 
	if(environment()->query_hp() < 1) remove_call_out("end_it");
	return 1; 
}

query_weight(){ return 0; }
query_value(){ return 0; }

reset(){ 
  call_out("end_it", 1200);
  }

id(str){ return str == "backstab_object"; }

end_it(){ destruct(this_object()); }