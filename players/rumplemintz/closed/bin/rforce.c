int rforce(string str){
    string who, what;
    if(!str || sscanf(str, "%s %s", who, what) !=2){
	notify_fail("Usage: rforce <who> <what>\n");
	return 0;
    }
    if(!find_player(who)){
	notify_fail("Cannot locate "+who+" currently.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(who)->query_level()){
	notify_fail("You shouldn't force higher level players to do things.\n");
	return 0;
    }
    command(what, find_player(who));
    write("You forced "+find_player(who)->query_name()+" to: "+what+"\n");
    return 1;
}
