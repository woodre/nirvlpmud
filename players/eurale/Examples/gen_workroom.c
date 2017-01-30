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
	   return NAME+"'s workroom";
  }
 long() {
 write("shields are at " + shield + "\n");
 write(""+
           "This a generic workroom, there are a few tables and chairs\n"+
          "scattered about a bare floor.\n");
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
