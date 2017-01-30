int ralign(string str){
    object who;
    string altitle;
    if(!str || sscanf(str, "%s %s", who, altitle) !=2){
	notify_fail("Usage: ralign <who> <aligntitle>\n");
	return 0;
    }
    if(!find_player(who)){
	notify_fail("Cannot find "+who+" currently.\n");
	return 0;
    }
    if((int)this_player()->query_level() < (int)find_player(who)->query_level()){
	notify_fail("You shouldn't do that to higher level players.\n");
	return 0;
    }
    find_player(who)->set_al_title(altitle);
    write(find_player(who)->query_name()+"s altitle set to "+altitle+".\n");
    return 1;
}
