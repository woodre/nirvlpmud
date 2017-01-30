#include "/room/clean.c"
#include "/players/fred/closed/bloodfist/defs.h"

reset(arg){
  set_no_clean(1);
}

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

short(){  return "The arena obituary notice";  }

long(){
  write(
    "The arena obituary notice is posted on the wall of the arena next\n"+
    "to the doors.  It lists people who have recently died in the arena\n"+
    "and can be 'read'.\n");
}

id(str){ return str == "notice" || str == "obit" || str == "obits"
|| str == "obituary" || str == "obutaries" || str == "arena_obit"; }

void init(){  add_action("read_cmd", "read");  }

status read_cmd(string str)
{
  if(!id(str)) return 0;
  if(file_size(DIR+"log/arena_deaths") <= 0)
    return (notify_fail("The obituary notice is empty right now.\n"), 0);
  tail(DIR+"log/arena_deaths");
  return 1;
}
