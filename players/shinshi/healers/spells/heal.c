#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	string who, msg1, msg2, msg3;
	int lv, lv2, sp, diff, inc;
	int HV, hpm, spm, XX, ok, ok2;
	object target;
		
	who = "";
	msg1 = "You lay your hands on ";
	msg2 = User->query_name()+" lays "+User->query_possessive()+" hands on ";
	msg3 = "You feel better.";
	
	lv = (int)PO->query_lev();
	lv2 = (int)User->query_level() + (int)User->query_extra_level();
	sp = lv * HEAL_VAR[1];
	diff = HEAL_VAR[4];
	XX = random(2) + 1;
	ok = 0;
	ok2 = 0;
	hpm = 0;
	spm = 0;
	
	if(lv > 50)
	{
		lv = 50;
	}
	
	if(!str)
	{
		write("Who would you like to heal?\n");
		return 1;
	}
	
	if(str)
	{
		if(sscanf(str,"%s %d",who) != 1)
		{
			who = str;
		} 
	}
	
	target = find_living(who);
	
	if(HEAL_VAR[0] > lv)
	{
		write("You cannot use that ability yet.\n");
		return 1;
	}
	
	if(sp > User->query_sp())
	{
		write("You are low on energy.\n");
		return 1;
	}
	
	if(!target)
	{
		write("No such player active.\n");
		return 1;
	}
	
	if(!present(target, environment(User)))
	{
		write("That person is not here!\n");
		return 1;
	}
	
	if((string)target->query_real_name() == "guest")
	{
		write("Guest may not be healed.\n");
		return 1;
	}
	
	if(target->query_level() > 19 && target->is_player())
	{
		write("You cannot cast upon a wizard!\n");
		return 1;
	}
	
	if(target->ShardakDragon())
	{
		write("Impossible to heal such a beast.\n");
		return 1;
	}
	
	hpm = (int)target->query_mhp() - (int)target->query_hp();
	spm = (int)target->query_msp() - (int)target->query_sp();
	
	if((hpm + spm) < 1)
	{
		write(target->query_name()+" is fully healed.\n");
		return 1;
	}
	
	HV = lv * HEAL_VAR[3];
	write("Pre prestige HV:"+HV+".\n");	/* debug */
	
	if(User->query_prestige_level() > 0)
	{
		HV = HV * 5 / 4;
		write("Post prestige HV:"+HV+".\n");	/* debug */
	}
	
	if(!target->heal_self(HV))	ok = 1;
	
	if(HV < hpm) hpm = HV;
	if(HV < spm) spm = HV;
	
	if(ok)
	{
		write("You lay your hands on "+target->query_name()+" and heal "+target->query_objective()+" ("+hpm+"/"+spm+" hp/sp amount)\n");
		say(User->query_name()+" lays "+User->query_possessive()+" hands on "+target->query_name()+".\n");
		tell_object(target, "You feel better.\n");
		return 1;
	}
	return 1;
}