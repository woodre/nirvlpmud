#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
inherit "/players/vertebraker/closed/std/monster.c";

string Location;

reset(arg)  
{
  ::reset(arg);
  if(arg) return;
  set_name("Invisible_Museum_Mob");
  set_short(0);
  set_level(1);
  set_hp(100000);
  set_no_exp_value();
}

set_location(string x) { Location = x; }

catch_tell(str) 
{
  tell_room("/players/zeus/museum/stands",
    HIY+Location+HIW+"]  "+NORM+str);
}
