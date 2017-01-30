#include "std.h"
 int shield, notin;
init() {
  add_action("on"); add_verb("on");
  add_action("pty","pty");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("out"); add_verb("out");
  add_action("north"); add_verb("north");
  add_action("view"); add_verb("view");
  add_action("scene"); add_verb("scene");
   add_action("upload"); add_verb("upload");
  set_light( 1);
  if(this_player()->query_real_name() != "lew" && shield == 1) {
  write("You feel an electric shock and see a flash of green light as\n");
  write("you rebound off the defense shield.\n");
  if (notin == 1) {
  write("Lew is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");
  }
  this_player()->move_player("off the shields#room/station");
 }
 }
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != "lew") {
  write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   notin = 0;
   write("shields deacivated.\n");
   return 1;
   }
out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;
   }

short() {
         return "Joplin";
  }
 long() {
 write("shields are at " + shield + "   not in message is at " + notin + "\n");
 write(""+
          "This is Lew's workroom.  Now why on earth would you ever\n"+
          "want to be here?\n");
  }
 north() {
  call_other(this_player(), "move_player", "north#room/church");
  return 1;
  }
post(){
  object mobj;
/*
   mobj = clone_object("/obj/mail_reader.c");
   move_object(mobj, this_player());
*/
move_object(this_player(), "room/post");
   return 1;
  }
pty(){
  move_object(clone_object("players/lew/closed/party"),this_object());
  return 1;
  }
view(str) {
    object target;
    target=find_living(str);
    if(this_player()->query_level() < 21) return 1;
    if(!str) return 1;
    if(!target) return 1;
    call_other(target, "look");
    return 1;
}
upload() {
     object item;
     item=clone_object("players/lew/closed/quarter");
     if(this_player()->query_real_name() != "lew") return 1;
     move_object(item, this_player());
     return 1;
}
