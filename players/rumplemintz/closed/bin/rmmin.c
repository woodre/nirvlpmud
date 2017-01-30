int rmmin(string str){
  string who, what;
    if(!str || sscanf(str, "%s %s", who, what) !=2){
	notify_fail("Usage: rmmin <who> <what>\n");
	return 0;
    }
    if(!find_player(who)){
	notify_fail("Cannot find "+who+" currently.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(who)->query_level()){
	notify_fail("You shouldn't use that on higher level players.\n");
	return 0;
    }
    find_player(who)->set_mmsgin(what);
    command("save silent", find_player(who));
    write(find_player(who)->query_name()+"'s mmin set to: "+what+"\n");
    return 1;
}
