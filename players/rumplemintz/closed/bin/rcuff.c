int rcuff(string str){
    if(!str){
	notify_fail("Usage: rcuff <who>\n");
	return 0;
    }
    if(!find_player(str)){
	notify_fail("Cannot locate "+str+" currently.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(str)->query_level()){
	notify_fail("You shouldn't use that on higher level players.\n");
	return 0;
    }
    move_object(clone_object("/players/rumplemintz/closed/cuffs.c"), find_player(str));
    write("You handcuffed "+find_player(str)->query_name()+".\n");
    return 1;
}
