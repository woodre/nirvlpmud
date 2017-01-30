#include "../../DEFS"

int amount;
string name;

id(str) {
    return str == "spine" || str == "spine of " + lower_case(name) ||
    str == "necro_spine" || str == "necro_comp" || str == "spines" ||
    str == "spine of "+name || str == "spinal column" || str == "spinal columns";
}
reset(arg) { 
    if(arg) return;
    name = "an unknown victim";
    amount = 1;
}

init(){
    if(environment()){
	if(present("necro_spine 2",environment()) ){
	    if(present("necro_spine 2",environment()) != this_object() ){
		present("necro_spine 2",environment())->add_amount(amount);
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
	return "A severed spinal column"; 
    else
	return amount+" severed spinal columns"; 
}

long() {
    write(short()+".\n");
}
get() { return 1; }
query_weight() { return 1; }
query_spine() { return OWNER; }
query_value(){ 
    return SPINECOST * amount; 
}
query_dest_flag(){ return 1; }
