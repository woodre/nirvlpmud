#include "../DEFS"

int cmd(string str){
    string msg;
    if(!str){
	notify_fail("What necro bug would you like to report?\n"+
	  "(Please completely describ the bug and location)\n");
	return 0;
    }
    msg = HIR+"\n>>> "+OFF+this_player()->query_real_name()+"\n   :"+
    file_name(environment(this_player()))+"\n   :"+str+"\n";
    write_file("players/guilds/necro/log/NBUG", msg);
    write(HIR+"You report the necro bug:\n"+OFF+msg);
    return 1;
}
