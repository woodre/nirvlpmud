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



swallow_pill(){
/*
present("circle_object", find_player("ranthom"))->set_special_title(
HIM+"W"+NORM+BOLD+BLK+"eaver "+NORM+RED+"of "+NORM+HIM+"D"+NORM+BOLD+BLK+"arkness"+NORM);
*/
present("circle_object", find_player("z"))->set_special_title(BOLD+BLK+"the "+
NORM+HIW+"W"+NORM+BOLD+BLK+"itch in the "+NORM+HIW+"W"+NORM+BOLD+BLK+"oods"+
NORM);
present("circle_object", find_player("z"))->save_circle(1);
  write("You swallow the pill.\n");
  say(TP->QN+" pops a pill.\n");
return 1;
}

