#include "std.h"
id(str) { return str == "peeker"; }
query_auto_load() {
	return "players/mizan/things/sc.c:"; }
get() { return 1; }
short() { return "A Super-Brief 'SC' Peeker"; }
long() {
write("This is a Super Quick Score Peeker. It shows you your basic stats\n"+
"with one keystroke. With the touch of the letter 'q' you get a display\n"+
"of your vital statistics. Write to Mizan for complaints, suggestions, etc.\n");
write("\n"+
"-NEW COMMAND- (Courtesy of Moloch) \n"+
" xp - Shows you the amount of experience you have currently.\n"+
"      (A showing of your current level and how much exp to level coming soon)\n");
	}
init() {
	add_action("q","q");

	add_action("xp","xp");
	write("  -=Quick SC Peeker Loaded!=-\n");
	}
xp() {
	write("Quick SC ->> Current EXP: "+
	(this_player()->query_exp())+".\n");
	return 1;
	}
drop() { return 0; }
q() {
	write("Quick SC->> ["+(this_player()->query_hp())+
	"]hp ["+(this_player()->query_sp())+"]sp ");
/*
Players are not to see their opponent's HP.  - Grimm
	if((this_player()->query_attack())!=0) {
	   int ahp;
	   string aname;
	   ahp=this_player()->query_attack()->query_hp();
	   aname=this_player()->query_attack()->query_name();
	   write("["+ahp+"]"+aname+" hp ");
	}
*/
	if((this_player()->query_intoxination())>0) {
	write("["+(this_player()->query_intoxination())+"]intox ");
	}
	if((this_player()->query_stuffed())>0) {
	write("["+(this_player()->query_stuffed())+"]stuffed ");
	}
	if((this_player()->query_soaked())>0) {
	write("["+(this_player()->query_soaked())+"]soaked ");
	}
	write("["+(this_player()->query_money())+"]gold\n");
	return 1;
	}
