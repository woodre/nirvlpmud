/*  Reward for bug finding to Symbio - Basically a glorified chat line */

#include "/players/maledicta/ansi.h"
#define TP this_player()
#define USER environment()
#define NAME "Incognito"
#define Allowed ({ "quicksilver", "mizan", "pestilence", })
query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }
int rank;

set_rank(int i){ 
save_object("players/maledicta/closed/symbio/members/"+USER->query_real_name());
rank = i; }
query_rank(){ return rank; }
add_rank(int i){ 
save_object("players/maledicta/closed/symbio/members/"+USER->query_real_name());
rank += i; }

id(str){
   return str == "insignia" || str == "clan_symbio";
}

query_auto_load(){ 
save_object("players/maledicta/closed/symbio/members/"+USER->query_real_name());
return "/players/maledicta/closed/symbio/clan.c:"; }


extra_look(){
if(this_player())
if(environment() == this_player()){
return USER->query_name()+" has a "+HIW+"Black Insignia"+NORM+" on "+USER->query_possessive()+" arm";
 }
}

long(){
   write(
      "This is a small insignia that is printed on your right\n"+
      "forearm.  It symbolizes a bond to the clan that is\n"+
      "permanent.\n"+
      "To find out the power it holds, type: "+HIY+"insignia"+NORM+"\n");
   return 1;
}

init(){
   if(!environment()) return;
   if(this_player() != environment()) return;
if(this_player())
if((member_array(this_player()->query_real_name(), Allowed) < 0)  && (this_player()->query_level() > 20) && (this_player()->query_level() < 100)){
write_file("/players/maledicta/closed/symbio/NONONO",
 this_player()->query_real_name()+" tried on "+ctime(time())+"\n");
 write("Action recorded.  Have a nice day.\n");
 destruct(this_object()); 
 return;
 }
restore_object("players/maledicta/closed/symbio/members/"+USER->query_real_name());
   add_action("clan_who", "clan");
   add_action("clan_line", "ct");
   add_action("clan_emote", "cte");
   add_action("leave_clan", "remove_insignia");
   add_action("tattoo_info", "insignia");
   add_action("new_quit", "quit");
   add_action("promote", "cpromote");
   add_action("demote", "cdemote");
   add_action("banish", "cbanish");
   add_action("initiate", "cinitiate");
   add_action("new_who", "pkwho");
if(USER->query_level() < 20)
   clan_emote("enters the game.\n");
if(USER->query_real_name() == "symbio" ||
   USER->query_level() > 19) rank = 11;
}

new_quit(){
save_object("players/maledicta/closed/symbio/members/"+USER->query_real_name());
return;
}  


promote(str){
object peep;
if(rank < 10) return;
if(!str){
  write("cpromote <who>\n");
  return 1;
  }
peep = present(str, environment(USER));
if(!peep){
  write("You do not see them here.\n");
  return 1;
  }
if(!living(peep)){
  write("That is not a person.\n");
  return 1;
  }
if(!present("clan_symbio", peep)){
  write("They are not a member of the Clan.\n");
  return 1;
  }
if(present("clan_symbio", peep)->query_rank() > 9){
  write("They are maxed at rank 10.\n");
  return 1;
  }
if(present("clan_symbio", peep)->query_rank() > 10){
  write("That is the leader!\n");
  return 1;
  }
present("clan_symbio", peep)->add_rank(1);
write("You promote "+str+" to rank "+
      present("clan_symbio", peep)->query_rank()+".\n");
tell_object(peep, "You have been promoted to rank "+ 
                  present("clan_symbio", peep)->query_rank()+".\n");
return 1;
}


