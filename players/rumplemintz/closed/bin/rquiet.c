int rquiet(string str){
    object scurse;
    if(!str){
	notify_fail("Usage: rquiet <who>\n");
	return 0;
    }
    if(!find_player(str)){
	notify_fail("Cannot locate "+str+" currently.\n");
	return 0;
    }
    if(this_player()->query_level() < find_player(str)->query_level()){
	notify_fail("You shouldn't do that to higher level players.\n");
	return 0;
    }
    scurse = clone_object("/obj/shout_curse");
    scurse->start(find_player(str));
    write("Started a shout curse on "+find_player(str)->query_name()+".\n");
    return 1;
}
