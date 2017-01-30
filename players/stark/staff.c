#include "/players/stark/defs.h"
#include "/players/stark/cmd/_iwho.h"
inherit "/obj/treasure.c";


short() { return "Stark's Staff"; }
id(str) { return str == "staff"; }
long() { write("tt to talk\iwho for idlewho\n"); }


init() {
	add_action("tell", "tell");
add_action("say","say");
	add_action("cmd_idlers","iwho");
add_action("title_change","title_change");
}
title_change(str){
TP->set_guild_name(str);
return 1;
}

say(msg){
if(!msg){write("Hmm?\n");return 1;}
tell_room(ENV(ETO), ""+BOLD+RED+"~"+BLK+"Stark thinks to the room"+RED+"~ . o O( "+NORM+msg+" "+BOLD+RED+")"+NORM+"\n");
return 1;
}
tell(str) {
object player;
string who;
string msg;

if(!str) {
	write("Mrow?\n");
	return 1;
}

if(sscanf(str,"%s %s",who,msg) != 2) {
	write("Tell <who> <what>.\n");
	return 1;
}

player = find_living(who);

if(!player) {
	write("There is no "+capitalize(who)+" online.\n");
	return 1;
}

player->add_tellhistory("Stark tells you: "+msg);
tell_object(player, ""+BOLD+RED+"~"+BLK+"Stark thinks from afar"+RED+"~ . o O( "+NORM+msg+" "+BOLD+RED+")"+NORM+"\n");
write("You whisper into "+capitalize(who)+": "+WHT+msg+NORM+"\n");
return 1;
}

