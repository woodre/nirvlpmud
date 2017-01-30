inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_short("A pill");
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill" || str == "kill_check_object"; }

  init(){
  ::init();
  add_action("swallow_pill", "swallow");
}


testt(){ write("yayaya\n"); }

swallow_pill(){
  write("You swallow the pill.\n");
  say(TP->QN+" pops a pill.\n");
get_a_different_error_in_the_log_so_i_can_tell_whats_new_and_whats_old();
  destruct(this_object());
return testt(); }

kill_check(object nmy){
object c;
if((c = present("corpse", environment(environment()))))
tell_object(environment(), "YES\n");
else
tell_object(environment(), "NO\n");
}
