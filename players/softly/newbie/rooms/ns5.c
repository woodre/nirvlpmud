#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ns5;

init() {
  ::init();
  add_action("cmdOpen","open");
  add_action("north","north");
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ns5")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {
  if(!present("firefly")) {
    move_object(clone_object("players/softly/newbie/mobs/ffly.c"),this_object()); 
  }  

  if(arg) return;

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  The path ends suddenly at a door.  In the midst of the forest sets\n"+
    "a very old structure, battered and covered with leaves.  The trees\n"+
    "close in around the sturdy large wooden building.  A tattered sign\n"+
    "hangs precariously from a single piece of chain.  Odd sounds, perhaps\n"+
    "moaning, can be heard inside.\n"; 

  items = ({
    "sign",
    "A worn hand made sign hangs above the door.\n\n"+ YEL +
    "     |~~~~~~~~~~~~~~~~~~~~~~~~~| \n"+
    "     |'                       '| \n"+
    "     |    Realm of Nirvana     | \n"+
    "     |   Adventurer's School   | \n"+
    "     |        est. 731         | \n"+
    "     |                         | \n"+
    "     |~~~~~~~~~~~~~~~~~~~~~~~~~| " + NORM +
    "",
    "chain",
    "A single length of chain holds a sign",
    "structure",
    "The large wooden building with peeling paint\n\
looks as if it may once have been a school",
    "building",
    "The sturdy structure has fallen into disrepair.\n\
It looks like it was once well used.  A sign hangs\n\
above the door",
    "door",
    "The slightly ajar door looks like it has not\n\
moved in a very long time.  It blocks your entry.\n\
Try to 'open' it",
    "sticks",
    "Fallen dead branches clutter the path",
    "branches",
    "The oak has many branches that grow near the ground.\n\
They might allow you to 'climb' the oak",
    "needles",
    "Spruce needles mix with fallen leaves on the forest floor",
    "sounds",
    "Soft moans and cries in many voices echo through the trees",
    "leaves",
    "A dense mat of fallen leaves pads the forest floor",
    "path",
    "A few stones and packed down leaves create a forest path",
    "oaks",
    "Tall stately oaks dominate the forest.  They are very old",
    "spruces",
    "Dotted amongst the oak forest spruce trees reach toward the sky",
    "forest",
    "The forest has large old trees, a mix of oaks and spruces.\n"+
    "The light is dim. A narrow stone path shows the way through",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons1.c","north",
    "/players/softly/newbie/rooms/ns4.c","south",
  });
}

status north(){
  write("\As you try to step north, you smack your head into\n\
the closed door.  Perhaps you should open it.\n");
  return 1;
}

cmdOpen(string str){
  if(!str)
    {
      notify_fail("What would you like to open?\n");
      return 0;
    }
  if(str == "door")
    {
      write("The door creaks loudly, then suddenly flies open.\n"+
	    "You fall into the room as leaves swirl and fly in\n"+
	    "with you.  The door slams loudly.\n\n");
      say(this_player()->query_name()+" opens the door and goes through it.\n");
      call_other(this_player(),"move_player","south#/players/softly/newbie/rooms/ons1.c");
      return 1;
    }
  else
    {      
      notify_fail("You can't open that!\n");
      return 0;
    }
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" observes:\n"+ 
	      " Sometimes the direction in which you may travel is not\n"+
	      "obvious.  Look carefully at each of the items that are\n"+
	      "mentioned.  There are usually clues hidden there.\n\n"+
	      " Don't forget to look at the door.\n\n"+
	      "\tDrag'oman waits patiently.\n\n");
  call_out("teach2",12,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " Of course you could try going north without looking\n"+
	      "at anything.  But you might end up in a very dangerous\n"+
	      "situation.  Remember, death may always be waiting for\n"+
	      "you around the next turn or over the next cliff.\n\n");
  guide->set_spoken("ns5");
}

adv_skool() { return 1; }
