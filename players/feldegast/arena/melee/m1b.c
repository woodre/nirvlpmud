#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=HIW+"Frozen Lake"+NORM;
  long_desc=
"  At the top of the mountain is a winter wonderland of powdery\n"+
"snow and crystal clear icicles.  A deep depression in the terrain\n"+
"has collected water and frozen, forming a frozen pond, perfect\n"+
"for skating.  A path leads back down the mountain.\n";
  items=({
    "mountain","I am Larry, King of the Lounge Lizards, and you are my Queen!\n",
    "snow","It kindof reminds you of that white stuff that keeps appearing\non your shoulders",
    "icicles","Crystal clear icicles hang from the rocks",
    "depression","There's ice in it",
    "water","It's frozen",
    "pond","Perfect for skating",
  });
  dest_dir=({
    PATH+"m1","southeast",
  });
}
long(str) {
  if(str=="mountain") view_room(PATH+"m1");
  else ::long(str);
}
init() {
  ::init();
  add_action("cmd_skate","skate");
}
int cmd_skate(string str) {
  notify_fail("Usage: skate <dir>\n");
  if(!str) return 0;
  if(str!="southeast" && str!="se") {
    write("You skate around in circles.\n");
    say(TPN+" skates around in circles.\n");
    return 1;
  }
  write("You skate off of the ice.\n");
  say(TPN+" skates off of the ice.\n");
  move_object(TP,PATH+"m1");
  return 1;
}
cmd_move() {
  if(!TP || !(TP->is_player())) return 0;
  if(TP->query_attrib("ste") < random(25)) {
    write("You slip on the ice.\n");
    say(TPN+" slips on the ice.\n");
    return 1;
  }
  return ::cmd_move();
}
