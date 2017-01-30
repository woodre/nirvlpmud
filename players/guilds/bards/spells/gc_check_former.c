#include "/players/guilds/bards/def.h"

status main(string str) {
  string line,temp;
  status found;
  int namelen;
  int lnum;
  if(!GOB->query_is_gc()) return 0;
  if(!str)
    FAIL("Who do you want to check for former membership in the Bards?\n");
  str=lower_case(str);
  namelen=strlen(str)-1;
  line=read_file("/players/guilds/bards/logs/leave",1,1);
  while(line) {
    if(lower_case(line[0..namelen])==str) {
      write(line);
      found=1;
    }
    line=read_file("/players/guilds/bards/logs/leave",++lnum,1);
  }
  if(!found)
    write("No records found.\n");
  return 1;
}
