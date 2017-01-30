int full;

int id(string str){
    if(full) return str=="rumplemintz" || str=="bottle";
    return str=="bottle";
}

string short(){
    if(full) return "bottle of rumplemintz";
    return "empty bottle";
}

int query_value(){
    if(!full) return 10;
    return 0;
}

void long(){ write(short()+".\n"); }

void reset(int arg){
    if(arg) return;
    full = 1;
}

int drink(string str){
    if(!str) return 0;
    if(!full) return 0;
    if(str=="rumplemintz" || str=="bottle" || str=="from bottle"){
	if(!this_player()->drink_alcohol(10)) return 1;
	this_player()->heal_self(350);
	full = 0;
	write("You feel invigorated and ready to do more adventuring!\n");
	say(this_player()->query_name()+" slams a bottle of rumplemintz.\n");
	return 1;
    }
}

void init(){
    add_action("drink", "drink");
}

int get(){ return 1; }
int query_weight(){ return 1; }
