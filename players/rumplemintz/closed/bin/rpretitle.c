int rpretitle(string str){
    string what, who;
    if(!str || sscanf(str, "%s %s", who, what) !=2){
	notify_fail("Usage: rpretitle <who> <what>\n");
	return 0;
    }
    if(!find_player(who)){
	notify_fail("Cannot find "+who+" currently.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(who)->query_level()){
	notify_fail("You shouldn't use this on higher level players.\n");
	return 0;
    }
    if(what=="|"){
	find_player(who)->set_pretitle(0);
	write("Cleared pretitle on "+find_player(who)->query_name()+"\n");
    } else {
	find_player(who)->set_pretitle(what);
	write(find_player(who)->query_name()+"'s pretitle has been set to: "+what+"\n");
    }
    return 1;
}
