#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons4;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons4")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {  
  if(!present("student")) {
    for(i=0;i<3;i++) {
      move_object(clone_object("players/softly/newbie/mobs/gstdnt.c"),this_object());
    }
  }
  if(arg) return;

  set_light(0);

  short_desc = "Adventurer's School";
  long_desc =
    "  A nearly empty room holds a lone student desk, its\n"+
    "broken chair attached to it.  A doorway leads west.\n"; 

  items = ({
    "desk",
    "The Student desk contains a slot to contain paper\n\
and has an attached chair",    
    "chair",
    "The broken chair is attached to a student desk",
    "door",
    "An open doorway leads west to a hall",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons1.c","west",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" observes:\n"+ 
	      " A guild is a group of people who have banded together to foster their\n"+
	      "self interest.  Upon joining a guild, you agree to obey and abide by the\n"+
	      "laws, limitations, and enhanced abilities of that guild.  Nirvana has a\n"+
	      "number of guilds.  Each has different requirements for entry.\n\n"+
	      " You may not join any guild until you have reached level 5.  Until then\n"+
	      "talk to others about their guilds, what they like and dislike about them,\n"+
	      "and what the joining requirements are so that you can make a decisions when\n"+
	      "you have reached the time to make a guild decision.\n\n");
  guide->set_spoken("ons4");
}

adv_skool() { return 1; }

