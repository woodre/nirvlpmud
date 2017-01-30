/* A fishing pole, Created <5/12/00> by Jara */

#include "/players/jara/misc/ansi.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("pole");
  set_short("A fishing pole");
  set_long("The fishing pole has a large reel and a long, sturdy rod. The\n"+
    "wire holds a hook with a wriggling worm for bait. You could"+HIW+" cast\n"+
    NORM+"the "+HIW+"line"+NORM+" or"+HIW+" reel"+NORM+" it in.\n");
  set_weight(1);
  set_value(300);
}

void init() {
  ::init();

  add_action("fisher", "cast");
  add_action("reeler", "reel");
  }

fisher(str) {
  if(!str) {
    notify_fail("What do you want to cast?\n");
  return 0;
  }

  if((str == "line") && (file_name(environment(this_player()))=="players/jara/area1/docks/room/dock2")) {
  write("You cast the line deep into the waters.\n");
  say(tp+" casts the fishing line deep into the waters.\n");
  return 1;  
  }
  else {
    notify_fail("You can't cast the line here.\n");
  return 0;
  }
}

reeler(str) {
  if(!str) {
    notify_fail("What do you want to reel?\n");
  return 0;
  }

  if((str == "line") && (file_name(environment(this_player()))=="players/jara/area1/docks/room/dock2")) {
    write("You reel the line in.\n");
  say(tp+" reels in the fishing line.\n");
  return 1;
  }

  else {
    notify_fail("You can't reel the line in here.\n");
  return 0;
  }
}
