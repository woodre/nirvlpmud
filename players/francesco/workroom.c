#include "std.h"
#define NAME "Francesco"
 int shield;
init() {
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("north"); add_verb("north");
  add_action("west"); add_verb("west");
  add_action("chiesa"); add_verb("chiesa");
  add_action("bed");add_verb("bed");
  add_action("tree");add_verb("tree");

  set_light( 1);
  if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a flash of white light as\n");
  write("you rebound off the defense shield.\n");
  this_player()->move_player("off the shields#room/church");
  }
 }
static on() {
   shield = 1;
   /* write("shields activated.\n"); */
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
   return ""+"Francesco's office in the Dept. of Mech. Engr.";
  }
 long() {
 /* write("shields are at " + shield + "\n"); */
 write("\n\
      A strange  feeling permeates  this office:  if you look at the type of\n\
    the items inside, then you can understand that the guy living here  must\n\
    be full  of interests in  the engineering.  In fact, the books scattered\n\
    around are typically addressed to such studies, with particular emphasis\n\
    to the manufacturing and mechanical sciences.  Moreover,  it is possible\n\
    to see some items useful  for experiencing  and studying those subjects:\n\
    micrometers,  cutting tools,  posters  depicting  industrial activities,\n\
    and even a small demonstrative lathe.  On the other side, there is a lot\n"+
"    of confusion  and the chaos is huge.  Piles of papers  lay on the top of\n\
    the desk, a printer is always running,  a crackling intercom to the labs\n\
    is insistently buzzing and continuosly annoying you and if you just stay\n\
    for a couple of minutes here, then you can see ordes of students running\n\
    in and out of the office, asking and questioning  about their thesis and\n\
    about their homeworks  and about their finals and about their study plan\n\
    and about their graduation time and about......  Oh my!!!  You wonder if\n\
    that guy is somehow  crazy or  he could be  reliable enough  in order to\n\
    handle all of these activities and as far as his work is concerned.\n\
 \n");
  }
west() {
  call_other(this_player(), "move_player", "west#room/adv_inner.c");
  return 1;
  }
 north() {
  call_other(this_player(), "move_player", "north#room/alley");
  return 1;
  }
church() {
call_other(this_player(), "move_player","church#room/church");
return 1;
}
post(){
  object mobj;
move_object(this_player(), "room/post");
   return 1;
  }
chiesa(){
move_object(this_player(), "room/church");
return 1;
}
bed() {
call_other(this_player(),"move_player","bed#players/francesco/bedroom1");
return 1;
}
tree() {
call_other(this_player(),"move_player","tree#players/francesco/kissing");
return 1;
}
