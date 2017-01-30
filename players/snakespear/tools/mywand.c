#include "/players/snakespear/closed/ansi.h"
id(str) { return str == "wand"; }

reset() {}

long() { write("The Wand of Titles.  <ztitle player title> to change a title.\n"); }

short() { return "The Wand of Titles"; }

init() {
    add_action("ztitle","ztitle");
    add_action("zrace","zrace");
    add_action("zpretitle","zpretitle");
}

ztitle(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
/* That's where you put the title you want. */
  find_player(who)->set_title(what);  
  return 1;
}
zpretitle(string arg) {
string who,what;
sscanf(arg,"%s %s",who,what);
write(who);
write(what);
find_player(who)->set_pretitle(what);
return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 5000; }

zrace(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  find_player(who)->set_race(what);
  return 1;
}
