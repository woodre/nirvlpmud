#include "../../defs.h"

string name;
int amount;
id(str) {
    return str == "blood" || str == "blood of " + lower_case(name) ||
    str == "necro_blood" || str == "necro_comp" ||
    str == "blood of "+name || str == "vial" || str == "vials" || str == "vial of blood";
}

query_blood() { return OWNER; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
  amount = 1;
}

init(){
  if(environment()){
  if(present("necro_blood 2",environment()) ){
  if(present("necro_blood 2",environment()) != this_object() ){
    present("necro_blood 2",environment())->add_amount(amount);
    destruct(this_object());
  }
  }
  }
}

set_name(n){ name = n; }
set_amount(i){ amount = i; }
add_amount(i){ amount += i; }
query_amount(){ return amount; }

short() {
   if(amount == 1)
    return "A small vial of dark red blood"; 
   else
    return amount+" small vials of dark red blood"; 
}

long() {
  write(short()+".\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ 
  return BLOODCOST * amount; 
}

query_dest_flag(){ return 1; }
