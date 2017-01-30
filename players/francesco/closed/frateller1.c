/*  Approved to use - 10/9/00 Eurale  */

#include "/players/eurale/closed/ansi.h"

id(str)  { return str == "fratell"; }
short() {return "Francesco's teller (mounted)";}

drop()   { return 1; }
get()    { return 1;}
int noidlequit;

init(){
    
    add_action("fratell","fratell");
    add_action("fratelle","fratelle"); 
    add_action("fratelli","fratelli");
    add_action("guild_change","setguild");
    add_action("tellother","frahist");
}
guild_change() {
this_player()->set_guild_name("undead");
return 1;}


tellother(string who) {
object ob;
  if(!who) {write("History of who?\n"); return 1; }
  ob=find_player(who);
  if(!ob) {write(who+" is not logged on.\n"); return 1;}
  ob->write_tellhistory(); 
  return 1;
  }


fratell(str) {

  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Tell what?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
	     tell_object(player, HIW+"Francesco (invis) politely speaks to you: "+NORM+what+" \n");
             write(HIW+"You invisibly fratell "+capitalize(who)+NORM+": "+what+"\n");
	     player->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
/*             add_tellhistory(this_player()->query_real_name()+" tells you: "+what);*/
             return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(player, HIW+"Francesco politely speaks to you: "+NORM+what+" \n");
	     write(HIW+"You fratell "+capitalize(who)+NORM+": "+what+"\n");
             player->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
/*	     add_tellhistory(capitalize(this_player())->query_real_name()+" tells you: "+what);*/
    return 1; 
            }
    return 1;
            }
    return 1;
            }

fratelle(str) {
  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
	     tell_object(player, "Francesco (invis) "+what+" \n");
             write("You invisibly fraemote to " +capitalize(who)+": "+what+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(player, "Francesco "+what+" \n");
	     write("You fraemote to " +capitalize(who)+": "+what+"\n");
    return 1; 
            }
    return 1;
            }
    return 1;
            }

fratelli(str) {
  object player;
  string who;
  string what;
	            
     if(!str) 
            {
             write("Emote to whom?\n"); 
     return 1;
            }
     if(sscanf(str,"%s %s",who,what)==2)
            {
             player = find_player(who);
     if(!player) 
            {
             write(capitalize(who) + " is not online now.\n"); 
    return 1; 
            }
    if(this_player()->query_invis() > 1) 
            {
	     tell_object(player, what+" \n");
             write("You echo to " +capitalize(who)+": "+what+"\n");
             
    return 1; 
            }
    if(this_player()->query_invis() < 1) 
            {
             tell_object(player,what+" \n");
	     write("You echo to " +capitalize(who)+": "+what+"\n");
    return 1; 
            }
    return 1;
            }
    return 1;
            }


set_noidlequit() {noidlequit=1; }
