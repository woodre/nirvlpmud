#include "/players/softly/closed/ansi.h"
inherit "obj/weapon.c";
int a;
#define tp this_player()->query_name()


reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("sword");
set_short(CYN+"Sword of the Apprentice"+NORM);
set_long(
"  This is a durable "+CYN+"steel longsword"+NORM+".  It was forged in the\n"+
""+HIM+"hall of apprentices"+NORM+" a short time ago. It should serve you\n"+
"well.\n");
set_type("sword");
set_params("other|physical",0,"newbie_hit");
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
int newbie_hit(object attacker){
 if(this_player())
  {
  int a;
  a=random(10);
  if(a >= 8) {
    write("You "+HIR+"SLAM "+NORM+"your opponent with "+HIR+"MIGHTY "+NORM+"swing!\n"+
          " \n");
    say(BOLD+tp+" "+HIR+"SLAMS"+NORM+" their opponent with a "+HIR+"MIGHTY "+NORM+"swing!\n"+
    " \n");    
    return random(3); 
  }
  return 0;
} 
}
drop(silently) {
    if (wielded) {
        call_other(wielded_by, "stop_wielding");
        wielded = 0;
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    write("The sword vanishes as it leaves your hand.\n");
   destruct(this_object());
    return 1;
}








