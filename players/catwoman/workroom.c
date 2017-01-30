#include "std.h"
 int shield, notin;
init() {
  add_action("on","on");
  add_action("post","post");
  add_action("off","off");
  add_action("out","out");
  add_action("south","south");
  add_action("church","church");
  add_action("lockers","lockers");
  set_light( 1);
  if(this_player()->query_real_name() != "catwoman" && shield == 1) {
  write("You feel thump as\n");
  write("you bounce off the door.\n");
  if (notin == 1) {
  write("Nobody is home.\n");
  
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
   if (call_other(this_player(), "query_real_name", 0) != "catwoman") {
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
           return "Catwoman's workroom";
  }
 long() {
 write("Catwoman's workroom. exits are south, church, lockers and post.\n");
 write("shields are at " + shield + "   and message is at " + notin + "\n");
 
  }

 south() {
  call_other(this_player(), "move_player", "south#/players/catwoman/study");
  return 1;
  }
lockers() {
  call_other(this_player(), "move_player", "lockers#/players/catwoman/tl");
  return 1;
  }
church() {
  call_other(this_player(), "move_player", "church#room/church");
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

