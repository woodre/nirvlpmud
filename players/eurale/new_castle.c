#include "/open/ansi.h"
#define TP this_player()
#define NAME "You"
#define DEST "room/exit"

id(str) { return str == "name"; }

short() { return "What player will see"; }

long() { write(
  "A description of what is seen when looked at.\n");
}

init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
  if(!id(str)) return 0;
TP->move_player("message#/players/wiz/path.c");
    return 1;
}

reset(arg) {
  if(arg) return;
    move_object(this_object(), DEST);
}

is_castle(){return 1;}
