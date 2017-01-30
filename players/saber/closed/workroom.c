#include "std.h"
 int shield, notin;
init() {
  add_action("on"); add_verb("on");
  add_action("pty","pty");
  add_action("off"); add_verb("off");
  add_action("out"); add_verb("out");
  add_action("orin"); add_verb("orin");
   add_action("church","church");
   add_action("hotel","hotel");
 add_action("shop"); add_verb("shop");
  add_action("rift","rift");
 add_action("tower"); add_verb("tower");
 add_action("room"); add_verb("room");
 add_action("sanctum"); add_verb("sanctum");
  add_action("post"); add_verb("post");
  set_light( 1);
  if(this_player()->query_real_name() != "saber" && shield == 1) {
write("You feel a strange sensation and briefly see a circle of blue\n");
write("as you rebound off a symbol of warding.\n");
  if (notin == 1) {
  write("Saber is not in or on another job right now, please leave a\n");
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
   if (call_other(this_player(), "query_real_name", 0) != "saber") {
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
	   return "Saber's Citadel";
  }
 long() {
 write(""+
 "You have entered Sabers citadel, a chamber constructed entirely from\n" +
 "from polished mahogany wood.  The room is bare.  The only object of\n" +
 "interest is the circle of blue power floating seven inches off the\n" +
 "floor, just large enough for one person to sit in.  The room is\n" +
 "illuminated dimly by the aura from the blue circle.\n");
write("You may exit church, post, hotel, rift, shop, orin, tower.\n");
  }
sanctum() {
  call_other(this_player(), "move_player", "sanctum#players/saber/closed/sanctum.c");
   return 1;   }
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;
  }
room() {
call_other(this_player(), "move_player", "room#players/saber/closed/room.c");
 return 1;
}
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;
  call_other(this_player(), "move_player", "#players/hawkeye/lv1/landing.c");
  return 1;
 }
 orin() {
call_other(this_player(), "move_player", "orin's inn#players/saber/ryllian/orin1.c");
  return 1;
  }
rift() {
call_other(this_player(), "move_player", "castle#room/sunalley1");
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
 tower() {
call_other(this_player(), "move_player", "tower#players/saber/tower/tower1.c");
return 1;
  }
pty(){
  move_object(clone_object("players/saber/closed/party"),this_object());
  return 1;
  }
 shop(){
call_other(this_player(), "move_player", "shop#room/shop");
return 1;
}

realm()  { return "NT";  }
