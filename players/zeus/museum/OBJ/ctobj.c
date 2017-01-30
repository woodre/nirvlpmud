inherit "obj/treasure";
#include "/players/zeus/closed/all.h"

string Location;

reset(arg)  
{
  ::reset(arg);
  if(arg) return;
  set_name("Invisible_catch_tell_Object");
  set_short(0);
  enable_commands();
}

get() { return 0; }

set_location(string x) { Location = x; }

catch_tell(str) 
{
  tell_room("/players/zeus/museum/stands",
    HIY+Location+HIW+"]  "+NORM+str);
}
