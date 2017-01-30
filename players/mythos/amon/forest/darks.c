#include "/players/mythos/closed/ansi.h"

id(str) {return str == "darksound"; }

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

init() {
  call_out("scare",20);
}

scare() {
	int sc;
	sc=random(7);
	if(sc==0 || sc==6) {say("Something tells you to fear the 'dark'\n");
	   call_out("scare",20); return 1;}
	if(sc==1) {say("The darkness is frightening.\n");
		call_out("scare",20); return 1;}
    if(sc==2) {say("You feel despair...\n");
    	call_out("scare",20); return 1;}
    call_out("scare",25); return 1;}
