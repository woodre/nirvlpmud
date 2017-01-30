#include "/players/llew/closed/ansi.h"

 reset(arg) {
 if(arg) return;
 set_light(1);
 }
 
init() {
  add_action("board","board");
  add_action("bards","bards");
  add_action("church","church");
  add_action("test","test");
   add_action("forest","forest");
  add_action("hotel","hotel");
  add_action("shop","shop");
  add_action("rift","rift");
  add_action("portal","portal");
  add_action("post","post");
  add_action("ndest","destruct",4);
   add_action("circle","circle");
  
if(!present("shieldstone")) move_object(clone_object("/players/llew/closed/workroom/stone"),this_object());
if(!present("pool")) {
move_object(clone_object("/players/saber/closed/bards/pool.c"),this_object());}

 }
 

short() {
   if(!present("shieldstone",this_object())) {
      move_object(clone_object("/players/llew/closed/workroom/stone.c"),this_object());
   }
   present("shieldstone",this_object())->check_shield();
   return "The "+BOLD+BLK+"Stone"+NORM+" Circle"; 
}
 
long() {
 write(""+
 "You are deep within an impenetrable forest.  Pale green light filters\n" +
 "through the leafy canopy high above.  The temperature is warm, with a\n" +
 "slight breeze.  Sounds of leaves rustling, a lone bird singing, the trickle\n" +
 "of a nearby stream falls upon your ears.  The flickering green light\n" +
 "gives off a relaxing atmosphere.  A circle of eleven stones encompasses\n" +
 "the area.  Each stone stands upright at a height of about four feet.\n" +
 "The stones are covered with carvings, spirils, strange animals, hands.\n" +
 "No animal will enter this sacred circle. \n" +
 "The ground is soft and green grass fills the area.  You wonder how such\n" +
 "can grow with as little light.  The peace of this place calms you.  You\n" +
 "feel you could rest here and be content.\n" +
  "You may exit: church, post, portal, bards, hotel, shop.\n");
   if(!present("shieldstone",this_object())) {
      move_object(clone_object("/players/llew/closed/workroom/stone.c"),this_object());
   }
   present("shieldstone",this_object())->check_shield();
   if(this_player()) {
      if(environment(this_player()) != this_object() && find_player("llew"))
         tell_object(find_player("llew"),capitalize(this_player()->query_real_name())+" is looking at you from afar.\n");
   }
}

ndest(str) {
  if(str=="llew") {
  tell_object(find_player("llew"),BOLD+"The dest field flashes.\n"+
             "Attempt to dest by "+this_player()->query_real_name()+"\n"+NORM);
  return 1;}}
  
bards() {
  call_other(this_player(), "move_player", "bards#players/saber/closed/bards/bardrooms/teleport.c");
   return 1;   }
   
church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;}
  
portal() {
call_other(this_player(), "move_player", "portal#players/saber/ryllian/portal.c");
 return 1;}
 
hotel() {
call_other(this_player(), "move_player", "hotel#players/boltar/hotel/hotel.c");
return 1;}

post(){
   call_other(this_player(), "move_player","post#room/post");
   return 1;}
   
forest() {
   this_player()->move_player("into the forest#players/llew/rooms/for_entrance.c");
   write("The trees rustle for a moment then all is silent...");
   return 1; }

  
shop(){
call_other(this_player(), "move_player", "shop#room/shop");
return 1;}

board() {
  call_other(this_player(),"move_player","board#room/adv_inner.c");
  return 1;}

test() {
  if(this_player()->query_level() < 21) {return 0;}
   this_player()->move_player("into the forest#players/llew/Other/rooms/testing_room");
   return 1;
}

circle() {
   this_player()->move_player("to the circle#players/llew/closed/temp/wedroom");
   return 1;
}
