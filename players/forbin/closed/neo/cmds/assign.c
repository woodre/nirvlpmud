#include "../defs.h"
#include "../specfuns.h"

void assign_tents(int t, string str, object gob, object player)
{
  string assignment;
  string num;
  
  if((int)player->query_ghost()) return 0;
  
  num = t+1;
  
  if(!str) 
    assignment = "unassigned";
	else 
	  assignment = str;
	if((string)gob->query_tents(t, t+1))
	{
		if((string)gob->query_tents(t, t+1) == "unavailable")
		  tell_object(player,
		    "Tentacle number "+num+" is currently restricted by your armor.\n");
		else
		  tell_object(player,
		    "Reassigning tentacle number "+num+" to "+CAP(assignment)+".\n");
	}
	else
	{ 
		tell_object(player,
		    "Assigning tentacle number "+num+" to "+CAP(assignment)+".\n");
    if(assignment == "burnoff" || assignment == "regeneration")
      tell_object(player, 
        "A tentacle retreats into your body to perform its work...\n");
  }
  gob->set_tents(t, assignment);
}


status main(string str, object gob, object player)
{
	int which, var1, var2;
	int i, diff;
	string towhat;
		
	if(!str)
	{
		tell_object(player,
		  "Assign tentacle # to <task>  -or-\n"+
			"Assign tentacles # through # to <tasks>\n"+
		PGC+"Tasks:"+NORM+"\n");
		tell_object(player,
		  "    "+HIR+"Attack"+NORM+"\n");
		tell_object(player,
		  "    "+HIR+"Defend"+NORM+"\n\n");		
    if((int)gob->query_skill("control") > 4) 
      tell_object(player,
        "    "+HIM+"Burnoff"+NORM+"\n");
		if((int)gob->query_skill("control") > 6) 
		  tell_object(player,
		    "    "+HIG+"Regeneration"+NORM+"\n");
		tell_object(player,
		  "For a listing of tentacle assignments, type 'list tentacles'.\n");
		return 1;
	}

	
	if(sscanf(str, "tentacle %d to %s", which, towhat) == 2)
	{
	  if(which < 1 || which > 10)
    { 
      tell_object(player,
        "Tentacle # must be between 1 and 10.\n"); 
      return 1; 
    }
    if(towhat == "attack")
    {  
    	assign_tents(which - 1, towhat, gob, player); 
    	return 1; 
    }
		else if(towhat == "defend")
		{ 
			assign_tents(which - 1, towhat, gob, player); 
			return 1; 
		}
    else if(towhat == "burnoff" && (int)gob->query_skill("control") > 4)
    { 
    	assign_tents(which - 1, towhat, gob, player); 
    	return 1; 
    }
		else if((towhat == "regeneration" || towhat == "regen") && (int)gob->query_skill("control") > 6)
		{ 
			assign_tents(which - 1, "regeneration", gob, player); 
			return 1; 
		}
		else if(towhat == "none" || towhat == "unassigned")
		{ 
			assign_tents(which - 1, 0, gob, player); 
			return 1; 
		}
		else
		{ 
			tell_object(player,
			  "That task is unavailable.  Type 'assign' to see a valid list.\n"); 
			  return 1; 
    }
		return 1;
  }		

	if(sscanf(str, "tentacles %d through %d to %s", var1, var2, towhat) == 3)
	{
    if(var1 < 1 || var1 > 10)
    { 
    	tell_object(player,
    	  "Tentacle #'s must be between 1 and 10.\n"); 
     return 1; 
    }
    if(var2 < 1 || var2 > 10)
    { 
    	tell_object(player,
    	  "Tentacle #'s must be between 1 and 10.\n"); 
    	return 1; 
    }
    if(var1 > var2)
    {	
    	tell_object(player,
    	  "First tentacle number must be lower than the second number.\n"); 
      return 1; 
    }
    if(towhat == "burnoff" && (int)gob->query_skill("control") > 4)
    {
		  for(i = var1 - 1; i < var2; i++)
		  {
				assign_tents(i, towhat, gob, player);
			}
      return 1;
		}
			else if((towhat == "regeneration" || towhat == "regen") && (int)gob->query_skill("control") > 6)
			{
			  for(i = var1 - 1; i < var2; i++)
			  {
				  assign_tents(i, towhat, gob, player);
				}
        return 1;
			}
			else if(towhat == "none" || towhat == "unassigned")
			{
				for(i = var1 - 1; i < var2; i++)
				{
				  assign_tents(i, 0, gob, player);
				}
        return 1;
			}
			else if(towhat == "attack")
			{
				for(i = var1 - 1; i < var2; i++)
				{
			  	assign_tents(i, towhat, gob, player);
				}
        return 1;
			}
			else if(towhat == "defend")
			{
				for(i = var1 - 1; i < var2; i++)
				{
					assign_tents(i, towhat, gob, player);
				}
         return 1;
      }
			else
			{ 
				tell_object(player,
				  "That task is unavailable.  Type 'assign' to see a valid list.\n"); 
				return 1; 
			}

		tell_object(player,
		  "That task is unavailable.  Type 'assign' to see a valid list.\n");
	  return 1;
	}
	tell_object(player,
	  "That task is unavailable.  Type 'assign' to see a valid list.\n"); 
	return 1;
}

status help(object gob, object player)
{
	string title;
	
	title = "Assign";
  tell_object(player,"\n"+
	  HELPLINE+
	  HELPTITLE+
	  HELPLINE+"\n"+
    "    "+SGC+"Spell Point Cost:"+NORM+"      none\n"+
	  "    "+SGC+"Matter Point Cost:"+NORM+"     none\n"+
	  "\n"+
	  help_wrap("By using the 'assign' command, a neo is able to place any free tentacles into "+
	  "any tentacle related use.  To see more information, type 'assign' by itself.\n")+
    "\n"+
    "         Usage:  "+PGC+"assign tentacle "+HIW+"#"+PGC+" to "+SGC+"<"+HIW+"task"+SGC+">"+NORM+"\n"+
	  "                 "+PGC+"assign tentacles "+HIW+"#"+PGC+" through "+HIW+"#"+PGC+" to "+SGC+
	  "<"+HIW+"task"+SGC+">"+NORM+"\n\n"+
	  HELPLINE);
  return 1;
}
