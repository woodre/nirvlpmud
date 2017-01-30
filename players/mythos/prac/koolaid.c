#include "/players/mythos/closed/ansi.h"
#include "/obj/clean.c"

id(str) {return str == "kool-aid"; }

short() {write(BLU+"A giant Kool-Aid Pitcher\n"+NORM);}

long() {write(BLU+"A Pitcher of refreshing Kool-AiD\n"+NORM+
				"There is something etched into the glass pitcher- (read)\n"+
				"You may drink <kool-aid>\nYou may pour <pitcher>\n");}
		
get() {return 1; }

query_weight() {return 1;}
query_value() {return 0; }

init() {
  add_action("drink","drink");
  add_action("read","read");
  add_action("pour","pour");
}

drink(str) {
	if(!str) {write("what do you wish to drink?\n"); return 1;}
	if(str=="kool-aid") {write("You feeeeeel refreshed!\n"); 
say(capitalize(this_player()->query_name())+" guzzles down the kool-aid\n");
	return 1;}
	}

read(str) {
	if(!str) {write("What do you wish to read?\n"); return 1;}
	if(str == "kool-aid" || str=="pitcher" || str=="aid" ) {
			write(BLU+"Llew & Kirlar\n"+NORM); return 1;}
			}
			
pour(str) {
	if(!str) {write("what do you wish to pour?\n"); return 1;}
	if(str=="pitcher" || str =="kool-aid") {
		write("You pour some kool-aid.\n");
		say(capitalize(this_player()->query_name())+" pours some kool-aid\n");
	return 1;}
return 1;}
