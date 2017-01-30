int dose;

status loaded;

#include "/players/vertebraker/ansi.h"
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


drop() { return 1; }
get() { return 1; }

id(str) { return (str=="derv_ac_mod"); }

init() {
  if(!loaded) {
  environment()->RegisterArmor(this_object(), ({ "physical", 0, 0, "do_special" }));
  begin();
  dose=(int)this_player()->query_extra_level() / 20;
  loaded=1;
  }
}

do_special() {
  return -dose;
}
