#include "/players/softly/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("club");
set_short("Gnarled Club");
set_long(
"  This club was created by Drag'oman for use by beginning\n"+
"adventurers.  It is aged and gnarled, a branch from some\n"+
"ancient tree.  It has a good gripping surface on one end.\n"+
"It will serve new adventurers well.\n");
set_type("club");

set_alias("newbie_wep");
set_class(13);
set_weight(1);
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
    write("The club vanishes as it leaves your hand.\n");
   destruct(this_object());
    return 1;
}







