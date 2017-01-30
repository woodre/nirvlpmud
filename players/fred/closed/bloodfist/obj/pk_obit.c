#include "/room/clean.c"
#include "/players/fred/closed/bloodfist/defs.h"

reset(arg){
  set_no_clean(1);
}

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

short(){  return "The pk obituary notice";  }

long(){
  write(
    "The pk obituary notice is posted near the treasure chest, and\n"+
    "displays the recent pk deaths, both Bloodfist kills and general\n"+
    "mudwide PK.  You can 'read kills' or 'read deaths'.\n");
}

id(str){ return str == "notice" || str == "obit" || str == "obits"
|| str == "obituary" || str == "obutaries" || str == "pk_obit"; }

void init(){  add_action("read_cmd", "read");  }

status read_cmd(string str)
{
  if(str == "kills")
  {
    if(file_size(DIR+"log/pk") <= 0)
      return (notify_fail("There are no BF kills right now.\n"), 0);
    return (tail(DIR+"log/pk"), 1);
  }
  else if(str == "deaths")
  {
    if(file_size("/log/PK") <= 0)
      return (notify_fail("There are no PK deaths right now.\n"), 0);
    return (tail("/log/PK"), 1);
  }
  return 0;
}
