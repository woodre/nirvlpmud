#define OWNER "tristian"

#if 0 /* Rumplemintz - just use the standard ansi file */
#include "/players/tristian/lib/ansi.h"
#else
#include <ansi.h>
#endif

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
           "Emote to Star - emotestar <name>#<msg>.\n"+
           "Echo to Star - echostar <name>#<msg>.\n"+
           "Scan an Inventory - invscan <arg>\n"+
           "Destory inventory obj - destr <arg>\n"+
           "Sforce\n");
  set_weight(0);
  set_value(0);
}

/* Non Droppable */
drop(str) {
  if(str=="all"||str=="wand"||str=="Tristian's magical wand") {
    destruct(this_object());
    return 1;
  }
  return 1;
} 

int set_gname(string arg) {
#if 1
  write("Do not use this to set guild names, can screw up player files.\n" +
        "Rumplemintz.\n");
  return 1;
#else
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
#endif
}

init() {
  if (this_player()->query_real_name()=="tristian") {
   add_action("title_me", "title_me");
   add_action("title_me2", "title_me2");
   add_action("filer","file");
   add_action("someone_tell","stell");
   add_action("harry_tell","htell");
   add_action("set_gname","set_gname");
   add_action("watch","watch");
   add_action("whonew", "who3");
   add_action("player_tell", "ptell");
#if 0 /* No reason to impersonate on star channel... - Rumplemintz */
   add_action("echostar", "echostar");
   add_action("emotestar", "emotestar");
#endif
   add_action("inv_scan","invscan"); 
#if 0 /* Rumplemintz - don't use add_verb */
   add_action("low_remove"); add_verb("low_remove");
   add_action("destr"); add_verb("destr");
#else
    add_action("low_remove", "low_remove");
    add_action("destr", "destr");
#endif
   add_action("sforce","sforce");
  }
  else {
    write("You cant use Tristian's shank.\n");
    return 1;
  }
}

/* Cheap Snoop Command - Echos typed commands only */
watch (who) {
#if 1 /* Rumplemintz */
  write("No snooping of players until wiz level 60 - Rumplemintz.\n");
  return 1;
#else
  object ob, snooper;
  ob = find_player(who);
  if (!ob) {
    write("Player not found: "+who+"\n");
    return 1;
  }
  snooper = present("123456", ob);
  if (snooper) { /* remove it */
    write("Stopping snoop on "+who+"...\n");
    destruct(snooper);
    return 1;
  }
  move_object(clone_object("/players/tristian/closed/cheaposnoop.c"),ob);
  return 1;
#endif
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

/* Command tells people in syntax - Someone tells you */
someone_tell(str) {
  object plyr;
  string who;
  string what;
  if(!str) {write("Tell what?\n"); return 1;}
  if(sscanf(str,"%s %s",who,what)==2){
    plyr = find_living(who);
    if(!plyr) {
      write(capitalize(who) + " is not online now.\n");
      return 1;
    }
    tell_object(plyr,"Someone tells you: " + what + "\n");
    write("You Stell "+capitalize(who)+": "+what+"\n");
    write("Rumplemintz tells you: Don't abuse this....\n");
    return 1;
  }
  write("Tell what to whom?\n");
  return 1;
}
   
/* Command tells people in syntax - Harry tells you */
harry_tell(str) {
  object plyr;
  string who;
  string what;
  if(!str) {write("Tell what?\n"); return 1;}
  if(sscanf(str,"%s %s",who,what)==2){
    plyr = find_living(who);
    if(!plyr) {
      write(capitalize(who) + " is not online now.\n");
      return 1;
    }
    tell_object(plyr,"Harry tells you: " + what + "\n");
    write("You Htell "+capitalize(who)+": "+what+"\n");
    write("Rumplemintz tells you: Don't abuse this....\n");
    return 1;
  }
  write("Tell what to whom?\n");
  return 1;
}

/* Who 3 New Who Command*/  
whonew(){
  object* ppl;
  int i;
  ppl = users();
  write(
    "Name:         HP:         Money:      Experience:    Level:    Fighting:\n");
	
  for(i = 0; i < sizeof(ppl); i++){
    if(ppl[i]->query_level() > 99 && ppl[i]->query_invis()) continue;
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
    tell_object(this_player(),"Not fighting.\n");
  }	
 }
return 1;
}

/* Tell Player - Syntax is Pname Tells you: */
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
        write("Rumplemintz tells you: Don't abuse this....\n");
return 1;
}
  write("Tell what to whom?\n");
return 1;
}
   
/* Echo to Channel Star */
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

/* Echo Emote to Channel Star */
emotestar(str){
  string who, what;
  object *us;
  int x;
  
  if(!str) {
    write("Use -> emotestar <name>#<msg>.\n");
return 1;
}
  if(sscanf(str, "%s#%s", who, what) < 2) {
    write("Use - emotestar <name>#<msg>.\n");
return 1;
}
  
  us = users();
  for(x=0; x<sizeof(us); x++) {
    if(present("star_tattoo", us[x]) && !(present("star_tattoo",us[x])->query_muff())) {
      tell_object(us[x], YEL+"~*~"+NORM+BOLD+"-*-"+NORM+YEL+"~*~ "+NORM+capitalize(who)+" "+what+"\n");
    }
  }
  "/obj/user/chistory.c"->add_history("star", "~*~-*-~*~ "+capitalize(who)+" "+what+"\n");
  return 1;
}

/* Scan an Inventory */
inv_scan (str)
{
    object item_o,person_o;
    string thing;
  if (!str) {
    write("Scan Inv what/who?\n");
return 1;
}

  person_o=present(str);
  if (!person_o)
     person_o=find_living(str);
  if (!person_o)
     person_o=find_object(str);
  if (str==".")
     person_o=environment(this_player());
  if (!person_o) {
    write("No such living thing or place.\n");
return 1;
}
  item_o=first_inventory(person_o);
  while(item_o) {
      object next;
      sscanf(item_o,"%s",thing);
      write(thing+"\n");
      next=next_inventory(item_o);
      item_o=next;
    }
  return 1;
}

low_remove(num)
{
    int n;
    object ob;

    if (sscanf(num, "%d", n) != 1)
        return 0;
    ob = first_inventory(environment(this_player()));
    while(n>0 && ob) {
        n += 1;
        ob = next_inventory(ob);
    }
    if (ob == this_player()) {
        write("That is your self !\n");
        return 1;
    }
    write("Destroying: " +call_other(ob, "short") + ".\n");
    destruct(ob);
    return 1;
}

destr(obj) {
  object ob;
  ob = present(obj, this_player());
  if (!ob) {
    write("No such object.\n");
return 1;
}
  write("Ok.\n");
  say(call_other(this_player(), "query_name") + " got rid of " +
    call_other(ob, "short") + ".\n");
    destruct(ob);
return 1;
}

sforce(str) {
#if 1
  write("Cannot use force until wiz level 50 - Rumplemintz\n");
  return 1;
#else
   object who;
    int count;
    string str1,str2;
      count=0;
       sscanf(str,"%s %s",str1,str2);
       who=find_player(str1);
           command(str2,who);
       write("Done.\n");
     return 1;
#endif
    }

force(str) {
#if 1
  write("Cannot use force until wiz level 50 - Rumplemintz\n");
  return 1;
#else
   string me,com;
    object ob;
    sscanf(str,"%s %s",me,com);
     ob=find_player(me);
    call_other(ob,"force_us",com);
    return 1;
#endif
  }
/*Autoload*/

query_auto_load() 
{ 
return basename(this_object())+":0";
}
