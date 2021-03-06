#include "../../DEFS"

string long, direction;
int time;

id(str){ return str == "ward" || str == "ward of the living"; }
short(){ return BOLD+"Ward of the dead"+OFF; }
long(str){
    write(long);
}

reset(arg){
    if(arg) return;
    long = "A large circle drawn in salt and surrounded by many arcane markings.  It\n"+
    "glows a foggy white as a mist rises from the boundries.  It seems to be warding\n"+
    "off the dead.\n";
}

init(){
    if(this_player()->query_level() > 20) return;
    if(call_other(this_player(), "id", "undead") ||
      call_other(this_player(), "id", "zombie") ||
      call_other(this_player(), "id", "ghost")){
	write(BOLD+"\nThe ward flares in color.\n"+OFF);
	write("\nYou are pushed back against the room.\n");
	say(BOLD+"The ward flares against the presence of "+this_player()->query_name()+".\n"+OFF);
	if(direction)
	    command(direction, this_player());
	else
	    this_player()->run_away();
    }
}

set_dir(d){
    switch(d){
    case "east":  direction = "east"; return 1; break; 
    case "west":  direction = "west"; return 1; break;
    case "north": direction = "north"; return 1; break;
    case "south": direction = "south"; return 1; break;
    case "up": direction = "up"; return 1; break;
    case "down": direction = "down"; return 1; break;
    case "northeast": direction = "northeast"; return 1; break;
    case "northwest": direction = "northwest"; return 1; break;
    case "southeast": direction = "southeast"; return 1; break;
    case "southwest": direction = "southwest"; return 1; break;
    default: return 0;
    }
} 

destructme(){
    tell_room(environment(this_object()),"The ward fades away.\n");
    destruct(this_object());
}

set_time(t){ time = t; call_out("destructme",t); }
set_long(l){ long = l; }

query_shatter_proof() { return 1;}
