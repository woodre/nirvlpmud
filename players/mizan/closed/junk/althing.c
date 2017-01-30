#include "/players/bastion/closed/color.h"
id(str) { return str == "titler"; }
short() { return "An al_title titler"; }
long() {
  write("Usage: al_title <str>.\n");
}

init() {
  add_action("use","al_title");
}

use(str) {
  this_player()->set_al_title(BLINK + BLUE + str + OFF);
  write("Ok.\n");
}
