#include <ansi.h>
#include "/players/wicket/guild/defs.h"
status main(string str, object PO, object User)
{
	object gob, scar;
	
	if(!str)
	{
		write("The "+HIW+"Ancient Master"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" intones: Please use "+BOLD+"abandon guild"+NORM+" if you are sure of this decision.\n");
		return 1;
	}
	
	if(str != "guild")
	{
		write("The "+HIW+"Ancient Master"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" intones: Please use '"+BOLD+"abandon guild"+NORM+"' if you are sure of this decision.\n");
		return 1;
	}
	
	scar = clone_object("/players/wicket/guild/objs/scar.c");
	
	if(str == "guild")
	{
		gob = present("wicket_element_orb", User);
		write(BOLD+"You abandon the "+NORM+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+BOLD+". The "+NORM+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+BOLD+" rip away at your soul!\n"+NORM);
		destruct(gob);
		CHAND->remove_channel(CHAN_NAME, User);
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
		User->add_exp(-((int)User->query_exp() * 2/3));
		User->set_title("has forsaken the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+".");
		User->save_me();
		User->reset();
		write_file("/players/wicket/guild/logs/LEFT", ctime()[4..15] + "  " +User->query_name()+ " has left the guild and forsaken us.\n");
		move_object(scar, User);
		User->death(BOLD+"Khnum"+NORM+", "+HIW+"Ancient Master "+NORM+"of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM);
		return 1;
	}
	return 1;
}