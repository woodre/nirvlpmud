#include "../../DEFS"

int amount;
string name;

id(str) {
    return str == "soul" || str == "soul of " + lower_case(name) ||
    str == "necro_soul" || str == "necro_comp" || str == "crystals" ||
    str == "souls" || str == "glowing crystals" ||
    str == "soul of "+name || str == "crystal" || str == "glowing crystal";
}

query_soul() { return OWNER; }

reset(arg) { 
    if(arg) return;
    name = "an unknown victim";
    amount = 1;
}

init(){
    if(environment()){
	if(present("necro_soul 2",environment()) ){
	    if(present("necro_soul 2",environment()) != this_object() ){
		present("necro_soul 2",environment())->add_amount(amount);
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
	return "A small crystal holding a lost soul"; 
    else
	return amount+" small crystals holding lost souls"; 
}
long(){
    write(short()+"\n");
}

query_dest_flag(){ return 1; }
get() { return 1; }
query_weight() { return 1; }
query_value(){ 
    return SOULCOST * amount; 
}
