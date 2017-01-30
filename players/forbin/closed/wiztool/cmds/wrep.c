/* workreport filer */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"
#include "/players/forbin/closed/wiztool/cmds/date_time.h"

main(str) {
  string action, comment;
  if(!str) {
    write("Usage: wrep <action#comment>\n");
      return 0;
  }
  if(sscanf(str, "%s#%s", action, comment) < 2) action = str;
  str = action+(comment ? "\n                   "+comment : "")+"\n";
  write_file("/players/forbin/WORK_REPORT", HIW+"["+WTC+date_time()+HIW+"] "+NORM+str);
  write_file("/players/forbin/closed/WORK_REPORT_NO_COLOR", date_time()+"  "+str);  
  write_file("/log/WR/forbin_workreport", HIW+"["+WTC+date_time()+HIW+"] "+NORM+str);
  write("report done.\n");
    return 1;
}
