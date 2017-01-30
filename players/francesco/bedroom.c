#include "std.h"
#define NAME "Francesco"
inherit "room/room";
 
int shield;
init() {
  add_action("on","on");
  add_action("post","post");
  add_action("off","off");
  add_action("north","north");
  add_action("west","west");
add_action("chiesa","chiesa");
  set_light( 1);
  if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a flash of white light as\n");
  write("you rebound off the defense shield.\n");
  this_player()->move_player("off the shields#room/church");
  }
 }
static on() {
   shield = 1;
   /* write("shields activated.\n"); */
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
  return "" + "Francesco's bedroom";
  }
 long() {
 /* write("shields are at " + shield + "\n"); */
 write("\n"+
           "  The bedroom.\n"+
           "\n");
  }
dest_dir = ({
   "/players/francesco/workroom.c","do",
   "/players/francesco/workroom.c","not",
   "/players/francesco/workroom.c","disturb",

})

west() {
  call_other(this_player(), "move_player", "west#room/adv_inner.c");
  return 1;
  }
 north() {
  call_other(this_player(), "move_player", "north#room/alley");
  return 1;
  }
church() {
call_other(this_player(), "move_player","church#room/church");
return 1;
}
post(){
  object mobj;
move_object(this_player(), "room/post");
   return 1;
  }
chiesa(){
move_object(this_player(), "room/church");
return 1;
}
