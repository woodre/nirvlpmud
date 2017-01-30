
#include "/room/clean.c"
string *dest_cmd, *dest_dir;

#include "alias.h"

add_exit(string what, string where) {
   if(!what || !where)
     return 1;
   if(!dest_cmd) { dest_cmd = ({ }); dest_dir = ({ }); }
   dest_cmd += ({ what });
   dest_dir += ({ where });
   make_exits();
}

make_exits() {
   int i;
   i = 0;
   while(i < sizeof(dest_cmd)) {
     add_action("move", dest_cmd[i]);
     i += 1;
   }
   add_action("search","search");
   add_action("listen","listen");
   set_up_alias();
}

search(str) {
   if(!str)
     return;
   this_player()->look("at "+str);
   return 1;
}

#include "listen.h"


