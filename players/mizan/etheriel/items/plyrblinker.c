#include "/players/boltar/things/esc.h"
int charges;
reset() {
  if(!charges) charges=10;
	}
id(str) { return str == "blinker"; }
short() { return "Blinky's Blinker ["+charges+"]"; }
long() { write("This is a small, blinking rock with words written on it:\n"+
	"To blink a message, type 'blink <mess>'.\n"+
	"To blink an emote, type 'blinke <emote>'.\n"+
	"The blinker has ["+charges+"] charges left on it.\n");
	}
get() { return 1; }
query_save_flag() { return 1; }
query_weight() { return 1; }
query_value() { return 50; }
init() {
	add_action("blink","blink");
	add_action("blinkemote","blinke");
	}
blink(str) {
	if(!str) return 0;
	write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mYou blink: "+str+esc+"[0m"+"\n");
	say(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+(this_player()->query_name())+" blinks: "+str+esc+"[0m"+"\n");
  charges=charges - 1;
  if(charges == 0) {
      write("The blinker disappears.\n");
    destruct(this_object());
    this_player()->add_weight(-1);
    return 1;
    }
	return 1;
	}
blinkemote(str) {
	if(!str) return 0;
	write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+(this_player()->query_name())+" "+str+esc+"[0m"+"\n");
	say(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+(this_player()->query_name())+" "+str+esc+"[0m"+"\n");
	return 1;
    charges=charges-1;
    if(charges == 0) {
        write("The blinker disintegrates.\n");
      destruct(this_object());
      this_player()->add_weight(-1);
    return 1;
    }
	}
