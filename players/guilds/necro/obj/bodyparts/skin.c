#include "../../DEFS"

int amount;
string name;

id(str) {
    return str == "skin" || str == "skin of " + lower_case(name) ||
    str == "necro_skin" || str == "necro_comp" || str == "skins" ||
    str == "patches" || str == "patches of skin" ||
    str == "skin of "+name || str == "patch" || str == "patch of skin";
}

query_skin() { return OWNER; }

reset(arg) { 
    if(arg) return;
    name = "an unknown victim";
    amount = 1;
}

init(){
    if(environment()){
	if(present("necro_skin 2",environment()) ){
	    if(present("necro_skin 2",environment()) != this_object() ){
		present("necro_skin 2",environment())->add_amount(amount);
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
	return "A small patch of skin"; 
    else
	return amount+" small patches of skin"; 
}
long(){
    write(short()+"\n");
}

query_dest_flag(){ return 1; }
get() { return 1; }
query_weight() { return 1; }
query_value(){ 
    return SKINCOST * amount; 
}
