#include <security.h>
#include <ansi.h>
#include "/players/boltar/things/esc.h"

#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define master "/obj/wiz_tool_master.c"
#define to this_object()
#define ep environment(to)
#define eep environment(ep)
#define logg "WIZTOOL",ctime(time())+tpn

id(str) { return str == "wiz_tool" || str == "tool" || str == "wiztool" || str == "claw"; }

/*short() { return HIK+capitalize(ep->query_real_name())+"'s Dragon Claw"+NORM; } */

extra_look(){
	if(environment() == this_player()) {
		write("Your "+HIK+"obsidian"+NORM+" scales are heavily scarred from past battles.\n");}
	else {
		write(environment()->query_name()+"'s "+HIK+"obsidian"+NORM+" scales are heavily scarred from past battles.\n");}
	}

long() { 
   write("This is a general all-purpose wiztool.\n"+
         "Commands:\n"+
         "wlog <action>#<reason>      writes a log of your actions\n"+
         "rules                       lists wizard rules & guidelines\n"+
         "I <name>                    inventory of name\n"+
         "IR <name>                   inv of room that name is in\n"+
		 "dest <name>                 dests an object of name \n"+
		 "clone <path>                clones a copy of object of path\n"+
		 "trans <name>                transports name to you\n"+
		 "scale <name>                clones teller to name\n"+
         "hand <name> <path>          hands name object of path\n"+
         "place <name> <path>         moves name to path\n"+
/*         "church <name>               moves name to church\n"+
         "                            note:no name meansyourself\n"+*/
         "trans <name>                moves name to you\n"+
         "peace                       forces all combat to stop\n"+
         "money                       gives you 80k coins\n"+
         "heal <name>                 heal someone in the room\n"+
         "                            note: no name is yourself\n"+
         "set_level <name> <#>        sets the level of name\n"+
         "set_extra_level <name> <#>  sets the extra level of name\n"+
         "set_home <name> <path>      sets the home of name to path\n"+
         "add_xp <name> <#>           adds # xp to name\n"+
         "set_stat <name> <what> <#>  sets the stat what of name to #\n"+
		 "set_title <name> <what>     sets the title of name to what \n"+
		 "set_race <name> <what>      sets the race of name to what \n"+
		 "set_guild <name> <what>     sets the guild name of who to what \n"+
         "idest <name> <object>       dests object from name's inv\n");
}

drop() { destruct(to); return 1; }
get() { if(tl > 20) return 1;  else destruct(to); return 1;}

init() {
  if(tl < 21) { destruct(to); return 1; }
  add_action("wizard_log", "wlog");
  add_action("wizard_rules", "rules");
  add_action("inv","I");
  add_action("invr","IR");
  add_action("hand","hand");
  add_action("place","place");
  add_action("idest","idest");
  add_action("cmd_home","dhome");
/*  add_action("church","church");*/
  add_action("trans","trans");
  add_action("peace","peace");
  add_action("money","money");
  add_action("heal","heal");
  add_action("add_xp","add_xp");
  add_action("set_ex","set_extra_level");
  add_action("set_stat","set_stat");
  add_action("set_level","set_level");
  add_action("set_home","set_home");
  add_action("set_title","set_title");
  add_action("set_race","set_race");
  add_action("set_guild","set_guild");
  add_action("dscale","scale");
  add_action("dclone","dclone");
  add_action("dtrans","dtrans");
  add_action("cmd_destruct","ddest");
 }

wizard_log(str) { master->wizard_log(str); return 1; }
wizard_rules() { master->wizard_rules(); return 1; }
inv(str) { master->inv(str); return 1; }
invr(str) { master->invr(str); return 1;}
place(str) { master->place(str); return 1; }
church(str) { master->church(str); return 1; }
idest(str) { master->idest(str); return 1; }
heal(str) { master->heal(str); return 1; }
set_ex(str) { master->set_ex(str); return 1; }
money() { master->money(); return 1; }
peace() { master->peace(); return 1; }
set_stat(str) { master->set_stat(str); return 1; }
set_level(str) { master->set_level(str); return 1; }
add_xp(str) { master->add_xp(str); return 1; }
set_home(str) { master->set_home(str); return 1; }

/*Commands*/
int cmd_home(){
	say("Katya slowly shifts into a large "+HIK+"obsidian"+NORM+" dragon and flies home.\n",this_player());
	tell_object(this_player(),"You have arrived at your workroom.\n");
	move_object(this_player(),"/players/katya/workroom.c");
	this_player()->look();
	say("Katya flies in.\n",tp);
	return 1;
}

