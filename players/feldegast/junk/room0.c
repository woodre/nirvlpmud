#include "/players/feldegast/defines.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Blah Land";
  long_desc="Welcome to blah land, room #0!\n";
}
void init() {
  ::init();
  add_action("walk","walk");
}

walk(str) {
  string dork;
  dork="/players/feldegast/junk/room"+random(2)+".c";
  write(dork);
  move_object(TP,"/players/feldegast/junk/room"+random(2));
  command("look",TP);
  return 1;
}
