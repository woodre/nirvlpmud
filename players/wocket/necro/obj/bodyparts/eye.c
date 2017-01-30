#include "../../defs.h"

string name;
int amount;
id(str) {
    return str == "eye" || str == "eyes" || str == "eye of " + lower_case(name) ||
    str == "necro_eye" || str == "necro_comp" || str == "eye of "+name;
}

query_eye() { return OWNER; }

reset(arg) { 
  if(arg) return;
  amount = 1;
  name = "an unknown victim";
}

init(){
  if(environment()){
  if(present("necro_eye 2",environment()) ){
  if(present("necro_eye 2",environment()) != this_object() ){
    present("necro_eye 2",environment())->add_amount(amount);
    destruct(this_object());
  }
  }
  }
}

set_name(n){ name = n; }

short() {
   if(amount == 1)
    return "An eye removed from a skull"; 
   else
   if(amount == 2)
    return "2 eyes removed from a skull";
   else
    return amount+" eyes removed from some skulls"; 
}
set_amount(i){ amount = i; }
add_amount(i){ amount += i; }
query_amount(){ return amount; }
long() {
  write(short()+".\n");
}
get() { return 1; }
query_weight() { return 1; }
query_value(){ 
  return EYECOST * amount; 
}

query_dest_flag(){ return 1; }
