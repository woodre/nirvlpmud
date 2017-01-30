#include "/obj/ansi.h"

status main(string str, object ob, object User)
{
  string who, what;
  object *us;
  int x;
  if(!str)
  {
    write("Use -> emotestar <name>#<msg>.\n");
    return 1;
  }
  if(sscanf(str, "%s#%s", who, what) < 2)
  {
    write("Use - emotestar <name>#<msg>.\n");
    return 1;
  }
  us = users();
  for(x=0; x<sizeof(us); x++)
  {
    if(present("star_tattoo", us[x]) && !(present("star_tattoo",us[x])->query_muff()))
    {
      tell_object(us[x], YEL+"~*~"+NORM+BOLD+"-*-"+NORM+YEL+"~*~ "+NORM+capitalize(who)+" "+what+"\n");
    }
  }
  "/obj/user/chistory.c"->add_history("star", "~*~-*-~*~ "+capitalize(who)+" "+what+"\n");
  return 1;
}