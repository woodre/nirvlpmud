#include <ansi.h>
#include "/players/shinshi/closed/rogue/defs.h"

string Lasttell; /* For 'retell' command */

int do_tell(string arg) {

  string name, tc, who, msg, myname;
  int level, mylevel;
  object player;

  if (query_verb() == "rereredotell" && Lasttell) {
    who = arg;
    arg = Lasttell;
    if (!who) {
      notify_fail("Usage: retell <player>\n");
      return 0;
    }
    if (!Lasttell) {
      notify_fail("You haven't sent a tell yet.\n");
      return 0;
    }
  }
  else
  if ((!arg) || sscanf(arg,"%s %s",who,arg) != 2) {
    write("Usage: tell <player> <message>\n");
    return 1;
  }

  Lasttell = arg;
  who = lower_case(who);
  player = find_living(who);

  if (!player) {
    write("Nobody logged on with that name.\n");
    return 1;
  }

  level = (int)player->query_level();
  if (!interactive(player)) {
    write("That recipient is not interactive.\n");
    return 1;
  }
  if (level >= 21 && player->query_tellblock()) {
    write("That person is blocking tells.\n");
    return 1;
  }
  if (this_player()->query_invis() && level < 20)
	myname = "(Shinshi)";
  else
		myname = "Shinshi";
	player->Replyer("shinshi");
  player->add_tellhistory(myname+" : "+arg);
/*  tc = (string)player->get_ansi_pref("tell"); */
  if (tc) 
    msg = tc + "<< " + myname + " >>: " + arg + NORM + "\n";
  else {
    tc = NORM;
    msg = HIK + "<< " + HIR + myname + HIK + " >>" + NORM + " : " + arg + "\n";
  }

  tell_object(player,msg);
  write("You tell " + tc + capitalize(who) + NORM + ": "+arg+"\n");
  return 1;
}
int do_retell(string arg) {
	string replyer;
	
	if(!(replyer = (string)this_player()->Replyer()))
	 return(notify_fail("You aren't replying to anyone.\n"), 0 );
	if(!arg) return (notify_fail("Reply what to " + capitalize(replyer) + "?\n"), 0 );
	 return command("dotell " + replyer + " " + arg, this_player());
}

int do_leave(string str)
{
	if(!str)
	  str = (string)this_player()->query_real_name();
	return (int)"/bin/wiz/_place"->cmd_place(str+" /players/shinshi/workroom");
}

int do_guard(string str)
{
	object mob;
	
	mob = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
	
	if(!str)
	move_object(mob, environment(environment(this_object())));
	return 1;
}
int do_fake(string str)
{
	object ob;
	
	if(!str){
		write("Who would you like to give the fake death message to?\n");
		return 1;
	}
	ob = find_living(str);
	
	if(!ob)
	{
		write("That player is not online.\n");
		return 1;
	}
	
	if(ob)
	{
		tell_object(ob, "You feel very weak as your badly damaged body falls to the ground to die.\n"+
		"Your strength is now 19\n"+
		"\n"+
		"        Unkeeping all inventory items...\n"+
		"Done.\n"+
		"\n"+
		"\n"+
        "                          You die.\n"+
        "                 You have a strange feeling.\n"+
        "         You can see your own dead body from above.\n"+
        "              setting hit points to 1/3 max....\n"+
        "\n"+
        "\n"+
        "A white dot appears and expands into a bright white tunnel.\n"+
		"The tunnel shimmers slightly as it grows in strength.\n"+
		"You feel a desire to enter the tunnel.\n"+
		"Shinshi was JUST KIDDING!\n");
		write("You fake kill "+ob->query_name()+".\n");
		return 1;
	}
}

int do_lol(string str)
{
	object ob;
	
	if(!str){
		write("Who would you like to Lol at?\n");
		return 1;
	}
	ob = find_living(str);
	
	if(!ob)
	{
		write("That player is not online.\n");
		return 1;
	}
	
	if(ob)
	{
		tell_object(ob,
"\n"+
"   ___        _______    ___\n"+
"  \/\\  \\      \/\\  ___ \\  \/\\  \\\n"+
"  \\ \\  \\     \\ \\ \\  \\ \\ \\ \\  \\\n"+
"   \\ \\  \\____ \\ \\ \\__\\ \\ \\ \\  \\____\n"+
"    \\ \\______\\ \\ \\______\\ \\ \\______\\\n"+
"     \\\/______\/  \\\/_____ \/  \\\/______\/\n"+
"\n"+
"Shinshi just lol'd at you!\n");
		write("You LOL at "+ob->query_name()+".\n");
		return 1;
	}
}

