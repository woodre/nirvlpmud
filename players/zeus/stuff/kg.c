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
object kg,gob;
  write("You swallow the pill.\n");
  say(TP->QN+" pops a pill.\n");
kg = find_player("korgon");
gob = present("circle_object", kg);
gob->set_special_title("}~ "+BOLD+BLK+" erebus' "+NORM+GRN+"manipulator"+NORM);
gob->save_circle();
  destruct(this_object());
return 1;
}

