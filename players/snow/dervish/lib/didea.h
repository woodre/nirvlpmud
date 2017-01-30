#include <ansi.h>

dervish_idea(str)
{
  object x;
  string msg;
  
  if(!str) return 0;
  msg = RED+"***"+NORM+" "+this_player()->query_name()+": "+NORM+str+RED+" ***"+NORM;
  write_file("/players/snow/dervish/log/didea.txt", msg+"\n");
  write("Your idea has been submitted to Shinshi.\n");
  x = find_player("shinshi");
  if(!x) { return; }
  
  if(x)
  {
	  tell_object(x, "A player has sent you a new guild idea.\n");
	  return 1;
  }
  return 1;
}