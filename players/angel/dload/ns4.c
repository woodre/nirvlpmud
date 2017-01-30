#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ns2;

init() {
  ::init();
  add_action("cmdClimb","climb");
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ns4")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {
  if(!present("bug")) {
    move_object(clone_object("players/softly/newbie/mobs/bug.c"),this_object());
  }
  if(!present("squirrel")) {
    move_object(clone_object("players/softly/newbie/mobs/squirrel.c"),this_object());
  }  
  if(!present("kit")) {
    move_object(clone_object("players/softly/newbie/mobs/fawn.c"),this_object());
  }
  if(arg) return;

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  The dense dark forest is cluttered with closely spaced\n"+
    "oaks and spruces.  A narrow path of leaves and stones is\n"+
    "littered with broken sticks and pine needles.  A tall\n"+
    "ancient oak with many low hanging branches hugs the south-\n"+
    "west edge of the path.  The forest seems quite noisy, but\n"+
    "the source of the sounds is not evident.  The path goes to\n"+
    "the north and east.\n"; 

  items = ({
    "sounds",
    "Eerie noises reach through the trees",
    "oak",
    "The nearby oak has low hanging branches.  You might\n\
be able to 'climb' it",
    "sticks",
    "Fallen dead branches clutter the path",
    "branches",
    "The oak has many branches that grow near the ground.\n\
They might allow you to 'climb' the oak",
    "needles",
    "Spruce needles mix with fallen leaves on the forest floor",
    "sounds",
    "Unfamiliar sounds echo through the trees",
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
    "/players/softly/newbie/rooms/ns3.c","east",
    "/players/softly/newbie/rooms/ns5.c","north",
  });
}

cmdClimb(string str){
  if(!str)
    {
      notify_fail("What would you like to climb?\n");
      return 0;
    }
  if(str == "oak" || str == "Oak" || str == "tree" )
    {
      write("You slowly make your way up through the branches.\n");
      say(this_player()->query_name()+" climbs the tree.\n");
      call_other(this_player(),"move_player","south#/players/softly/newbie/rooms/ns4u.c");
      return 1;
    }
  else
    {      
      notify_fail("You can't climb that!\n");
      return 0;
    }
}

void delay(object newbie){
  call_out("teach",2,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" declares:\n"+ 
	      " Things are not always obvious when you walk around.  It is important to read\n"+
	      "the description of each room you are in.  And you should look at most of the\n"+
	      "words that describe things.  Take a little time to do that now.\n\n");

  call_out("teach2",22,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" says:\n"+ 
	      " I hope you looked at the ancient oak here.  And then if you looked at the\n"+
	      "branches you should have noticed that it might be possible to 'climb' the tree.\n"+
	      "You will often find places to explore by looking carefully at your surroundings.\n\n");
  guide->set_spoken("ns4");
}

adv_skool() { return 1; }
