/*
 * An object for allies of the Servants of Shardak
 * Makes the ally join in on the guild channel
 */
#include "../def.h"
static mapping  cmds;
static int      color_flag, muffled;

id(str) { return str == "mark" || str == "allymark";}
drop()  { return 1;}
get()   { return 1;}
query_auto_load() { return (OBJDIR + "allymark:" + color_flag);}
init_arg(s) { color_flag = atoi(s);}
extra_look() { return environment()->query_name() + " is an ally of the Servants of Shardak";}
short() { if (this_player() == environment()) return "The mark of an ally";}

reset(a)
{
    if (!(a || root())) {
	CHANNELD->register(this_object());
	cmds = ACTIOND->query_cmds();
    }
}

long()
{
    write("\
With this mark you can easily communicate with your allies, the\n\
Servants of Shardak. Available are the commands gt, ge, gts, gw,\n\
color, and leave alliance.\n");
}

init()
{
    if (environment() == this_player()) {
	add_action("cmd_leave", "leave");
	add_action("cmd_hook", "color");
	add_action("cmd_hook", "gts");
	add_action("cmd_hook", "gw");
	add_action("cmd_hook", "ge");
	add_action("cmd_hook", "gt");
    }
}

cmd_leave(string str)
{
    if (str != "alliance") return 0;
    CHANNELD->deregister(this_object());
    write("You are no longer an ally of the Servants of Shardak.\n");
    destruct(this_object());
    return 1;
}

cmd_hook(string str)
{
    string cmd;
    if (cmd = cmds[query_verb()])
	return (status) cmd->main(str);
}

GuildClass(x) { return -1;}
Color(cl)     { return (color_flag ^= cl);}
Muffled(mf)   { return (muffled ^= mf);}

receive_message(int p, string msg, string cmsg)
{
    if (!muffled && environment())
	tell_object(environment(), color_flag ? cmsg : msg);
}
