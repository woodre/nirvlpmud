#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  string *logs;
  logs = get_dir("/log/WR/*_workreport");
  if(!str) { tail("/players/vital/logs/work.log"); return 1; }
  else if(member_array(str+"_workreport",logs) != -1)
  {
    tail("/log/WR/"+str+"_workreport");
    return 1;
  }
  else
  {
    write_file("/players/vital/logs/work.log",ctime(time())+" "+HIB+"-->"+NORM+" "+str+"\n");
    write_file("/log/WR/vital_workreport",ctime(time())+" "+HIB+"-->"+NORM+" "+str+"\n");
    write("Log entered\n");
  }
  return 1;
}

get_help()
{
  string help;
  help = "Post to the work_report";
  return help;
}
