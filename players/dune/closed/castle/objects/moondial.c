inherit "obj/clean";
#include "definitions.h"


init() { add_action("watch_dial","dial"); }

id(str) { return str == "dial" || str == "moondial"; }

get() { return 1; }
drop() { return 0; }
query_weight() { return 4; }
/* Changed from value 1000 to 0.
       Fred 7-7-03    */
query_value() { return 0; } 

reset() {}

short() { return "A moon dial"; }

long()
{
  write(
"     This is small heavy device that measures the phases\n"+
"of the Lothlorien moon. It also displays the current\n"+
"Lothlorien month. It is very mechanical and confusing,\n"+
"but easy to use. Simply watch the 'dial'.\n");
}

watch_dial()
{
  string month, phase;
  month = call_other(CASTLEROOM+"/moonshrine.c", "query_month");
  phase = call_other(CASTLEROOM+"/moonshrine.c", "query_phase");
  write("~~~~~Lothlorien Moon Dial~~~~~\n");
  write("It is "+CAP(month)+" and the moon is "+CAP(phase)+".\n");
  return 1;
}
