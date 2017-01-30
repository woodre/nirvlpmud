#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons8;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons8")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {  
  if(!present("dog")) {
    move_object(clone_object("players/softly/newbie/mobs/gdog.c"),this_object());
  }
  if(arg) return;

  set_light(0);

  short_desc = "Adventurer's School";
  long_desc =
    "  A basement room contains a few broken chairs and desks.\n"+
    "A large coal furnace sits in one corner, it's door hanging\n"+
    "from a single hinge.  Coal dust covers everything.\n"; 

  items = ({
    "room",
    "This large room is nearly empty.",
    "chairs",
    "Small student chairs with legs missing stand about",
    "desks",
    "The broken student desks have many names carved in them",
    "furnace",
    "The sturdy iron furnace was once used to burn coal.",
    "door",
    "The furnace door hangs by a single hinge",
    "dust",
    "A fine coating of black gritty material covers everything",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons6.c","up",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" observes:\n"+ 
	      " 'help rules' is short but very important.  There are a few basic rules you\n"+
	      "must follow.  Do not play more than one character at once.  Do not use 'bots'.\n"+
	      "And do what wizards tell you to do.  If you violate the rules you may find\n"+
	      "yourself in prison.  Prison is not a pleasant place to spend time.\n\n");
  call_out("teach2",12,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " But let us not think of unpleasant things.  By now you should have some xp,\n"+
	      "armor, a weapon, and perhaps a map of town.  We are glad you have chosen to\n"+
	      "spend some time with us.  Above all, HAVE FUN!!! \n\n");
  guide->set_spoken("ons8");
}

adv_skool() { return 1; }




