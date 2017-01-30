#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
  if(arg) return;
  set_id("planner");
set_short("a planner");
set_long(
"This sets my plan.  Type plan.\n");
set_weight(0);
set_value(0);
set_dest_flag(1);
}
init() {
  ::init();
add_action("plan","plan");
}
plan() {
if(TPRN != "jenny") {
write("fuck you.  You're not jenny."); }

write_file("/players/jenny/PLAN",RED+
"	+++++++++++++++++++++++++++++++++++++++++++++++++\n"+
"	+						+\n"+
"	+	finished	Married with Children	+\n"+
"	+			Dukes of Hazzard	+\n"+
"	+			80's			+\n"+
"	+						+\n"+
"	+	working on	Haunted House		+\n"+
"	+			Detroit Red Wings	+\n"+
"	+						+\n"+
"	+	In future	LEXX			+\n"+
"	+						+\n"+
"	+++++++++++++++++++++++++++++++++++++++++++++++++"+NORM+"\n");
return 1;}
