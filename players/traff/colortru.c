#include "/players/arrina/closed/ansi.h"
id(str) { return str == "colorob"; }

init() {
  add_action("do_color","do_color");
}

do_color() {
find_player("truenight")->set_title(HIB+"Full of Darkness"+NORM);
return 1;}
