int rfrog(string str){
    if(!str){
	notify_fail("Usage: rfrog <who>\n");
	return 0;
    }
    if(!find_player(str)){
	notify_fail("Cannot find "+str+" currently.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(str)->query_level()){
	notify_fail("You shouldn't use this on higher level players.\n");
	return 0;
    }
    if(find_player(str)->query_frog())
        write("You defrog "+find_player(str)->query_name()+"\n");
    else
        write("You frog "+find_player(str)->query_name()+"\n");
    find_player(str)->frog_curse(!find_player(str)->query_frog());
    return 1;
}
