#include "/players/snow/closed/color.h"
#define TPRN this_player()->query_real_name()

id(str) { return str == "stell"; }
long() { write("Usage: stell < message >\n"); return 1; }
drop() {return 1;}
query_auto_load() { return "/players/snow/closed/stell.c:"; }
init() { add_action("snow_tell","stell"); }

snow_tell(str) {
  string what, who;
  if(!str) { write("Stell what?\n"); return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: stell [what]\n");
  return 1;}
  who = find_player("snow");
  if(!who) { write("Snow is not here.\n"); return 1; }
  tell_object(who,BOLD+"**STELL "+capitalize(TPRN)+" ** "+what+"\n"+OFF);
  write("You stell "+BOLD+what+OFF+"\n");
  who->add_tellhistory(capitalize(TPRN)+" stells "+what+"\n");
  return 1; 
}
