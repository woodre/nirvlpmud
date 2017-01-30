/*  This is a generic workroom for wizes...
 *  go ahead and copy this and configure as you please.
 *                                     -mythos
 */
#include "std.h"
#define owner "mythos"
 int shield, notin;
 reset(arg) {
 if(arg) return;
 set_light(1);
 }
 
init() {
  add_action("on","on");
  add_action("kesu","off");
  add_action("out","out");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("shop","shop");
  add_action("post","post");
  
if(this_player()->query_real_name() != owner && shield == 1) {
  write("You bounce off the shields.\n");
  if (notin == 1) {
  write(capitalize(owner)+" is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");}
  this_player()->move_player("off the shields#room/church");}
 }
 
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;}
   
static kesu() {
  if(this_player()->query_real_name() != owner) {
   write("You can not do that.\n");
    return 1;}
   shield = 0;
   notin = 0;
   write("shields deactivated.\n");
   return 1;
   }
   
out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;}

 short() { return "Circle of Darkness";}
 
long() {
 write(""+
 "Be Welcome, be comfortable.\n"+
  "You may exit church, post, hotel\n");
}

church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;}
  
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;}

post(){
   call_other(this_player(), "move_player","post#room/post");
   return 1;}

shop(){
call_other(this_player(), "move_player", "shop#room/shop");
return 1;}
