/* workreport comment filer */

#include "/players/forbin/define.h"

main(str) {
  string comment;
  if(!str) {
    write("Usage: wcom <comment>\n");
      return 0;
  }
  comment = "                              "+str+"\n";
  write_file("/players/forbin/WORK_REPORT", comment);
  write_file("/log/WR/forbin_workreport", comment);
  write("comments appended.\n");
    return 1;
}
