#define DAEMON "/players/rumplemintz/closed/bin/rdaemon.c"

int rdebug(string str){
    object ob;
    if(!str){
        notify_fail("Usage: rdebug <item>\n");
	return 0;
    }
    ob = DAEMON->parse_list(str);
    if(!ob) return 0;
    debug_info(0,ob);
    debug_info(1,ob);
    return 1;
}
