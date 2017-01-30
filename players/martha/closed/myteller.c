#include "/obj/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()

/*query_auto_load() { return "players/martha/closed/marthatell2.c:";}*/

id(str){ return str == "teller" || str == "tattoo"; }

extra_look(){
	if(environment() == this_player()) {
		write("You have a small "+CYN+"Yin"+NORM+" "+HIC+"Yang"+NORM+" symbol tattooed on your shoulder.\n");}
	else {
		write(environment()->query_name()+" has a small "+CYN+"Yin"+NORM+" "+HIC+"Yang"+NORM+" symbol tattooed on her shoulder.\n");}
	}

drop(){
	return 1;}

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
				write(capitalize(who)+" is invisible right now.\n");
				return 1;} */
		else 
		idle = query_idle(player);
		m = idle/60;
		s = idle%60;
			if(idle > 119) {
				write(""+HIB+capitalize(who)+" has been idle for "+m+" minutes and "+s+" seconds."+NORM+"\n");}
	if(this_player()->query_invis()){
		tell_object(player,""+CYN+"Invis "+HIC+tpn+" tells you \""+HIB+what+HIC+"\""+NORM+"\n");
		write(""+CYN+"Invis"+HIC+" You say "+capitalize(who)+" \""+HIB+what+HIC+"\""+NORM+"\n");
		return 1;}
		tell_object(player,""+HIC+tpn+" tells you \""+HIB+what+HIC+"\""+NORM+"\n");
		write(""+HIC+" You say "+capitalize(who)+" \""+HIB+what+HIC+"\""+NORM+"\n");
		player->add_tellhistory(""+HIC+tpn+" said to you \""+HIB+what+HIC+"\""+NORM+"");
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
				write(""+HIB+capitalize(who)+" has been idle for "+m+" minutes and "+s+" seconds."+NORM+"\n");}

	if(this_player()->query_invis()){
		tell_object(player,""+HIC+"Invis"+HIC+tpn+" "+HIB+what+NORM+"\n");
		write(""+HIC+"Invis"+HIC+" You emote to "+capitalize(who)+HIB+": "+HIC+tpn+" "+what+NORM+"\n");
		return 1;}
		write(""+HIC+" You emote to "+capitalize(who)+HIB+": "+HIC+tpn+" "+what+NORM+"\n");
		tell_object(player,""+HIC+tpn+" "+what+NORM+"\n");
		return 1;}}

cmd_say(string str){
	
	string verb;
	
	if(!str){
		write("Say what?\n");
		return 1;}
	if(strlen(str) > 0){
		if(str[strlen(str)-1] == '?')
			verb = "asks";
		else if(str[strlen(str)-1] == '!')
			verb = "exclaims";
		else
			verb = "says";
	}
	else verb = "says";
		write(""+HIC+"You "+verb+" \""+HIB+str+HIC+"\""+NORM+"\n");
		say(HIC+this_player()->query_name()+" "+verb+" \""+HIB+str+HIC+"\""+NORM+"\n");
		return 1;}