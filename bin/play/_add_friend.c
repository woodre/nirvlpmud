#include <ansi.h>

int cmd_add_friend(string str)
{
	object ob, ask_ob;
	if(!str) return 0;
	if(this_player()->query_friend(str))
	{
		write("That player is already your friend!\n");
		return 1;
	}
	if(!(ob=find_player(str)))
	{
		write(str+" is not logged on.\n");
		return 1;
	}
        if((int)ob->query_level() >= 21) {
           write("Wizards can't be your friend!\n");
            return 1;
         }
	write("Asking "+capitalize(str)+" to be your friend...\n");
	ask_ob = clone_object("/obj/user/friends/ask_obj");
        ask_ob->set_ask((string)this_player()->query_real_name(),this_player());
	move_object(ask_ob, ob);
	command("askobj", ob);
	return 1;
}
