#include "../defs.h"
status main(string str, object PO, object User)
{
	object gob;
	int experience;
	
	experience = (int)User->query_exp();
	gob = present("shinshi_rogue_seal", User);
	write("You elect to leave the Rogues.\n");
	destruct(gob);
	User->set_level(1);
	User->set_extra_level(0);
	User->set_guild_name(0);
	User->set_guild_file(0);
	User->set_home(0);
	User->set_attrib("cha", 5);
	User->set_attrib("int", 5);
	User->set_attrib("mag", 5);
	User->set_attrib("sta", 5);
	User->set_attrib("str", 5);
	User->set_attrib("dex", 5);
	User->set_attrib("luc", 5);
	User->set_attrib("pie", 5);
	User->set_attrib("ste", 5);
	User->set_attrib("wil", 5);
	User->add_exp(-experience);
	User->set_title("of the Forsaken Brotherhood");
	User->unset_invs_sp();
	User->save_me();
	User->reset();
	CHAND->remove_channel(CHAN_NAME, User);
	write_file(LOGPATH+"LEFT", ctime()[4..15] + "  " +User->query_name()+ " has left the guild.\n");
    return 1;
}