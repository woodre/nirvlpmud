#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("hammer");
set_short("War Hammer of the Apprentice");
set_long(
"  This Hammer was created at the hall of apprentices. It has\n"+
"a huge steel head which shines in the light. The handle is\n"+
"made of a strong oak, with a leather strap attached to it at\n"+
"the base.\n");
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
    write("The hammer vanishes as it leaves your hand.\n");
   destruct(this_object());
    return 1;
}







