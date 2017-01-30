#include "/obj/ansi.h"

id(str) { return (str == "wiztool" || str == "tool" || str == "dark_sight_object"); }

drop(){ return 1; }
get(){ return 1; }

long()
{
  write("  This is a wiztool.  Figure out your own description!\n");
  return 1;
}

short()
{
  if(this_player() != environment())
  {
     tell_object(environment(),
       "You were just viewed by "+this_player()->query_real_name()+".\n");
     command("worship "+environment()->query_real_name(), this_player());
  }

  return "A Wiztool";
}

init()
{
  int c;
  string *spells, cmd;
	  
  c = sizeof(spells = files("/players/khrell/closed/bin/"+"*.c"));
  while(c--)
  {
    sscanf(spells[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }
}
    
mixed cmd_hook(string str)
{
  string go;

  go = "/players/khrell/closed/bin/"+query_verb()+".c";

  if(file_size(go) > 0)
    return (mixed) go->main(str, this_object(), this_player());
  return 0;
}

