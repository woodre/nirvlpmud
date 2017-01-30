#include "../DEFS"

int cmd(string str){
    string what, who, how, msg, msg2, who2;
    if(!str){ 
	notify_fail("What would you like to emote?\n");
	return 0;
    }
    sscanf(str,"%s %s", what, who2);
    if(!who2){
	notify_fail("Who would you like to emote to?\n");
	return 0;
    }
    if(sscanf(who2,"%s %s", who, how) !=2)
	who = who2;
    else
	sscanf(who2,"%s %s", who, how);
    if(!find_player(who)){
	notify_fail("Noone with that name can be found.\n");
	return 0;
    }
    if(how){
	msg = "You "+what+" "+how+" at "+find_living(who)->query_name();
	msg2 = this_player()->query_name()+" "+what+" "+how+" at you";
    } else {
	msg = "You "+what+" at "+find_living(who)->query_name();
	msg2 = this_player()->query_name()+" "+what+" at you";
    }
    if(environment(this_player()) != environment(find_living(who))){
	msg += " from afar.\n";
	msg2 += " from afar.\n";
    } else {
	msg += ".\n";
	msg2 += ".\n";
    }
    tell_object(this_player(), msg);
    tell_object(find_living(who), msg2);
    return 1;
}
