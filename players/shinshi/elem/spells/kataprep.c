#include <ansi.h>
#include "/players/wicket/guild/defs.h"
status main(string str, object PO, object User)
{
	string eq_type, *armors;
	int a, s, x;
	
	if(PO->query_suspend())
	{
		write("You are suspended and cannot do that.\n");
		return 1;
	}
	
	if(User->query_ghost()) return 0;
	
	if(!str){
		tell_object(User, "Usage: 'kataprep <armor type>' or 'kataprep all'\n");
		return 1;
	}
	
	armors = (mixed)PO->query_armors();
	
	if(str == "all"){
		
		s = sizeof(armors);
		
		for(x=0; x<s; x++){
			main(armors[x], PO, User);
		}
		return 1;
	}
	
	a = member_array(str, armors);
	
	if(a == -1)
	{
		write("The Elements don't know of that armor.\n");
		return 1;
	}
	
	if(PO->check_armors(str))
	{
		tell_object(User, HIR+"\n\nThe Elements have already granted you that.\n"+NORM);
		return 1;
	}
	
	else
	{
		eq_type = str;
	}
	
	if(eq_type == "armor")
	{
		if(User->query_sp() < 50)
		{
			tell_object(User, HIR+"\n\nYou lack the sps.\n\n"+NORM);
			return 1;
		}
		
		if(User->query_money() < 1000)
		{
			tell_object(User, "\n\nYou lack the gold.\n\n");
			return 1;
		}
		
		else User->add_spell_point(-50); User->add_money(-1000);
	}
	
	else
	{
		if(User->query_sp() < 30)
		{
			tell_object(User, HIR+"\n\nYou lack the sps.\n\n"+NORM);
			return 1;
		}
		
		if(User->query_money() < 750)
		{
			tell_object(User, "\n\nYou lack the gold.\n\n");
			return 1;
		}
		
		else User->add_spell_point(-30); User->add_money(-750);
	}
	
	tell_object(User, "\nYou invoke the \"Daiki Taiyu of Aikibojitsu\" and get "+str+" from the elements.\n");
	User->RegisterArmor(PO, ({ "physical", 0, 0, "armor_special" }));
	PO->add_armors(eq_type);
	return 1;
}
			
	
	