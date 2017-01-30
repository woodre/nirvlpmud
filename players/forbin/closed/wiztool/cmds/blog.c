/* workreport filer */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"
#include "/players/forbin/closed/wiztool/cmds/date_time.h"

main(str) {
  string action, comment;
  if(!str) {
    write("Usage: blog <what>\n");
      return 0;
  }
  write_file("/players/forbin/closed/bfeq", "["+date_time()+"] "+str+"\n");
  write("BF Eq Log Appended.\n");
    return 1;
}
