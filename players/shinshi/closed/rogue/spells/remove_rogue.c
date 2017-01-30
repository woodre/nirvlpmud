#include "../defs.h"

status main(string str, object PO, object User)
{
	object player, gob;
	int experience;
	
	
	if(!str){
		write("Who would you like to kick from the guild??\n");
		return 1;
	}
	
	player = find_living(str);
	
	if(!player){
		write("That player isn't logged on!\n");
		return 1;
	}
	
	if(User->query_level() < 40)
	{
		write("I'm sorry. You don't have access to do this.\n");
		return 1;
	}
	
	if(player){
		write("Kicking "+player->query_name()+" from the guild.\n");
		tell_object(player, "You have been removed from the guild by "+User->query_name()+".\n");
		experience = (int)player->query_exp();
		gob = present("shinshi_rogue_seal", player);
		destruct(gob);
		player->set_level(1);
		player->set_extra_level(0);
		player->set_experience(0);
		player->set_guild_name(0);
		player->set_guild_file(0);
		player->set_home(0);
		player->set_attrib("cha", 5);
		player->set_attrib("int", 5);
		player->set_attrib("mag", 5);
		player->set_attrib("sta", 5);
		player->set_attrib("str", 5);
		player->set_attrib("dex", 5);
		player->set_attrib("luc", 5);
		player->set_attrib("pie", 5);
		player->set_attrib("ste", 5);
		player->set_attrib("wil", 5);
		player->add_exp(-experience);
		player->set_title("is not worthy of being a Rogue");
		player->unset_invs_sp();
		player->save_me();
		player->reset();
		CHAND->remove_channel(CHAN_NAME, User);
		write_file(LOGPATH+"KICKED", ctime()[4..15] + "  " +player->query_name()+ " has been kicked from the guild by "+User->query_name()+" .\n");
		return 1;
	}
}