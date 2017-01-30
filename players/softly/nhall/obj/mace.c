#include "/players/softly/closed/ansi.h"
inherit "obj/weapon.c";



reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("mace");
set_short("Mace of the Apprentice");
set_long(
"  This mace was created at the hall of apprentices. Its huge\n"+
"spiked head is made of a durable steel, and the shaft is made\n"+
"of a short oak wood.  It is very durable and quite capable of\n"+
"delivering good damage.\n");
set_type("club");

set_alias("newbie_wep");
set_class(18);
set_weight(0);
set_value(0);
set_hit_func(this_object());
set_save_flag(0);
}

weapon_hit(attacker) {
   if(this_player()->query_level() > 7) {
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
    write("The mace vanishes as it leaves your hand.\n");
   destruct(this_object());
    return 1;
}







