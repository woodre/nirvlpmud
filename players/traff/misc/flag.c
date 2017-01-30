#include "/players/traff/closed/ansi.h"
int check;

id(str) {
    return str == "flag";
}

reset(arg) {
  if(arg) return;
  check = 0;
}

silence(n) { check = n; }

long() {
    write("A "+RED+"flag"+NORM+".\n");
    write("You can <flag> <player>, to get their attention.\n");
}

short() {
    return "A small flag";
}

init() {
  add_action("flag","flag");
}
flag (str)
{
string who;
    who = lower_case(str);
  if(!str) {
    write("Flag who?\n");
  return 1; }
  if(!find_player(who)) {
    write(who+" is not here....\n");
  return 1; }
  tell_object(find_player(who),"O\n|"+BRED+"          "+NORM+
  "\n|"+BRED+" Hey You! "+NORM+
  "\n|"+BRED+"          "+NORM+
  "\n|\n|\n"+
  NORM+capitalize(this_player()->query_real_name())+" wants your attention\n");
  write("You wave your flag at "+who+"\n");
  return 1; 
}