demote(str){
object peep;
if(rank < 10) return;
if(!str){
  write("cdemote <who>\n");
  return 1;
  }
peep = present(str, environment(USER));
if(!peep){
  write("You do not see them here.\n");
  return 1;
  }
if(!living(peep)){
  write("That is not a person.\n");
  return 1;
  }
if(!present("clan_symbio", peep)){
  write("They are not a member of the Clan.\n");
  return 1;
  }
if(present("clan_symbio", peep)->query_rank() < 2){
  write("They are already at rank 1.\n");
  return 1;
  }
if(present("clan_symbio", peep)->query_rank() > 10){
  write("That is the leader!\n");
  return 1;
  }
present("clan_symbio", peep)->add_rank(-1);
write("You demote "+str+" to rank "+
      present("clan_symbio", peep)->query_rank()+".\n");
tell_object(peep, "You have been demoted to rank "+ 
                  present("clan_symbio", peep)->query_rank()+".\n");
return 1;
}

banish(str){
object peep;
if(rank < 11) return;
if(!str){
  write("cbanish <who>\n");
  return 1;
  }
peep = find_living(str);
if(!peep){
  write("They are not logged on.\n");
  return 1;
  }
if(!living(peep)){
  write("That is not a person.\n");
  return 1;
  }
if(!present("clan_symbio", peep)){
  write("They are not a member of the Clan.\n");
  return 1;
  }
if(present("clan_symbio", peep)->query_rank() > 10){
  write("That is the leader!\n");
  return 1;
  }
destruct(present("clan_symbio", peep));
rm("/players/maledicta/closed/symbio/members/"+peep->query_real_name()+".o");
write("You banish "+str+" from the clan.\n");
tell_object(peep, "You have been removed from the Clan.\n");
return 1;
}

initiate(str){
object peep;
if(rank < 10) return;
if(!str){
  write("cinitiate <who>\n");
  return 1;
  }
peep = find_living(str);
if(!peep){
  write("They are not logged on.\n");
  return 1;
  }
if(!living(peep)){
  write("That is not a person.\n");
  return 1;
  }
if(present("clan_symbio", peep)){
  write("They are already a member of the Clan.\n");
  return 1;
  }
move_object(clone_object("/players/maledicta/closed/symbio/clan.c"), peep);
write("You bring "+str+" into the clan.\n");
tell_object(peep, "You have been initiated into the Clan.\n");
return 1;
}

clan_emote(str) {
   object list;
   object clan;
   int i;
   string myname;
   if (!str) { write("cte <emote message>\n"); return 1; }
 
  list = users();
   /* $ color by verte */
   str = "/players/vertebraker/closed/std/color"->filter_msg(str);
   /* $ end color by verte */
str += "\n";
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      clan = present("clan_symbio",list[i]);
      if (clan) {
         tell_object(list[i], 
            HIR+"["+HIW+NAME+HIR+"] "+NORM+myname+" "+str+"\n");
       }
   }
   /* added by verte */
   "/obj/user/chistory"->add_history("symbio_clan",
      HIR+"["+HIW+NAME+HIR+"] "+NORM+this_player()->query_name()+" "+str);
   return 1;
}




clan_line(str) {
   object list;
   object clan;
   int i;
   string myname;
   string history;
   if (!str) { write("Use: ct <message>\n"); return 1; }
   list = users();
   if(str == "history" || str == "-h")
      {
      history = "/obj/user/chistory"->query_history("symbio_clan");
      write(history+"\n");
      return 1;
   }
   /* $ color by verte */
   str = "/players/vertebraker/closed/std/color"->filter_msg(str);
   /* $ end color by verte */
str += "\n";
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      clan = present("clan_symbio",list[i]);
      if (clan) {
         tell_object(list[i], 
            HIR+"["+HIW+NAME+HIR+"] "+NORM+myname+": "+str+"\n");
       }
   }
   /* added by verte */
   "/obj/user/chistory"->add_history("symbio_clan",
      HIR+"["+HIW+NAME+HIR+"] "+NORM+this_player()->query_name()+": "+str);
   return 1;
}






