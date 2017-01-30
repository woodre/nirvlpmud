#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons2;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons2")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {
  if(!present("rat")) {
    move_object(clone_object("players/softly/newbie/mobs/grat.c"),this_object());
  }
  if(arg) return;

  set_light(0);

  short_desc = "Adventurer's School";
  long_desc =
    "  A dimly lit hallway, tall and long, contains two visible doors.\n"+
    "The doorways to the east and west are open, but only darkness lies\n"+
    "beyond.  The footing is uncertain.  There are the sounds of small\n"+
    "feet scurrying among the leaves and papers on the floor.\n"; 

  items = ({
    "leaves",
    "Brown leaves blown in through the door litter the floor",
    "paper",
    "Yellowed papers with student writing lie all around",
    "hallway",
    "A long, narrow hallway of indeterminate color has a two\n\
doors visible.  The floor is cluttered with leaves and old papers",
    "doors",
    "There are doors to the ease and west.",
    "doorways",
    "The doors stand open, papers and debris piled against them",
    "footing",
    "Papers and leaves clutter the floor.",
    "sounds",
    "The moaning of trapped creatures tears at your heart",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons5.c","west",
    "/players/softly/newbie/rooms/ons6.c","east",
    "/players/softly/newbie/rooms/ons1.c","south",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" mentions:\n"+      
	      " If you type 'sc2' or 'score2'you will see a list of your\n"+
	      "attributes and their current values.  Typing 'help attribs'\n"+
	      "will tell you more about each of them and about the cost of\n"+
	      "raising them.  You will have to go to the Adventurer's Guild\n"+
	      "in town when you want to raise them.\n\n");
  guide->set_spoken("ons2"); 
}


adv_skool() { return 1; }

