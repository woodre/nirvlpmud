int rgender(string str){
    string what, who;
    if(!str || sscanf(str, "%s %s", who, what) !=2){
	notify_fail("Usage: rgender <who> <what>\n");
	return 0;
    }
    if(!find_player(who)){
	notify_fail("Cannot find "+who+" currently.\n");
	return 0;
    }
    if(what!="male" && what!="female" && what!="creature"){
	notify_fail("Can only set to male, female, or creature.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(who)->query_level()){
	notify_fail("You shouldn't use this on higher level players.\n");
	return 0;
    }
    find_player(who)->set_gender(what);
    write(find_player(who)->query_name()+" is now: "+find_player(who)->query_gender()+"!\n");
    return 1;
}
