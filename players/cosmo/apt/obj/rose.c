#include "/players/cosmo/closed/ansi.h"

id(str) { return str == "flower" || str == "rose"; }
short() { return "A lovely "+RED+"rose"+NORM; }
query_save_flag() { return 1; }
query_value() { return (10); }
long() {
  write("\n"+RED+
"    ...  :``..':\n"+
"     : ````.'   :''::'\n"+
"   ..:..  :     .'' :\n"+
"``.    `:    .'     :\n"+
"    :    :   :        :\n"+
"     :   :   :         :\n"+
"     :    :   :        :\n"+
"      :    :   :..''''``"+GRN+"::.\n"+RED+
"       : ...:..'     "+GRN+".''\n"+
"       .'   .'  .::::'\n"+
"      :..'''``:::::::\n"+
"      '         `::::\n"+
"                  `::.\n"+
"                   `::\n"+
"                    :::.\n"+
"         ..:`:..:'`. ::'`.\n"+
"       ..'      `:.: ::\n"+
"      .:        .:``:::\n"+
"      .:    ..''     :::\n"+
"       : .''         .::\n"+
"        :          .'`::\n"+
"                      ::\n"+
"                      ::\n"+NORM+
"\n"); }

reset(arg) {
  if(arg) return;
}

 get() { return 1; }

init() {
  add_action("smell","smell");
}

smell(arg) {
  if(!arg) {
    write("What would you like to smell?\n"); return 1; }
  if(arg=="rose" || arg=="flower") {
    write("You breathe in deep and the sweet aroma of the rose soothes\n"+
      "your mind and body, making you feel completely at ease.\n");
  return 1; }
  else { write("You cannot smell the "+arg+".\n"); }
return 1; }

