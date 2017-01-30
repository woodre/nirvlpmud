#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"

id(str) { return str == "camera"; }
short() { return "A Polaroid camera"; }
query_save_flag() { return 1; }
query_value() { return (10); }
long() {
  write(short()+".\n"+
        "A great invention for getting instant photos.\n"+
        "Perhaps you can <snap> a <picture>.\n"); }

reset(arg) {
  if(arg) return;
}

init() {
  add_action("snap","snap"); }

snap(str) {
if(str == "picture") {
/* Code to capture the long description of this_player's room */
  write("You click the button and capture your surroundings.\n");
  return 1; }
else { write("Usage: <snap picture>.\n");
return 1; }
}

get() { return 1; }

query_weight() { return 1; }

