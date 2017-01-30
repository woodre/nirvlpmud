string short(){ return "Hand cuffs"; }

void long(){ write("These are special cuffs just for you.\n"); }

void reset(int arg){ if(arg) return; }

void init(){ add_action("quit"); add_xverb(""); }

int quit(){
    if((string)this_player()->query_real_name() != "rumplemintz"){
	write("You are paralyzed.\n");
	say(this_player()->query_real_name()+" has a spaz attack.\n");
	return 1;
    }
    return 0;
}

int drop(){ return 1; }
int get(){ return 1; }

int id(string str){ return str=="nairb" || str=="cuffs"; }
