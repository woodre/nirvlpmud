#include "/players/traff/closed/ansi.h"
id(str) { return str == "sign"; }
short() { return WHT+"A sign about the "+GRN+"Forest"+WHT+"."+NORM;}
long() {
  write("The sign looks pretty important.\nYou should probably READ it!\n"); }

init() {
  add_action("read","read");
       }

read(str) {
  if(!str) return 0;
  if(str == "sign") {
  say((this_player()->query_name())+" reads the sign.\n");
  cat("/players/traff/delnoch/forest/WELCOME");
  return 1;
  }
return 0;
}
