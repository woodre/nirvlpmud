#include "/players/puppy/define.h"
#define NAME "Puppy"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_long(
      "As you look around you notice that there isn't much to\n"+
      "this room.  It's actually rather secluded from the rest\n"+
      "of the mud.  Perhaps this is why Puppy decided to make\n"+
      "it his home.  Everything in the room seems quite bland\n"+
      "except for a tattered blanket on one side of the room\n"+
      "and a small bowl that you should not touch.  You see a\n"+
      "small stream of water trickling down the wall.\n");
   set_light(1);
   
   add_listen("main", "The only thing making a sound is the water trickling down the walls.");
   add_smell("main", "You smell wet dog hair.");
   add_touch("bowl", "What part of "+RED+"DO NOT TOUCH"+NORM+" did you not understand?");
   items = ({
         "tattered blanket","A tattered blanket covered in fur",
         "blanket","A tattered blanket covered in fur",
         "small bowl","A small bowl used for feeding animals",
         "bowl","A small bowl used for feeding animals",
         "small stream","A stream of water running down the wall",
         "stream","A stream of water running down the wall",
         "walll","The sides of the den look quite bland"});
}

init() {
   ::init();
   add_action("post", "go");
   add_action("area", "go");
   add_action("bank", "go");
}
bank(str){
   if(!str){ notify_fail("Wh...What?\n"); return 0; }
   if(str == "color") {
      this_player()->move_player("banks of stony pond#players/puppy/EX/color.c");
      say(this_player()->query_name()+" runs off to the banks of stony pond\n");
      return 1;}
}

post(str){
   if(!str){ notify_fail("Wh...What?\n"); return 0; }
   if(str == "post") {
      this_player()->move_player("post#/room/post.c");
      say(this_player()->query_name()+" runs off to the post office\n");
      return 1;}
}

area(str){
   if(!str){ notify_fail("Wh...What?\n"); return 0; }
   if(str == "smurf") {
      this_player()->move_player("post#/room/farmroad2.c");
      say(this_player()->query_name()+" runs off to a portal\n");
      return 1;}
}
short() { int a; a = random(14);
if (a==0) return "USS Abraham Lincoln";
if (a==1) return "Air Force One";
if (a==2) return "USS Kitty Hawk";
if (a==3) return "USS Theodore Roosevelt";
if (a==4) return "USS Harry S. Truman";
if (a==5) return "USS Carl Vinson";
if (a==6) return "USS John C. Stennis";
if (a==7) return "USS Enterprise";
if (a==8) return "USS Nimitz";
if (a==9) return "USS Dwight D. Eisenhower";
if (a==10) return "USS George Washington";
if (a==11) return "NORAD";
if (a==12) return "CENTCOM";
if (a==13) return "USS John F. Kenedy";
if (a==14) return "USS George H.W. Bush";
}
