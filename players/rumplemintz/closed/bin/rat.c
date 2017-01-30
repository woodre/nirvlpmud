int rat(string str){
    string who, what;
    object back;
    if(!str || sscanf(str, "%s %s", who, what) !=2){
	notify_fail("Usage: rat <who> <command>\n");
	return 0;
    }
    if(!find_player(who)){
	notify_fail("Cannot locate "+who+" currently.\n");
	return 0;
    }
    back = environment(this_player());
    move_object(this_player(), environment(find_player(who)));
    command(what, this_player());
    move_object(this_player(), back);
    write("Executed: "+what+" |||| at "+find_player(who)->query_name()+"'s environment.\n");
    return 1;
}
