#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	int level, tlev, x, ST;
	int crhp, mxhp, crsp, mxsp;
	int s, f, t, i;
	object *target;
	object player;
	string msg, hpstat, spstat;
	string in, gname;
	
	target = users();
	
	if(!str)
	{
		write("NEED ANALYSIS for ALL Players:\n\n");
		for(x=0;x<sizeof(target);x++) {
			if(target[x]->query_level())
				if(environment(target[x]))
					if((string)target[x]->query_real_name() != "guest")
						if(target[x]->query_level() < 20 && !target[x]->query_invis()) {
							
							crhp = (int)target[x]->query_hp();
							mxhp = (int)target[x]->query_mhp();
							crsp = (int)target[x]->query_sp();
							mxsp = (int)target[x]->query_msp();
							
							msg = (string)target[x]->query_name();
							while(strlen(msg) < 16) msg += " ";
							msg += "lvl: ";
							if(target[x]->query_extra_level()+target[x]->query_level() < 10) msg += " "+target[x]->query_level();
							else msg += target[x]->query_extra_level()+target[x]->query_level();
							
                  			if(mxhp) msg = "   "+msg+"  hp: "+(PO->needany(crhp * 10/mxhp));
                  			else msg = "   "+msg+"  hp: "+PO->needany(0);
                            
                            if((string)environment(target[x])->realm() == "NM" ||
                            	environment(target[x])->query_NM())
                            		msg += "  sp:  NM  ";
                            
                  			else if(mxsp) msg += "  sp: "+PO->needany(crsp * 10/mxsp);
                        	else msg += "  sp: "+PO->needany(0);
                            
                        	msg += "   ";
                        	
                  			if(environment(target[x])) {
                    			msg += "Loc: ";
                    			msg += pad((string)environment(target[x])->short(),13);
                    			msg += NORM+"  ";
                  			}
                  			
                  			if(!interactive(target[x])) msg += "DC   ";
                            if(interactive(target[x]))
                            {
	                            if(query_idle(target[x]) > 120) msg += "IDLE   ";
                    			if(target[x]->query_attack()) msg += "COMBAT   ";
                    			if(target[x]->query_ghost())  msg += "GHOST";
                  			}
                            
                  			msg += NORM+"\n";
                  			write(msg);
           				}
     	}
	write("\n");
  	return 1;
  	}
  	
  	if(str)
  	{
	  	if(str != "room")
	  	{
		  	tlev = User->query_level() + User->query_extra_level();
		  	ST = 0;
			player = find_player(str);
			
			if(str == "guest")
			{
				write("You may not need guest.\n");
				return 1;
			}
			
			if(!player)
			{
				write("That person is not online.\n");
				return 1;
			}
			
			if(player->query_invis())
			{
				write("That person is not visible.\n");
				return 1;
			}
			
			if(player->query_level() > 19)
			{
				write("You cannot use need on a wizard!\n");
				return 1;
			}
			
			crhp = (int)player->query_hp();
			mxhp = (int)player->query_mhp();
			crsp = (int)player->query_sp();
			mxsp = (int)player->query_msp();
			
			if(mxhp) hpstat = ""+(crhp * 10/mxhp);
            else hpstat = "0";
			
            if((string)environment(player)->realm() == "NM" || (string)environment(player)->query_NM()) spstat = " NM ";
      		else if(mxsp) spstat = ""+(crsp * 10/mxsp);
            else spstat = "0";
            
          	i = (int)player->query_intoxination()*10/((int)player->query_max_intox());
          	f = (int)player->query_stuffed()*10/((int)player->query_max_stuff());
          	s = (int)player->query_soaked()*10/((int)player->query_max_soak());
          	gname = (string)player->query_guild_name();
          	
          	if(!gname) gname = "none";
          	
          	write("NEED ANALYSIS for "+capitalize(str)+"  <lvl: "+(player->query_extra_level() + player->query_level()) + ">  [ "+gname+ " ]\n\n"+
            "     HP: "+hpstat+"     SP: "+spstat+"         ");
            
            if(tlev > 10) write("\n     I: "+i+"       F: "+f+"      S: "+s);
            	write("\n");
            if(environment(player)) write("     Loc: "+environment(player)->short());
            if((string)environment(player)->realm() == "NT") write("  [non-teleport]");
            	write("\n     STATUS: ");
            if(!interactive(player))
            {
	            write("DC");
	            ST = 1;
	        }
	        
            if(interactive(player))
            {
            	if(query_idle(player) > 120)
            	{
	            	write("IDLE");
	            	ST = 1;
	        	}
	            
				if(player->query_attack())
				{
					write("  COMBAT   ATT: "+(player->query_attack())->short());
					ST = 1;
				}
			
            	if(player->query_ghost())
            	{
		            write("  GHOST");
	            	ST = 1;
	        	}
            }
            
            if(tlev > 7)
            {
	            if(present("disease",player) || present("virus",player) || present("VD",player) ||
                   present("illness",player) || present("cold",player))
                {
	                write("  SICK");
	                ST = 1;
	            }
	            
				if(present("poison",player) || present("venom",player))
                {
	               	write("  POISON"); ST = 1;
	            }
            }
            
            if(!ST) write("  NORMAL");
			write("\n");
			
            if(tlev > 8)
            {
	            write("     ");
	            write("Defense:  "+PO->needDef(player->query_ac())+"\n");
	        }
	        
            if(tlev > 15)
            {
	            ST = 0;
	            write("     STATS UNDER 20:");
	            
				if(player->query_attrib("str") < 20)
				{
					write(" STR");
					ST = 1;
				}
                
				if(player->query_attrib("mag") < 20)
				{
					write(" MAG");
					ST = 1;
				}
				
                if(player->query_attrib("sta") < 20) { write(" STA"); ST = 1; }
                if(player->query_attrib("pie") < 20) { write(" PIE"); ST = 1; }
                if(player->query_attrib("int") < 20) { write(" INT"); ST = 1; }
                if(player->query_attrib("luc") < 20) { write(" LUC"); ST = 1; }
                if(player->query_attrib("ste") < 20) { write(" STE"); ST = 1; }
                if(player->query_attrib("wil") < 20) { write(" WIL"); ST = 1; }
                if(!ST) write("  NONE");
                write("\n");
                                                  }
             write("\n");
     	}
     	
     	else
     	{
	     	tlev = User->query_level() + User->query_extra_level();
	     	
	     	target = all_inventory(environment(User));
	     	
	     	write("NEED ANALYSIS for ALL Players in ROOM:\n\n");
	     	for(x=0;x<sizeof(target);x++)
	     	{
		     	if(target[x]->query_level())
		     		if(environment(target[x]))
		     			if(target[x]->is_player())
		     				if(find_player(target[x]->query_real_name()))
		     					if((string)target[x]->query_real_name() != "guest")
		     						if(target[x]->query_level() < 20 && !target[x]->query_invis())
		     						{
			     						gname = (string)target[x]->query_guild_name();
			     						if(!gname) gname = "none";
			     						if(gname == 0) gname = "none";
			     						
			     						msg = (string)target[x]->query_name();
			     						msg += " <"+gname+">";
			     						while(strlen(msg) < 16) msg += " ";
			     						msg += " lvl: ";
			     						
			     						if(target[x]->query_level() + target[x]->query_extra_level() < 10) msg += " "+target[x]->query_level();
			     						else msg += target[x]->query_level() + target[x]->query_extra_level();
			     						
			     						crhp = (int)target[x]->query_hp();
										mxhp = (int)target[x]->query_mhp();
										crsp = (int)target[x]->query_sp();
										mxsp = (int)target[x]->query_msp();
			     						
			     						if(mxhp) msg = "   "+msg+"   hp: "+PO->needany(crhp * 10/mxhp);
			     						else msg = "  "+msg+"  hp: "+PO->needany(0);
			     						
			     						if((string)environment(target[x])->realm() == "NM" || environment(target[x])->query_NM()) msg += "  sp:  NM  ";
			     						else if(mxsp) msg += "  sp: "+PO->needany(crsp * 10/mxsp);
			     						else msg += "  sp: "+PO->needany(0);
			     						
			     						msg += "  ";
			     						
			     						i = (int)target[x]->query_intoxination()*10/((int)target[x]->query_max_intox());
							          	f = (int)target[x]->query_stuffed()*10/((int)target[x]->query_max_stuff());
							          	s = (int)target[x]->query_soaked()*10/((int)target[x]->query_max_soak());
							          	
							          	if(tlev > 10)
							          	{
								          	msg += "I: "+i+" F: "+f+" S: "+s;
								          	msg += "   ";
							          	}
							          	
							          	if(!interactive(target[x])) msg += "DC   ";
							          	
							          	if(interactive(target[x]))
							          	{
								          	if(query_idle(target[x]) > 120) msg += "IDLE   ";
								          	if(target[x]->query_attack()) msg += "COMBAT   ";
								          	if(target[x]->query_ghost()) msg += "GHOST  ";
							          	}
							          	
							          	msg += NORM+"\n";
							          	write(msg);
						          	}
			   }
					          	
			   write("\n");
			}
			
			return 1;
	}
		 	
 	return 1;
}