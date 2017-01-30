/*
Trenchcoat worn by Strangers in Dark City.
*/
#include "/players/feldegast/defines.h"
inherit "obj/armor";

void reset(int arg) {
  if(!arg) {
    set_name("trenchcoat");
  ::reset();
    set_alias("coat");
    set_short(BOLD+BLK+"Black trenchcoat"+NORM);
    set_type("chest");
    set_weight(2);
    set_ac(2);
    set_params("magical",2,0,0);
    set_params("other|dark",0,10,0);
    set_long(
"A stylish black leather trenchcoat.\n"
    );
    set_value(1000+random(200));
  }
}
do_special(owner)
{
  if(!random(1000)) {
    command("remove trenchcoat",owner);
    destruct(this_object());
    tell_object(owner,BOLD+"Your trenchcoat has become too ripped up and shredded to wear any longer.\n"+NORM);
    return 0;
  }
}
