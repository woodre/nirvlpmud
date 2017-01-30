#include "/players/traff/closed/ansi.h"
id(str) { return str == "sign"; }
short() { return WHT+"A NEW sign about "+BLU+"Delnoch"+WHT+"."+NORM; }
long() {
write("For information about recent changes to the Delnoch area\n"+
      "and things to come in the future, please type:\n\n"+
       "                  'read sign'\n"); }

init() {
    add_action("read","read");
       }

read(str) {
    if(!str) return 0;
    if(str == "sign") {
    say((this_player()->query_name())+" reads the sign.\n");
    cat("/players/traff/delnoch/CHANGES");
    return 1;
    }
return 0;
}
