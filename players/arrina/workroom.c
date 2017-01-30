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
   add_action("garden","garden");
   add_action("crystal"); add_verb("crystal");
   add_action("post"); add_verb("post");
 set_light( 1);
   if(this_player()->query_real_name() != "arrina" && shield == 1) {
 write("You feel a strange sensation and briefly see a circle of crystal\n");
 write("as you rebound off a symbol of warding.\n");
  if (notin == 1) {
  write("Arrina is not in or on another job right now, please leave a\n");
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
   if (call_other(this_player(), "query_real_name", 0) != "arrina") {
   write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   notin = 0;
   write("shields deactivated.\n");
   return 1;
   }
 out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;
   }
  short() {
   return "Dark Crystal";
  }
 long() {
 write(""+
 "You have entered Arrina's crystal workroom.  It is formed out of\n" +
 "many shapes of transparent quartz, and gives off an aura of power.\n" +
 "The room is bare, yet somehow comfortable.  The crystals give off\n" +
 "strange light and warmth, but also give you the feeling that they\n" +
 "could become instantly cold and dark should you anger the owner.\n");
 write("You may exit church, post, hotel, garden, shop, orin, crystal.\n");
  }
 church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;
  }
 hotel() {
 call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
 return 1;
  }
  orin() {
 call_other(this_player(), "move_player", "orin's inn#players/saber/ryllian/orin1.c");
   return 1;
  }
 garden() {
 call_other(this_player(), "move_player", "garden#/players/arrina/closed/misc/garden");
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
  crystal() {
 call_other(this_player(), "move_player", "crystal#players/arrina/castle.c");
 return 1;
   }
  shop(){
 call_other(this_player(), "move_player", "shop#room/shop");
 return 1;
 }
  realm()  { return "NT";  }
