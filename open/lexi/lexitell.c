#include "/obj/ansi.h"
#include "/bin/gender.c"
#define tp this_player()
#define tpp posess(tp)
#define tpn this_player()->query_name()
/*query_auto_load() { return "players/lexi/lexi_tell.c:";}*/

id(str){ return str == "teller" || str == "heart" || str == "dark_sight_object"; }

extra_look(){
	if(environment() == this_player()) {
		write("You have a small "+RED+"heart"+NORM+" shaped tattoo on your left shoulder blade.\n");}
	else {
		write(environment()->query_name()+" has a small "+RED+"heart"+NORM+" shaped tattoo on "+tpp+" left shoulder blade.\n");}
	}

drop(){
	return 1;}

long() { 
   write("\n"+
		 "Your tellers functions in case you forget!\n"+
         "Commands:\n"+
         "tell <who> <what>       Send a tell to <who> saying <what>\n"+	
		 "say <what>              Say <what>, Duh!\n"+
		 "em <who> <what>         Emote <what> to <who>\n");}

init(){
	add_action("cmd_tell","tell");
	add_action("cmd_say","say");
	add_action("cmd_say"); add_xverb("'");
	add_action("cmd_emote","em");
	}

cmd_tell(str){
	object player;
	object who;
	object what;
	int idle,m,s;

if(!str){
	write("Tell who what?\n");
	return 1;}
else 
  if(sscanf(str,"%s %s",who,what)==2){
		player = find_player(who);
	if(!player) {
		write(capitalize(who)+" is not logged in.\n");
		return 1;}
  else 
		if(!player->query_interactive()){
			write(capitalize(who)+" is disconnected.\n");
			return 1;}
/*		else
			if(player->query_invis()){
				write(capitalize(who)+" is invisble right now.\n");
				return 1;} */
		else 
		idle = query_idle(player);
		m = idle/60;
		s = idle%60;
			if(idle > 119) {
				write(""+MAG+capitalize(who)+" has been idle for "+m+" minutes and "+s+" seconds."+NORM+"\n");}
	if(this_player()->query_invis()){
		tell_object(player,""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+"Invis"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+tpn+" says to you \""+HIC+what+NORM+MAG+"\""+NORM+"\n");
		write(""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+"Invis"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+"You say to "+capitalize(who)+" \""+HIC+what+NORM+MAG+"\""+NORM+"\n");
		return 1;}
		tell_object(player,""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+tpn+" says to you \""+HIC+what+NORM+MAG+"\""+NORM+"\n");
		write(""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+"You say to "+capitalize(who)+" \""+HIC+what+NORM+MAG+"\""+NORM+"\n");
		player->add_tellhistory(""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+tpn+" said to you \""+HIC+what+NORM+MAG+"\""+NORM+"\n");
		return 1; }}

cmd_emote(str){
	object player;
	object who;
	object what;
	int idle,m,s;

if(!str){
	write("Tell who what?\n");
	return 1;}
else 
  if(sscanf(str,"%s %s",who,what)==2){
		player = find_player(who);
	if(!player) {
		write(capitalize(who)+" is not logged in.\n");
		return 1;}
  else 
		if(!player->query_interactive()){
			write(capitalize(who)+" is disconnected.\n");
			return 1;}
/*		else
			if(player->query_invis()){
				write(capitalize(who)+" is invisble right now.\n");
				return 1;} */
		else 
		idle = query_idle(player);
		m = idle/60;
		s = idle%60;
			if(idle > 119) {
				write(""+MAG+capitalize(who)+" has been idle for "+m+" minutes and "+s+" seconds."+NORM+"\n");}

	if(this_player()->query_invis()){
		tell_object(player,""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+"Invis"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+tpn+" "+HIC+what+NORM+"\n");
		write(""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+"Invis"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+"You emote to "+capitalize(who)+HIW+": "+HIC+tpn+" "+what+NORM+"\n");
		return 1;}
		write(""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+"You emote to "+capitalize(who)+HIW+": "+HIC+tpn+" "+what+NORM+"\n");
		tell_object(player,""+HIW+"~"+CYN+"<"+NORM+CYN+"*"+HIC+">"+HIW+"~ "+NORM+MAG+tpn+" "+HIC+what+NORM+"\n");
		return 1;}}

cmd_say(string str){
	
	string verb;
	
	if(!str){
		write("Say what?\n");
		return 1;}
	if(strlen(str) > 1){
		if(str[strlen(str)-1] == '?')
			verb = "ask";
		else if(str[strlen(str)-1] == '!')
			verb = "exclaim";
		else
			verb = "say";
	}
	else verb = "say";
		write(""+MAG+"You "+verb+" \""+HIC+str+NORM+MAG+"\""+NORM+"\n");
		say(MAG+this_player()->query_name()+" "+verb+"s \""+HIC+str+NORM+MAG+"\""+NORM+"\n");
		return 1;}