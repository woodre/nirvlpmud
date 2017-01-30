#define DAEMON "/players/rumplemintz/closed/bin/rdaemon.c"

int rdest(string str){
    object ob;
    if(!str){
	notify_fail("Usage: rdestruct <item>\n");
	return 0;
    }
    ob=DAEMON->parse_list(str);
    if(!ob) return 0;
    destruct(ob);
    write("Ok.\n");
    return 1;
}
