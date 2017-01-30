#include "/players/feldegast/defines.h"

int do_cmd(string str) {
  if(!str) {
    write("Usage: Wlog <string>\n");
    return 1;
  }
  write_file("/log/WR/feldegast_workreport",ctime(time())+" "+str+"\n");
  write("Wrote: "+ctime(time())+" "+str+"\n");
  return 1;
}
