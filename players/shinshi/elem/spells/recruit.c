#include <ansi.h>
#include "/players/wicket/guild/defs.h"
status main(string str, object PO, object User)
{
	object ob, recruiter;
	
	if(!PO->query_elder() && !PO->query_gwiz()){
		write("You are not an Elder or Guild Wizard!\n");
		return 1;
	}
	
	if(PO->query_suspend())
	{
		write("You are suspended and cannot do that.\n");
		return 1;
	}
	
	if(!str){
		write("Who are we recruiting?\n");
		return 1;
	}
	
	ob = find_player(str);
	
	if(!ob){
		write("That person is not online.\n");
		return 1;
	}
	
	if(ob->query_level() < 15){
		write(ob->query_name()+" is not worth of being an "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+NORM+".\n");
		return 1;
	}
	
	if((string)ob->query_guild_name() != "none" && ob->query_guild_name()){
		write(ob->query_name()+" is already in a guild.\n");
		return 1;
	}
	
	if(ob && !present(ob, environment(User))){
		write(ob->query_name()+" is not here!\n");
		return 1;
	}
	
	recruiter = clone_object("/players/wicket/guild/objs/book.c");
	
	if(present("temp_ele_gobj", ob))
	{
		write(ob->query_name()+" is already in the process of joining the Elementalists!\n");
		return 1;
	}
	
	if(restore_object("players/wicket/guild/members/"+ob->query_real_name()))
	{
		write("That player must speak to Guild Wizard to rejoin.\n");
		return 1;
	}
	
	if(ob && present(ob, environment(User)) && ob->query_level() >= 15){
		tell_object(User, "You recommend "+ob->query_name()+"'s name to the Ancient "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ists"+NORM+".\n");
		tell_object(ob, User->query_name()+" hands you an ancient History Book of the Elements!\n");
		move_object(recruiter, ob);
		write_file("/players/wicket/guild/logs/BOOK", ctime()[4..15] + "  " +User->query_name()+ " just gave " +ob->query_name()+ " a history book.\n");
		return 1;
	}
	
	return 1;
}