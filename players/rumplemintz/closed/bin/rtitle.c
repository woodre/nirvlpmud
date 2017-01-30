int rtitle(string str){
    string who, title;
    if(!str || sscanf(str, "%s %s", who, title) !=2){
	notify_fail("Usage: rtitle <who> <title>\n");
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
    find_player(who)->set_title(title);
    write(find_player(who)->query_name()+"'s title has been set to: "+title+"\n");
    return 1;
}
