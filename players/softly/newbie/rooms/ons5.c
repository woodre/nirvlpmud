#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons5;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons5")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {  
  if(!present("student")) {
    for(i=0;i<3;i++) {
      move_object(clone_object("players/softly/newbie/mobs/gstdnt.c"),this_object());
    }
  }
  if(!present("rat")) {
    move_object(clone_object("players/softly/newbie/mobs/grat.c"),this_object());
  }
  if(arg) return;

  set_light(0);

  short_desc = "Adventurer's School";
  long_desc =
    "  Half a dozen small desks with attached chairs dot the\n"+
    "center of the room.  The air is stale with disuse.  Dark\n"+
    "shadows recollect a time when many student voices echoed.\n\n"; 

  items = ({
    "chairs",
    "The work chairs are attached to student desks",
    "desks",
    "Student desks with a slot to contain paper and an attached chair",
    "air",
    "The fetid air has not moved in a very long time",
    "shadows",
    "Shadows seem to descend over the room",
    "voices",
    "The voices are merely echoes in your imagination",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons2.c","east",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" observes:\n"+ 
	      " There are a number of different ways to communicate.  You can speak to one\n"+
	      "person over a long distance using the 'tell' command.  Once you reach the\n"+
	      "age of one hour, you may speak over the various channels available.  Type\n"+
	      "'channels' to see which ones you are on.  Gossip is the most frequently\n"+
	      "used mud-wide channel.\n\n");
  call_out("teach2",12,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " When you are able to talk on channels remember a few guidelines.  Don't 'spam'\n"+
	      "or crowd general channels with things that are not interesting to others.  If\n"+
	      "you want to carry on a long conversation either go to a room or use tells.  Also\n"+
	      "remember that most channels should be kept appropriate for the very young and\n"+
	      "the very old.  If you must swear, use the risque channel\n\n");
  guide->set_spoken("ons5");
}

adv_skool() { return 1; }

