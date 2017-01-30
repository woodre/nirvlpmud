#include <ansi.h>

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
	myname = "(wicket)";
  else
		myname = "wicket";
	player->Replyer("wicket");
  player->add_tellhistory(myname+" : "+arg);
/*  tc = (string)player->get_ansi_pref("tell"); */
  if (tc) 
    msg = tc + "<|> " + capitalize(myname) + " <|>: " + arg + NORM + "\n";
  else {
    tc = NORM;
    msg = HIK + "<|> " + NORM + capitalize(myname) + HIK + " <|>" + NORM + " : " + arg + "\n";
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
	return (int)"/bin/wiz/_place"->cmd_place(str+" /players/wicket/workroom");
}


int do_rt(string str)
{
	mixed ob;
	ob = "/players/shinshi/closed/rogue/objects/chatob.c";
	
	if(!ob){
		write("The guild line is currently down.\n");
		return 1;
	}
	if(!str){
		write("What would you like to say to your fellow Rogues?\n");
		return 1;
	}
	
	ob->tell(str);
	return 1;
}

int do_rte(string str)
{
	mixed ob;
	ob = "/players/shinshi/closed/rogue/objects/chatob.c";
	
	if(!ob){
		write("The guild line is currently down.\n");
		return 1;
	}
	if(!str){
		write("What would you like to emote to your fellow Rogues?\n");
		return 1;
	}
	
	ob->emote(str);
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


int get() { return 1; }
int drop() { return 1; }

void init() {
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
  add_action("do_workroom", "workroom");
  add_action("do_rt", "rt");
  add_action("do_rte", "rte");
  add_action("do_brothers", "brothers");
}

void short() {
	if(this_player() != environment(this_object())) {
		tell_object(find_player("wicket"), capitalize(this_player()->query_real_name()+ " just looked at your inventory.\n"));
	}
}

void long() { write("You can use 'tell <player> <what>' or 'retell <player>'\n"); }

status id(string arg) { return ( arg == "notfuckinghappening" || arg == "chipisajackass" || arg == "az2009chipblowsdick" || arg == "shinshi_rogue_seal"); }
