#include "/players/softly/closed/ansi.h"
#define OWNER "softly"
id(str) { return str == "rwep"; }

drop() { return 1;}

long() { write("Usage: rwep <string>\n"); }

init() {
  if(this_player()->query_real_name() != OWNER) destruct(this_object());
add_action("write_wepr","rwep");
}

write_wepr(str) {
  if(!str) return 0;
  write_file("/open/"+OWNER+"/"+OWNER+"_weapons",ctime(time())+" "+HIB+"-"+NORM+" "+str+"\n");
  write_file("/open/maledicta/"+OWNER+"_weapons",ctime(time())+" "+HIB+"-"+NORM+" "+str+"\n");
write(HIB+"Weapon resistance report completed."+NORM+"\n");
return 1;}
