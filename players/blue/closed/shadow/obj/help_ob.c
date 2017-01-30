#include "/players/blue/closed/shadow/help.h"
#include "/players/blue/closed/lib/esc.h"
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"


id(str) { return str == "pamphlet"; }
short() {
   string short;
   short = "A "+BOLD+" SHADOW "+NOSTYLE+" info pamphlet";
   return short;
}
long() { 
   write("This is a small pamphlet with an incredible amount of information"+
" about\nthe Shadow guild.  Type 'info help' for a list of help topics, and"+
"\n'info <topic>' to read about any of the topics.\n");
}
get() { return 1; }
drop() { return 0; }
value() { return 0; }
reset(arg) {
   if(arg) return;
}

init() {
   add_action("help_me","info");
}

help_me(str) {
   if(!str) {
      write("Usage: 'info help' or 'info <topic>'.\n");
      return 1;
   }
   help_subject(str);
   return 1;
}
