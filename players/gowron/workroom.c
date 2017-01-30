#include "std.h"

int shield, notin;
 
void reset(int arg) {
     if (arg) 
        return;
     set_light(1);
 }
 
void init() {
  add_action("on","on");
  add_action("kesu","off");
  add_action("out","out");
  add_action("church","church");
  add_action("hotel","hotel");
  add_action("shop","shop");
  add_action("post","post");
  add_action("title", "ntitle");

  if ((shield) && (this_player() != find_player("gowron"))) {
     write("\n\tA Celestial Dragon appears and TOSSES you away "+
	   "FAR AWAY.\n\n");
     if (notin == 1) {
        write("gowron is not in or on another job right now, "+
              "please leave message at the post office.\n");
     }
     this_player()->move_player("off the shields#room/church");
  }
}
 
static int on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
}
   
static int kesu() {
   if (this_player() != find_player("gowron")) {
      write("You cannot do that....Aren't you worried at what gowron "+
	    "may say?\n");
      return 1;
   }
   shield = 0;
   notin = 0;
   write("shields deactivated.\n");
   return 1;
}
   
int out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;
}

string short() { return "Circle of Darkness";}
 
void long() {
 write(""+
 "Here within these walls, peace dwells.  The Tatami floor is\n" +
 "slightly raised, except for an area nearest to the glowing\n" +
 "portal behind you- here you may remove your shoes and wdon\n" +
 "the slippers that are set before you.  On the far west wall\n" +
 "in the center, there is a Japanese Sumie painting depicting\n" +
 "the Great Mountain Fuji.  In the north east corner there is a  \n" +
 "paper door closet- within are Futons to be taken out when sleep\n" +
 "calls.  In the center of the room is a low wood table- the\n" +
 "Zabutons are stacked in the south east corner. In the north\n" +
 " west corner is a small Tansu.  The room is lit by the light\n" +
 "from the Portal.\n" +
 "Be Welcome, be comfortable.\n"+
"You may exit church, post, portal, bards, hotel, shop, chamber.\n");}

int title(string str) {
	string w,t,t2;
	object who;

	if (sscanf(str, "%s %s", w, t) < 2) {
	   write("Usage title <who> <what>\n");
           return 1;
	}
        who = find_player(w);
	if (!who) {
           write(w+" is not logged in.\n");
           return 1;
	}
	who->set_title(t);
	write(who->short());
}
      
int church() {
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
