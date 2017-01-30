#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons7;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons7")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {  
  if(!present("teacher")) {
    move_object(clone_object("players/softly/newbie/mobs/gteach.c"),this_object());
  }
  if(!present("map")) {
    move_object(clone_object("players/softly/newbie/obj/tmap.c"),this_object());
  }
  if(arg) return;

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  A dusty attic has a little light peeking in through\n"+
    "cracks in the roof.  Piles of papers and slate lie in\n"+
    "disarray all over the room.  On the north wall of the\n"+
    "room is a narrow staircase.\n"; 

  items = ({
    "attic",
    "Musty and moldy, years of student papers and detrius\n\
are stored here.  A large desk sits in a corner",
    "cracks",
    "The roof like the rest of the building is deteriorating",
    "papers",
    "Stacks and stacks of papers lie all around.  They are\n\
covered with childish writing",
    "slate",
    "Irregularly shaped pieces of slate, some with chalked\n\
writing, lie on the floor.",
    "staircase",
    "A rickety staircase leads down",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons3.c","down",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" sadly says:\n"+ 
	      " Sometimes in spite of your best efforts you may die.  When that happens you\n"+
	      "are a ghost and cannot wear armor, wield weapons, or carry coins.  Death,\n"+
	      "while not permanent, is costly.  You lose 1/3 of your experience.  Try to\n"+
	      "remember that death is part of the game, and don't be too discouraged.\n\n");
  call_out("teach2",12,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" observes:\n"+ 
	      " To revive from death go to the church and pray.  Then it is a good idea to\n"+
	      "return to the place where you died to retrieve your coins and equipment.  Try\n"+
	      "to remember the exact location and retrieve your stuff quickly.  Your corpse\n"+
	      "will not lie around for very long.  And there are unscrupulous players who\n"+
	      "will occasionally help themselves to your things.\n\n");
  guide->set_spoken("ons7");
}

adv_skool() { return 1; }

