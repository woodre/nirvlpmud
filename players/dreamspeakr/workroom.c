#include "std.h"
#include "/players/dreamspeakr/closed/ansi.h"
#define NAME "dreamspeakr"


inherit "room/room";

  int shield;
init() {
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("church"); add_verb("church");
  add_action("wizadv"); add_verb("wizadv");
  add_action("dreams"); add_verb("dreams");
  add_action("vamp"); add_verb("vamp");
  add_action("ninja"); add_verb("ninja");
  add_action("mage"); add_verb("mage");
  add_action("ranger"); add_verb("ranger");
  add_action("poly"); add_verb("poly");
  add_action("knight"); add_verb("knight");
  add_action("chamber"); add_verb("chamber");
  add_action("daycare"); add_verb("daycare");
  add_action("hotel"); add_verb("hotel");
  add_action("portal"); add_verb("portal");
  add_action("adv"); add_verb("adv");
  add_action("angel"); add_verb("angel");
  add_action("warp"); add_verb("warp");

  set_light(1);
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
   return "Dark room";
  }
 long() {
 write("shields are at " + shield + "\n");
 write("\n"+
           "Steaming hot water swirls all around this marble hottub.  \n"+
           "A bottle of sparkling champayne chills in a small icebucket \n"+
           "on the side.  The soft lighting here is very soothing.  Soft \n"+
           "relaxing music plays in the background.  There is a sign above  \n"+
           "the hottub.\n"+
           "\n");
   }
wizadv() {
  call_other(this_player(), "move_player", "wizadv#room/adv_inner.c");
  return 1;
  }
church() {
  call_other(this_player(), "move_player", "church#room/church");
  return 1;
  }
post(){
  call_other(this_player(), "move_player", "post#room/post");
   return 1;
  }
vamp(){
  call_other(this_player(), "move_player", "vamp#/players/nooneelse/black/guild_hall");
   return 1;
  }
ninja(){
  call_other(this_player(), "move_player", "ninja#/players/snow/closed/cyber/rooms/entrance.c");
   return 1;
  }
mage(){
  call_other(this_player(), "move_player", "mage#/room/eastroad2");
   return 1;
  }
ranger(){
  call_other(this_player(), "move_player", "ranger#/players/beck/room/mountain2");
   return 1;
  }
poly(){
  call_other(this_player(), "move_player", "poly#/players/mizan/etheriel/ROOMS/spuck");
   return 1;
  }
knight(){
  call_other(this_player(), "move_player", "knight#/room/south/sshore1");
   return 1;
  }
chamber(){
  call_other(this_player(), "move_player", "chamber#/players/mythos/enterance");
   return 1;
  }
daycare(){
  call_other(this_player(), "move_player", "daycare#/players/boltar/sprooms/daycare.c");
   return 1;
  }
hotel(){
  call_other(this_player(), "move_player", "hotel#/players/boltar/hotel/hotel.c");
   return 1;
  }
portal(){
  call_other(this_player(), "move_player", "portal#/players/saber/ryllian/portal.c");
   return 1;
  }
adv(){
  call_other(this_player(), "move_player", "adv#/room/adv_guild.c");
   return 1;
  }
dreams(){
  call_other(this_player(), "move_player", "dreams#/room/forest9");
   return 1;
  }
angel(){
  call_other(this_player(), "move_player", "angel#/room/south/sforst45.c");
   return 1;
  }
warp(){
  call_other(this_player(), "move_player", "warp#/players/eurale/closed/warp.c");
   return 1;
  }

reset(arg) {
  move_object(clone_object("/players/dreamspeakr/exit.c"), this_object());
  if(arg) return;
}