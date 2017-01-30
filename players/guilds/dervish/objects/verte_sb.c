#include <ansi.h>
int dose;

status loaded;

int saved_ac;
begin()
{
  call_out("tick_end", 1800);
}

tick_end()
{
 if(environment())
 {
  environment()->RemoveArmor(this_object());
    tell_room(environment(), BOLD+"The power of SandBlast seems to have worn off.\n"+NORM);
 }
 destruct(this_object());
}

set_dose(x){ dose += x; }

drop() { return 1; }
get() { return 1; }

id(str) { return (str=="derv_ac_mod"); }

init() {
  if(!loaded) {
   environment()->RegisterArmor(this_object(), ({ "physical", 0, 0, "do_special"}));
  begin();
  loaded=1;
  }
}

do_special() {
  return -dose;
}

short() {
  if( this_player() && this_player()->query_level() > 80 )
    return "<<INVIS>> Dervish AC Mod (dose: "+dose+")";
}
