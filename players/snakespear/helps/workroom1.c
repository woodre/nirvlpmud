#include "std.h"
#define NAME "your_name"
 int shield;
init() {
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("north"); add_verb("north");
  add_action("west"); add_verb("west");
  set_light( 1);
  if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a flash of white light as\n");
  write("you rebound off the defense shield.\n");
  this_player()->move_player("off the shields#room/church");
  }
 }
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != NAME) {
  write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   write("shields deacivated.\n");
   return 1;
   }

short() {
  return "a hole in the ground";
  }
 long() {
 write("shields are at " + shield + "\n");
 write(""+
 "You are perched high above a large city on a small ledge. There\n"+
 "are several low lying clouds surrounding you.  Looking back\n"+
 "you can gaze into a dark portal, except something tells you that\n"+
 "doing so would make for a lethal descision on your part.  The dark\n"+
 "stones of the building seems to almost come alive with life when the\n"+
 "sun falls below to hills to the west. You feel at ease with the yourself here.\n");
  }
west() {
  call_other(this_player(), "move_player", "west#room/adv_inner.c");
  return 1;
  }
 north() {
  call_other(this_player(), "move_player", "north#room/alley");
  return 1;
  }
post(){
  object mobj;
move_object(this_player(), "room/post");
   return 1;
  }
