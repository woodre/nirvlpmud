#include "/obj/security.h"
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  if(!str) { tail("/players/vital/logs/com.log"); return 1; }
  else
  write_file("/players/vital/logs/com.log",RED+"==>"+NORM+" "+str+"\n");
  write(HIB+"Comment completed."+NORM+"\n");
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: com [comment]";
  return help;
}