int do_rt(string str)
{
	string pre;
	
	if(!CHAND){
		write("The guild line is currently down.\n");
		return 1;
	}
	
	if(!str){
		write("What would you like to say to your fellow Rogues?\n");
		return 1;
	}
	
	pre = "";
  	pre += RED+"(XX "+WHT+"Rogue"+RED+" XX)"+WHT+" (GUILD WIZ) "+OFF+OFF;
  	
  	if(str[0] == ':')
  		pre += NORM;
  	else
  		pre += this_player()->query_name()+":   "+NORM;
  	
  	CHAND->channel_message(CHAN_NAME, str, pre);
  	return 1;
}

int do_derv(string str)
{
  string pre;
  object PO;
  
	if(!CHAND) {
		write("The guild line is currently down.\n");
		return 1;
	}
	
  pre = RED+BOLD+"**DERVISH** ";
  
  if(str[0] == ':')
    pre += NORM;
  else
    pre += this_player()->query_name() + " (Guild Wiz):   "+ NORM;
    
	CHAND->channel_message("Dervish", str, pre );
	return 1;
}

int do_brothers(string str)
{
	int level, xlevel, x;
	string title, place;
	object ob, *people;
        people = users();
	
	write("\n");
	write(BOLD+"********************************************************"+
	    "***********************\n"+OFF);
	write(BOLD+BLACK+pad("Rogues",     15)+
	    pad("Level",       11)+
	    pad("Location",    30)+"\n"+OFF+OFF);
	write(BOLD+"********************************************************"+
	    "***********************\n\n"+OFF);
	    
	for(x=0;x<sizeof(people);x+=1)
        {
		if(!people[x]->query_invis() && present("shinshi_rogue_seal", people[x]))
                {
			ob = people[x];
			write(pad((string)ob->query_name(), 15));
			level = (int)ob->query_level();
			xlevel = (int)ob->query_extra_level();
			write(pad(level+"+"+xlevel, 15));
			place = (string)environment(ob)->short();
			write(place);
			write("\n");
		}
	}
        return 1;
}

int check_wicket()
{
	object owner;
	int num;
	
	num = random(10);
	owner = environment(this_object());
	
	if(num != 5)
	{
		tell_object(owner, "Tick\n");
		tell_object(owner, "Tock\n");
	}
	
	if(num == 5)
	{
		this_object()->doublexp();
		tell_object(find_player("shinshi"), "Double experience applied.\n");
	}
	
	call_out("check_wicket", 180);
	return 1;
}

int quit()
{
	CHAND->remove_channel(CHAN_NAME, this_player());
	CHAND->remove_channel("Dervish", this_player());
	this_player()->do_quit();
	return 1;
}


int doublexp()
{
	object *us;
	object ob;
	int s;
	
	s = sizeof(us = users());
	
	while(s--)
	{
		if(us[s] && (int)us[s]->query_level() < 20)
		{
			if(!present("double_xp_object", us[s]))
			{
				move_object(clone_object("/obj/secure/double_obj.c"), us[s]);
				/*tell_object(us[s], HIR+"\n\nThe Gods look down upon you and deem you unworthy of\n");
				tell_object(us[s], HIR+"           DOUBLE EXPERIENCE and give you "+YEL+"HALF EXPERIENCE"+HIR+" instead!\n\n"+NORM);*/
				tell_object(us[s], HIR+"\n\nYou have been granted "+HIY+"DOUBLE EXPERIENCE"+HIR+".\n\n"+NORM);
			}
		}
	}
	write("Ok.\n");
	return 1;
}

int get() { return 1; }
int drop() { return 1; }

void init() {
	
	CHAND->add_channel(CHAN_NAME, environment());
	CHAND->add_channel("Dervish", environment());
	
  
  
  add_action("do_tell", "dotell");
  add_action("do_retell", "redotell");
  add_action("do_leave", "home2");
  add_action("do_leave", "home3");
  add_action("do_leave", "home4");
  add_action("do_leave", "home5");
  add_action("do_leave", "home6");
  add_action("do_leave", "home7");
  add_action("do_leave", "home8");
  add_action("do_leave", "home9");
  add_action("do_leave", "home69");
  add_action("do_leave", "ilold");
  add_action("do_workroom", "workroom");
  add_action("do_fake", "fake");
  add_action("do_guard", "guard");
  add_action("do_lol", "lol");
  add_action("do_rt", "rt");
  add_action("do_brothers", "brothers");
  add_action("check_wicket", "noidle");
  add_action("do_derv", "derv");
  add_action("quit", "quit");
  add_action("doublexp", "doublexp");
}

void short() {
	if(this_player() != environment(this_object())) {
		tell_object(find_player("shinshi"), capitalize(this_player()->query_real_name()+ " just looked at your inventory.\n"));
	}
}

void long() { write("You can use 'tell <player> <what>' or 'retell <player>'\n"); }

status id(string arg) { return ( arg == "notfuckinghappening" || arg == "chipisajackass" || arg == "az2009chipblowsdick" || arg == "shinshi_rogue_seal" || arg == "dervish_tattoo"); }
