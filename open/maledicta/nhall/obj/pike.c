#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("pike");
set_short("Pike of the Apprentice");
set_long(
"  This is a large polearm.  Its shaft is made of a sturdy oak, with\n"+
"the large head made of steel. It seems very durable, and quite sharp.\n");
set_type("polearm");

set_class(14);
set_weight(2);
set_alias("newbie_wep");
set_value(0);
set_hit_func(this_object());
set_save_flag(0);
}

weapon_hit(attacker) {
   if(this_player()->query_level() > 5) {
      write("You are no longer an apprentice, you can not use this.\n");
      call_other(this_object(), "drop", 0);
      destruct(this_object());
      return 1;
   }
   return;
}

drop(silently) {
    if (wielded) {
        call_other(wielded_by, "stop_wielding");
        wielded = 0;
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    write("The pike vanishes as it leaves your hand.\n");
   destruct(this_object());
    return 1;
}