int dclone(string str){
  string err;
  string pwd;
  object ob;
   
  if (!str)
  {
    write("Clone what object?\n");
    return 1;
  }
  if(str=="player.c" || str=="/obj/player.c")
  {
    write("That is not allowed.\n");
    this_player()->illegal_patch("cloned player.c");
    return 1;
  }
  str=(string)this_player()->valid_read(str);
  if(!str || (err=catch(ob=clone_object(str))))
  {
    if(err)
      write("Clone failure..\n"+err);
    else
      write("Clone what?\n");
    return 1;
  }
  pwd=(string)this_player()->query_pwd();
  if((pwd && pwd[0..4]=="/open") ||
   str[0..4]=="/open")
    log_file("OPEN",
     ctime()+" "+(string)this_player()->query_real_name()+
     " cloned "+str+"\n");

 say("A small "+MAG+"magenta"+NORM+" dragon fetches something for Katya.\n",this_player());
    if((status)ob->get())
  {
    this_player()->add_weight((int)ob->query_weight());
    move_object(ob, this_player());
  }
  else
    move_object(ob, environment(this_player()));
  write("A small "+MAG+"magenta "+NORM+"dragon fetches "+ob->short()+".\n");
  return 1;
} 

dtrans(str) {
object where;
  if(!str) return 0;
  if(!find_player(str)) { write("Target is not game.\n");
     return 1; }
where = environment(find_player(str));
  say("A giant "+HIK+"onyx"+NORM+" dragon drops "+capitalize(str)+" from its claws.\n",this_player());
  move_object(find_player(str),environment(tp));
  tell_room(where,"A giant "+HIK+"onyx"+NORM+" dragon swoops down, captures "+
		capitalize(str)+" in its claws and carries them away.\n");
  write("You have transed "+capitalize(str)+" to you.\n");
  tell_object(find_player(str),"A giant "+HIK+"onyx"+NORM+" dragon swoops down, captures "+
		"you in its claws and carries you away.\n");
return 1; }

set_guild(str){
	string who,what;
	if(!str) return 0;
	if(sscanf(str,"%s %s",who,what));
	if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
	find_player(who)->set_guild_name(what);
	tell_object(find_player(who),"Katya has changed your guild name to "+what+".\n");
	write("You have set "+capitalize(who)+"'s guild name to "+what+".\n");
	log_file(logg + "set "+who+"'s guild name to "+what+".\n");
	return 1; }

set_race(str) {
string who,what;
  if(!str) return 0;
  if(sscanf(str,"%s %s",who,what));
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_race(what);
  tell_object(find_player(who),"Katya has changed your race to "+what+".\n");
  write("You have set "+capitalize(who)+"'s race to "+what+".\n");
  log_file(logg + "set "+who+"'s race to "+what+".\n");
return 1; }

status
set_title(string str){
	int s;
    string *words;
	string who,what;

    if(!str)
    {
      notify_fail("Set who's title to what?\n");
      return 0;
    }

  if(sscanf(str,"%s %s",who,what));
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
      words = explode(what, "$");
      s = sizeof(words);

      while(s --)
        if(find_player(who)->replace_ansi(words[s]))
          words[s] = (string)find_player(who)->replace_ansi(words[s]);

      str = (implode(words, "")) + esc + "[0m";
    

	tell_object(find_player(who),"Katya has changed your title to "+str+".\n");
	write("You have set "+capitalize(who)+"'s title to "+str+"\n");
    find_player(who)->set_title(str);

    return 1;
}

hand(str) { 
string what,name;
object ob,targ;
ob = 0;
  if(!str) return 0;
  if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target not in play.\n"); return 1; }

  if(catch(ob = clone_object(what)))
    return (write("Object did not clone.\n"), 1);
  move_object(ob,targ);
  tell_object(targ,"A tiny "+MAG+"magenta"+NORM+" scaled dragon has "+ 
                   "dropped something into your inventory.\n"+
                   "     **   From: "+capitalize(tpn)+
                   "    **\n");
  write("You have cloned "+what+" to "+capitalize(name)+".\n");
return 1;
}

dscale(name) { 
object ob,targ;
ob = 0;
  if(!name) return 0;
  targ = find_player(name);
  if(!targ) { write("Target not in play.\n"); return 1; }

  if(catch(ob = clone_object("/players/katya/kteller.c")))
    return (write("Object did not clone.\n"), 1);
  move_object(ob,targ);
  tell_object(targ,"A tiny "+MAG+"magenta"+NORM+" scaled dragon has "+ 
                   "dropped something into your inventory.\n"+
                   "     **   From: "+capitalize(tpn)+
                   "    **\n");
  write("You have given a scale to "+capitalize(name)+".\n");
return 1;
}

void destruct_inventory()
{
  object ob, oc;
  ob = first_inventory(this_player());
  while(ob)
  {
    oc=next_inventory(ob);
    if(!ob->id("ND"))
    {
      destruct(ob);
      write("destruct: " + (string)ob->short() + ".\n");
    }
    ob=oc;
  }
}

int cmd_destruct(string str)
{
  object ob;
  if (!str) {
    write("Destruct what?\n");
    return 1;
  }
  str = lower_case(str);
  if (str == "all")
  {
    destruct_inventory();
    return 1;
  }
  if(!(ob=present(str, this_player())) &&
     !(ob=present(str, environment(this_player()))))
  {
    write("You don't see " + str + " here.\n");
    return 1;
  }
  say("A small "+HIK+"black "+NORM+"dragon flies in and destroys "+ob->short()+" for Katya.\n",this_player());
  write("A small "+HIK+"black "+NORM+"dragon disintegrates "+ob->short()+".\n");
  destruct(ob);
  return 1;
}
