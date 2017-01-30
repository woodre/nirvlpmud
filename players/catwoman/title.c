#include "/open/ansi.h"
#define TP this_player()
inherit "/obj/treasure.c";
   object who;
string target;
int mode,prefix;
reset(int arg) {
  if(arg) return;
  set_id("wand");
set_short("A title Maker");
}

init() {
    ::init();
if(TP->query_level() > 20) {
add_action("hero","hero");
}
}
hero() {
TP->set_pretitle("Hero of the"+RED+" LUNAR"+NORM+" empire -");
TP->set_title(BOLD+"the Razoress"+NORM);
return 1;}
drop() {
write(""+YEL+"The wand breaks as it hits the ground."+NORM+"\n");
destruct(this_object());
return 1; }
give() {
write(""+YEL+"Do you really think anyone would want this?"+NORM+"\n");
return 1; }
