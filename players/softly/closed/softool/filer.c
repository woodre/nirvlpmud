#include "/players/softly/closed/ansi.h"
#define OWNER "softly"
id(str) { return str == "filer"; }

drop() { return 1;}

long() { write("Usage: file <string>\n"); }

init() {
  if(this_player()->query_real_name() != OWNER) destruct(this_object());
  add_action("filer","file");
}

filer(str) {
  if(!str) return 0;
  write_file("/players/"+OWNER+"/WR/WORK_REPORT",ctime()[4..15]+" "+HIR+"-->"+NORM+" "+str+"\n");
  write_file("/log/WR/"+OWNER+"_workreport",ctime()[4..15]+" "+HIR+"-->"+NORM+" "+str+"\n");
  write(HIR+"Report completed."+NORM+"\n");
  return 1;}
