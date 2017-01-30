#include "std.h"
#define NAME "Francesco"
 int shield;
init() {
  add_action("on","on");
  add_action("post","post");
  add_action("off","off");
  add_action("north","north");
  add_action("west","west");
   add_action("sw","sw");
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
sw(){
object mobj;
move_object(this_player(), "/players/francesco/workroom");
return 1;
}
