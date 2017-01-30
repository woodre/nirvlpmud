#include "../defs.h"

#define stats security_check(Owner, previous_object(), points, info)
#define PATCHLOG "/players/earwax/closed/TRACKER/logs/patchlog"

status
security_check(object ob, object pob, int points, string info)
{
  string name, loginfo;

  if (pob == find_object(PKD))
    return 1;

  if (name = (string)pob->query_real_name())
    loginfo = capitalize(name) + " attempted to set stats for: ";
  else
    loginfo = "Unknown code/caller attempted to set stats for: ";

  loginfo += (string)Owner->query_real_name()+"\n";
  loginfo += "Points: "+points+"\n"+info+"\n";
    
    write_file(PATCHLOG, "\
=========================================================================="+
ctime()+"\n"+loginfo+"\
=========================================================================="+
"\n\n");
  return 0;
}
