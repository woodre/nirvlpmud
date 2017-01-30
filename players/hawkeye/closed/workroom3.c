#include "std.h"
 int shield, notin;
init() {
  add_action("on"); add_verb("on");
  add_action("pty","pty");
  add_action("off"); add_verb("off");
  add_action("out"); add_verb("out");
  add_action("guild"); add_verb("guild");
   add_action("church","church");
   add_action("hotel","hotel");
  add_action("castle","castle");
  add_action("post"); add_verb("post");
  set_light( 1);
  if(this_player()->query_real_name() != "dragnar" && shield == 1) {
  write("You feel an electric shock and see a flash of green light as\n");
  write("you rebound off the defense shield.\n");
  if (notin == 1) {
  write("Dragnar is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");
  }
  this_player()->move_player("off the shields#room/church");
 }
 }
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != "dragnar") {
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
	   return "The Swamp";
  }
 long() {
 write("shields are at " + shield + "   not in message is at " + notin + "\n");
 write(""+
           "This is Dragnar's workroom, the walls are covered with drawings\n" +
        "of his great designs and inventions.\n") +
write("Obvious exits are: Church, Post, Hotel, Guild, Castle.\n");
  }
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;
  }
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;
  call_other(this_player(), "move_player", "#players/hawkeye/lv1/landing.c");
  return 1;
 }
 guild() {
  call_other(this_player(), "move_player", "guild#players/grimm/guild");
  return 1;
  }
castle() {
call_other(this_player(), "move_player", "castle#room/crop");
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
  move_object(clone_object("players/dragnar/closed/party"),this_object());
  return 1;
  }
