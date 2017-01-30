#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons1;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons1")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {
  if(!present("rat")) {
    for(i=0;i<2;i++) {
      move_object(clone_object("players/softly/newbie/mobs/grat.c"),this_object());
    }
  }
  if(arg) return;

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  A dimly lit hallway, tall and long, contains three visible doors.\n"+
    "The doorway to the east is open.  Darkness lies beyond.  The door\n"+
    "to the west, while still on its hinges, is broken allowing one to\n"+
    "easily enter.  The footing is precarious.  It is not possible to see\n"+
    "to the north.\n"; 

  items = ({
    "hallway",
    "A long, narrow hallway of indeterminate color has a three\n\
doors visible.  The floor is cluttered with leaves and old papers",
    "doors",
    "There are doors to the west and south.  An empty doorway\n\
lies to the east",
    "doorway",
    "The eastward doorway has no door",
    "footing",
    "Papers and leaves clutter the floor.",
    "door",
    "The broken door to the west is one half of its original\n\
size.  One could easily pass through it.",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons3.c","west",
    "/players/softly/newbie/rooms/ons4.c","east",
    "/players/softly/newbie/rooms/ons2.c","north",
    "/players/softly/newbie/rooms/ns5.c","leave",

  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" notices:\n"+ 
	      " This looks like it was a school.  There seem to be some\n"+
	      "dark places ahead.  You will sometimes need a light source\n"+
	      "so that you can see what is around you in dark places.  Make\n"+
	      "sure you have one before you explore further or you might not\n"+
	      "be able to see the way out.\n\n");
  call_out("teach2",12,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " Since we are in a school, this is a good time to teach a few\n"+
	      "more things about yourself.  As you gain experience you will be\n"+
	      "able to raise your level.  Typing 'help levels' will show you the\n"+
	      "amount of xp you need to move to the next level.  Level 2 requires\n"+
	      "1014 xp.\n\n");
  guide->set_spoken("ons1");
}

adv_skool() { return 1; }

