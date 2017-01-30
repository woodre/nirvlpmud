#include "std.h"
 int shield, notin;
init() {
  add_action("on"); add_verb("on");
  add_action("pty","pty");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("out"); add_verb("out");
  add_action("north"); add_verb("north");
  add_action("west"); add_verb("west");
  add_action("east"); add_verb("east");
  set_light( 1);
  if(this_player()->query_real_name() != "boltar" && shield == 1) {
  write("You feel an electric shock and see a flash of green light as\n");
  write("you rebound off the defense shield.\n");
  if (notin == 1) {
  write("Boltar is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");
  }
  this_player()->move_player("off the shields#players/boltar/lv1/landing");
 }
 }
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != "boltar") {
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
	   return "Boltar's workroom";
  }
 long() {
 write("shields are at " + shield + "   not in message is at " + notin + "\n");
 write(""+
           "This is Boltar's workroom, the walls are covered with drawings\n" +
           "of his great designs and inventions.\n");
  }
west() {
  call_other(this_player(), "move_player", "west#players/boltar/sprooms/hall.c");
  return 1;
  }
east() {
  call_other(this_player(), "move_player", "east#players/boltar/lv1/landing.c");
  return 1;
 }
 north() {
  call_other(this_player(), "move_player", "north#room/alley");
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
  move_object(clone_object("players/boltar/closed/party"),this_object());
  return 1;
  }
query_spar_area() { return 1; }
