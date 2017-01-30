/*
H_Tell & S_tell taken from original code by Gemini
*/
#define OWNER "tristian"
#include "/players/tristian/lib/ansi.h"
#define ATT ppl[i]->query_attack()
#define ATTN ATT->query_name()
#define vis this_player()->query_invis()



inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("shank");
    set_alias("shank");
    set_short("A prison shank");
    set_long("Set Guild Name - set_gname <guild name>\n"+
             "Set Title 1 - title_me\n"+
             "Set Title 2 - title_me2\n"+
             "Log to file - file <quote>\n"+
             "Someone Tell - stell <arg>\n"+
             "Harry Tell - htell <arg>\n"+
             "Who 3 - Extended who\n"+
             "emotestar <name>#<msg>.\n"+
             "echostar <name>#<msg>.\n");
    set_weight(0);
    set_value(0);
}

/* Non Droppable */

drop() { return 1; } 

int set_gname(string arg) {

  string who;
  mixed what;
  object ob;

  if (!arg) {
    notify_fail("Syntax: set_gname <who> <new guild name>\nOr:      set_gname <your new guild name>\n");
    return 0;
  }

  if (sscanf(arg,"%s %s", who, what) == 2) {
    ob = find_player(who);
    if (!ob) {
      notify_fail(who+" not found.\n");
      return 0;
    }
  }
  else  {
    ob = this_player();
    what = arg;
  }

  if (what == "none" || what == "None")
    what = 0;

  ob->set_guild_name(what);
  write("Player '"+capitalize((string)ob->query_real_name())+"'s guild name set to: "+what+".\n");
  return 1;
}


init(){
   ::init();

   add_action("title_me", "title_me");
   add_action("title_me2", "title_me2");
   add_action("filer","file");
   add_action("someone_tell","stell");
   add_action("harry_tell","htell");
   add_action("set_gname","set_gname");
   add_action("watch","watch");
   add_action("whonew", "who3");
   add_action("player_tell", "ptell");
   add_action("echostar", "echostar");
   add_action("emotestar", "emotestar"); 
}

watch (who) {
  object ob, snooper;

  ob = find_player(who);

  if (!ob)
  {
    write("Player not found: "+who+"\n");
    return 1;
  }

  snooper = present("123456", ob);

  if (snooper) /* remove it */
  {
    write("Stopping snoop on "+who+"...\n");
    destruct(snooper);
    return 1;
  }


  move_object(
      clone_object("/players/tristian/closed/cheaposnoop.c"),
      ob);
  return 1;
}

/* TITLE FUNCTIONS */

title_me()  {
    this_player()->set_pretitle(HIR+"Can't come up with a witty title"+NORM+HIY );
    this_player()->set_title(HIB+ "is brain dead!"+NORM);
    this_player()->set_al_title(HIG+"FLATLINE"+NORM);
    return 1;
}

title_me2()  {
    this_player()->set_pretitle("( "+HIG );
    this_player()->set_title(BLK);
    this_player()->set_al_title(NORM);
    return 1;
}

filer(str) {
     if(!str) return 0;
     write_file("/players/"+OWNER+"/WORK_REPORT",ctime(time())+"  "+str+"\n");
     write_file("/log/WR/"+OWNER+"_workreport",ctime(time())+"  "+str+"\n");
     write("report done.\n");
     return 1;
}

someone_tell(str) {
  object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Someone tells you: " + what + "\n");
	 write("You Stell "+capitalize(who)+": "+what+"\n");
	return 1;
	}
	write("Tell what to whom?\n");
	return 1;
   }

harry_tell(str) {
  object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Harry tells you: " + what + "\n");
	 write("You Htell "+capitalize(who)+": "+what+"\n");

	return 1;
	}

	write("Tell what to whom?\n");
	return 1;
   }

/* Who 3 */  
whonew(){
	object* ppl;
	int i;
	ppl = users();
	write(
	"Name:         HP:         Money:      Experience:    Level:    Fighting:\n");
	
	for(i = 0; i < sizeof(ppl); i++){
		if(ppl[i]->query_level() > 500000 && ppl[i]->query_invis()) continue;
		tell_object(this_player(),
		pad(ppl[i]->query_real_name()+"           ", 14));
		tell_object(this_player(),
		pad(ppl[i]->query_hp()+"/"+ppl[i]->query_mhp()+"    ", 12));
		tell_object(this_player(),
		pad(ppl[i]->query_money()+"           ", 12));
		tell_object(this_player(), pad(ppl[i]->query_exp()+"         ", 15));
		if(ppl[i]->query_extra_level()){
			tell_object(this_player(),
			pad(ppl[i]->query_level()+"+"+ppl[i]->query_extra_level()+"      ", 10));
		}
		else{
			tell_object(this_player(),
			pad(ppl[i]->query_level()+"        ", 10));
		}
		if(ATT){
			tell_object(this_player(),
			ATTN+" ["+ATT->query_hp()+"/"+ATT->query_mhp()+"]\n");
		}
		else{
			tell_object(this_player(),
			"Not fighting.\n");
		}
		
	}
	return 1;
}

player_tell(str) {
  object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr, capitalize(who)+ " tells you: " + what + "\n");
	 write("You Ptell "+capitalize(who)+": "+what+"\n");

	return 1;
	}

	write("Tell what to whom?\n");
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

/*Autoload*/

query_auto_load() 
{ 
return basename(this_object())+":0";
}