tattoo_info(){
   write(
  HIR+"                    - "+NAME+" -\n"+
  HIW+" As a Clan Member you may do any of the following:\n\n"+
      " ct"+HIR+"..............."+HIW+"The Clan Channel.          \n"+
      " cte"+HIR+".............."+HIW+"An emote on the Clan Channel.\n"+
      " clan"+HIR+"............."+HIW+"A full listing of all clan members.\n"+
      " remove_insignia"+HIR+"...."+HIW+"This is the command to leave the Clan.\n"+
      "\n"+NORM);
   if(rank > 5)
   write(
  HIW+" pkwho"+HIR+"............"+HIW+"A list of pkers on.\n"+NORM);
   if(rank > 10)
  write(
  HIW+" cbanish"+HIR+".........."+HIW+"Banish a clan member.\n"+NORM);
   if(rank > 9)
  write(
  HIW+" cpromote"+HIR+"........."+HIW+"Promote a clan member.\n"+
      " cdemote"+HIR+".........."+HIW+"Demote a clan member.\n"+
      " cinitiate"+HIR+"........"+HIW+"Bring in a new member.\n"+NORM);
   return 1;
}

leave_clan(){
   write("You decide to leave the Clan.\n");
   rm("/players/maledicta/closed/symbio/members/"+USER->query_real_name()+".o");
   clan_emote("has left the Clan.\n");
   write("Done.\n");
   destruct(this_object());
   return 1;
}


clan_who() {
   int i, z, ally;
   object *list;
   
   list = users();
   write(HIW);
   write(pad("",41,'-')+"\n");
   write("["+NORM+HIR+"  Name:\t Rank:\tGuild:         "+NORM+HIW+" ]\n");
   write(NORM+HIW);
   write("["+pad("",39,'-')+"]\n");
   write("["+pad("",39)+"]\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(list); i++) {
      if(present("clan_symbio", list[i])){
      if(!environment(list[i]) || list[i]->query_level() > 19) continue;
         write(HIW+"[  "+HIR+pad(list[i]->query_name(),14)+NORM);
         z++;
         if (list[i]->query_pl_k())
            write(present("clan_symbio", list[i])->query_rank() + "*\t");
         else
            write(present("clan_symbio", list[i])->query_rank() + "\t");
         
         if (!list[i]->query_guild_name())
            write(pad("None",16));
         else
            write(pad(capitalize(list[i]->query_guild_name()),16));
         write(NORM+HIW+"]\n");
       }
   }
   if(!z) write(HIW+"[  "+NORM+pad("No Members logged in.",37)+NORM+HIW+"]\n");
   write(HIW);
   write("["+pad("",39)+"]\n");
   write(pad("",41,'-')+"\n");
   write(NORM);
   return 1;
}


new_who(){
	int i;
	int b;
	int namer;
	int gspacer;
	int guilder;
	int spacer;
	object *plist;
    if(rank < 6) return 0;
	if(USER->query_ghost()) return 0;
	if(!USER->query_pl_k()){
		write("Why would you care about such things when your own pk isn't set?\n");
		return 1;
	}
	
	plist = users();
	write(
		"               "+BOLD+"[  "+HIR+"PK WHO"+NORM+BOLD+"  ]"+NORM+"\n\n"+
		""+HIR+"Name"+NORM+BOLD+":         "+HIR+"Guild"+NORM+HIW+":"+
	"        Room:"+NORM+"\n");
	
	for(i=0; i<sizeof(plist); i++){
		if(plist[i]->query_invis() && plist[i]->query_level() >= USER->query_level()) continue;
		if(plist[i]->query_level() < 20){
			if(plist[i]->query_pl_k() || plist[i]->query_fight_area()){
				namer = strlen(plist[i]->query_name());
				spacer = 14 - namer;
				write(
				HIB+plist[i]->query_name()+""+NORM);
				for(b=0;b<spacer;b++) {
					write(" ");
				}
				if(plist[i]->query_guild_name()){
					guilder = strlen(plist[i]->query_guild_name());
					gspacer = 14 - guilder;
					write(
					HIB+plist[i]->query_guild_name()+NORM+"");
				}
				else{
					gspacer = 10;
					write(HIB+"none"+NORM);
				}
				for(b=0;b<gspacer;b++) {
					write(" ");
				}
				if(environment(plist[i])){
					write(environment(plist[i])->short()+"\n");
				}
				else{
					write("Unknown Location\n");
				}
			}
		}
	}
	write("\n\n");
	return 1;
}
