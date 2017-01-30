#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/cmds/date_time.h"

status main(string str, object gob, object player)
{
  string action, comment;
  
  if((string)player->query_real_name() != "forbin" &&
    (string)player->query_real_name() != "fred" &&
    (string)player->query_real_name() != "toy" &&
    (string)player->query_real_name() != "fone")
    return 0; 
  
  if(!str) 
  {
    write("Usage: logit <what>\n");
      return 1;
  }
  	
  write_file("/players/forbin/closed/neo/logs/nwlog", 
    log_wrap(str));  
  write("Log entered.\n");
    return 1;
}
