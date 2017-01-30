#include "../../DEFS"

int amount;
string name;

id(str) {
    return str == "heart" || str == "hearts" || str == "heart of " + lower_case(name) ||
    str == "necro_heart" || str == "necro_comp" || str == "heart of "+name;
}

query_heart() { return OWNER; }

reset(arg) { 
    if(arg) return;
    amount = 1;
    name = "an unknown victim";
}

init(){
    if(environment()){
	if(present("necro_heart 2",environment()) ){
	    if(present("necro_heart 2",environment()) != this_object() ){
		present("necro_heart 2",environment())->add_amount(amount);
		destruct(this_object());
	    }
	}
    }
}
set_amount(i){ amount = i; }
add_amount(i){ amount += i; }
query_amount(){ return amount; }
set_name(n){ name = n; }

short() {
    if(amount == 1)
	return "A heart torn from an unfortunate victim"; 
    else
	return amount+" hearts torn from unfortunate victims"; 
}

long() {
    write(short()+".\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ 
    return HEARTCOST * amount; 
}

query_dest_flag(){ return 1; }
