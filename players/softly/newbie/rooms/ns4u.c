#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ns2;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ns4u")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {
  if(!present("squirrel")) {
    for(i=0;i<3;i++) {
      move_object(clone_object("players/softly/newbie/mobs/squirrel.c"),this_object());
    }
  }
   
  if(!present("nut")) {
    move_object(clone_object("players/softly/newbie/obj/nut.c"),this_object());
  }

  if(arg) return;

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  Near the top of a stately oak a group of branches\n"+
    "meets to create a sheltered nesting place lined with\n"+
    "leaves.  From this high perch all of the forest and\n"+
    "the lands beyond are visible.  It looks possible to\n"+
    "climb 'down'.\n"; 

  items = ({
    "oak",
    "The tall oak looks over the forest below",
    "branches",
    "A clutch of sturdy branches creates a platform\n\
on which things may rest",
    "leaves",
    "A dense mat of fallen leaves pads the high perch",
    "oaks",
    "Tall stately oaks dominate the forest.  They are very old",
    "spruces",
    "Dotted amongst the oak forest spruce trees reach toward the sky",
    "forest",
    "The forest has large old trees, a mix of oaks and spruces.\n"+
    "The light is dim. A narrow stone path shows the way through",
    "perch",
    "The crotch of the tree branches makes a comfortable resting\n\
place for adventurers or small animals",
    "lands",
    "Forest is visible to the south and east.  The forest seems\n\
to blend into plains to the north.  To the northeast a small\n\
rooftop is visible.  Beyond that is a desert",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ns4.c","down",
  });
}


void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" explains:\n"+ 	
	      " You have gotten injured and have had to wait to heal.  There are sometimes items\n"+
	      "which will speed your rate of healing.  The most common is alcohol, available at\n"+
	      "pubs around the realm.  Other healing items are often food or drink.  If you find\n"+
	      "any such items, try them to see if they heal you.  Remember to check your monitor.\n\n");

  guide->set_spoken("ns4u");
}

adv_skool() { return 1; }
