#include "/players/boltar/things/esc.h"
 
id(str) { return str == "blinker"; }
short() { return "Blinky's Blinker (Release Three)"; }
long() { write("To blink a message, type 'blink <mess>'.\n"+
	"To blink an emote, type 'blinke <emote>'.\n"+
	"To echo to the room in blink, type 'blinkecho <str>'.\n"+
	"To make the whole mud see an echo, type 'blinkshout <str>'.\n"); }
get() { return 1; }
init() {
	add_action("blink","blink");
	add_action("blinkemote","blinke");
	add_action("blinkecho","blinkecho");
	add_action("blinkshout","blinkshout");
	}
blink(str) {
	if(!str) return 0;
	write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mYou blink: "+str+esc+"[0m"+"\n");
	say(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+(this_player()->query_name())+" blinks: "+str+esc+"[0m"+"\n");
	return 1;
	}
blinkemote(str) {
	if(!str) return 0;
	write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+(this_player()->query_name())+" "+str+esc+"[0m"+"\n");
	say(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+(this_player()->query_name())+" "+str+esc+"[0m"+"\n");
	return 1;
	}
blinkecho(str) {
	if(!str) return 0;
	write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+str+esc+"[0m"+"\n");
	say(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+str+esc+"[0m"+"\n");
	return 1;
	}
blinkshout(str) {
	if(!str) return 0;
	write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+str+esc+"[0m"+"\n");
	shout(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+str+esc+"[0m"+"\n");
	return 1;
	}
