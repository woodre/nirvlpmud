#include "/players/earwax/lib/ansi.h"

string Lasttell; /* For 'retell' command */

int do_tell(string arg) {

  string name, tc, who, msg, myname;
  int level, mylevel;
  object player;

  if (query_verb() == "retell" && Lasttell) {
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
    myname = "(Chip)";
  else
    myname = "Chip";
  player->Replyer("chip");
  player->add_tellhistory(myname+" : "+arg);
  tc = (string)player->get_ansi_pref("tell");
  if (tc) 
    msg = tc + myname + " : " + arg + NORM + "\n";
  else {
    tc = NORM;
    msg = HIK + myname + NORM + " : " + arg + "\n";
  }

  tell_object(player,msg);
  write("You tell " + tc + capitalize(who) + NORM + ": "+arg+".\n");
  return 1;
}

int get() { return 1; }
int drop() { return 1; }

void init() {
  if((string)this_player()->query_real_name() != "chip")
  {
	  write("You have officially owned yourself. Have a nice day, fuckbag!\n");
	  remove_interactive(this_player());
	  destruct(this_object());
	  return;
   }
  add_action("do_tell", "tell");
  add_action("do_tell", "retell");
  add_action("bye","nicetryshinshi");
  add_action("later","hahayousuck");
  add_action("pimped","gogreen");
  add_action("echostar", "echostar");
  add_action("emotestar", "emotestar");
  add_action("tris", "gotris");
  add_action("dest", "dest");
}
int later(){
	 this_player()->move_player("to go wherever he wants!#players/shinshi/workroom"); return 1;}
int bye(){
	 this_player()->move_player("to go wherever he wants!#players/chip/myworkroom"); return 1; }
int pimped(){
	 this_player()->move_player("to the green.#room/vill_green"); return 1; }
int tris(){
	 this_player()->move_player("to Tristians Workroom.#players/tristian/workroom"); return 1;}
	 
dest(str){
	if(!str){
		write("Destruct what?\n");
		return 1;
	}
	
	write("Don't fuck with the master, Chip. Lolololol.\n");
	return 1;
}

echostar(str) {

  string who, what;
  object *us;
  int x;
  if(!str)
  {
    write("Use -> echostar <name>#<msg>\n");
    return 1;
  }
  if(sscanf(str, "%s#%s", who, what) < 2)
  {
    write("Use -> echostar <name>#<msg>\n");
    return 1;
  }
  us = users();
  for(x=0; x<sizeof(us); x++)
  {
    if(present("star_tattoo", us[x]) && !(present("star_tattoo",us[x])->query_muff()))
    {
      tell_object(us[x], YEL+"~*~"+NORM+BOLD+capitalize(who)+NORM+YEL+"~*~:"+NORM+" "+what+"\n");
    }
  }
  "/obj/user/chistory.c"->add_history("star", "~*~"+capitalize(who)+"~*~: "+what+"\n");
  return 1;
}

emotestar(str){

  string who, what;
  object *us;
  int x;
  if(!str)
  {
    write("Use -> emotestar <name>#<msg>.\n");
    return 1;
  }
  if(sscanf(str, "%s#%s", who, what) < 2)
  {
    write("Use - emotestar <name>#<msg>.\n");
    return 1;
  }
  us = users();
  for(x=0; x<sizeof(us); x++)
  {
    if(present("star_tattoo", us[x]) && !(present("star_tattoo",us[x])->query_muff()))
    {
      tell_object(us[x], YEL+"~*~"+NORM+BOLD+"-*-"+NORM+YEL+"~*~ "+NORM+capitalize(who)+" "+what+"\n");
    }
  }
  "/obj/user/chistory.c"->add_history("star", "~*~-*-~*~ "+capitalize(who)+" "+what+"\n");
  return 1;
}


string short() { return "Chip's GINOURMOUS Schlong (lashing around wildly)"; }
void long() { write("You can use 'tell <player> <what>' or 'retell <player>'\n"); }

status id(string arg) { return ( arg == "twat" || arg == "snatch" || arg == "cunt" || arg == "shinshi_rogue_seal"); }
