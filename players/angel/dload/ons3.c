#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons3;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons3")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {  
  if(!present("rat")) {
    for(i=0;i<3;i++) {
      move_object(clone_object("players/softly/newbie/mobs/gstdnt.c"),this_object());
    }
  }
  if(arg) return;

  set_light(0);

  short_desc = "Adventurer's School";
  long_desc =
    "  A dozen small desks with attached chairs dot the center\n"+
    "of the room.  The floor is scuffed and grooved from the\n"+
    "passage of many small feet.  The tiny window has been painted\n"+
    "over.  On the north wall of the room is a narrow staircase.\n"; 

  items = ({
    "desks",
    "Student desks with a slot to contain paper and an attached chair",
    "floor",
    "Many adventurer's have passed through this room",
    "window",
    "The window, crafted of some unknown material, has been painted black",
    "staircase",
    "A rickety staircase hugging the wall leads up",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons7.c","up",
    "/players/softly/newbie/rooms/ons1.c","east",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" states:\n"+ 
	      " When you get too big for Adventurer's School you will still\n"+
	      "be able to enter the Adventurer's Hall until you reach Level 6.\n"+
	      "On the lower level you will find heals that you can buy at very\n"+
	      "reasonable cost.\n\n");
  call_out("teach2",12,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " On the upper level there are two important rooms.  The first is\n"+
	      "a study where you will find two books describing places you might\n"+
	      "go.  Read them carefully and often.\n\n"+
	      " You will also find lockers where you may store armors and weapons\n"+
	      "until you reach Level 6.  You will find this helpful when you leave\n"+
	      "and return.\n\n");
  guide->set_spoken("ons3");
}

adv_skool() { return 1; }

