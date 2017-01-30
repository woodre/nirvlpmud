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
    if(!guide->query_spoken("ns2a")) delay((object)guide->query_whoisnewbie());
  }
}   

reset(arg) {

  if(!present("bug")) {
    for(i=0;i<4;i++) {
      move_object(clone_object("players/softly/newbie/mobs/bug.c"),this_object());
    }
  }

  if(arg) return;

  set_chance(3);
  add_msg("A cool breeze wafts through the forest....");
  add_msg("A butterfly lands on your arm....");
  add_msg("hoooooo .... hoooooooo ....");
  add_msg("Chatter..Chatter..Chatter");
  add_msg("meeEE ..  meeEE ..");

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  A broad stone path passes through brightly lit open forest.\n"+
    "A profusion of flowers edge the path.  Sunlight abounds and\n"+
    "the sounds of wildlife are everywhere.  The path continues to\n"+
    "the east.\n"; 

  items = ({
    "room",
    "The Hall of Apprentices school room is visible through the archway",
    "walls",
    "Polished white rock which is carefully laid in a silver mortar",
    "stone",
    "A heavy strong stone that is nearly unbreakable",
    "archway",
    "The large stone archway seems covered with a thin swirling\n\
mist.  Beyond the archway is a room with white stone walls",
    "forest",
    "Sunlight streams down into the open forest.  A broad\n\
stone path is beneath your feet",
    "path",
    "The stone path is very worn, but clearly defines the way\n\
through the forest",
    "flowers",
    "A profusion of trillium, laural, and other woodland flowers\n\
line the path and are scattered through the forest",
    "sunlight",
    "Streaming through the trees, the golden sunlight brings\n\
life to the forest",
    "sounds",
    "Distant sounds that may be animals or insects can be heard",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ns2.c","east",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" intones:\n"+       
	      " You can see what you are carrying, wearing, or wielding by Typing 'i' or\n"+
	      "'inventory'.  And you can see how many coins you have by typing 'sc'.  You\n"+
	      "will not be able to see items you have in a bag unless you type 'look in bag'.\n"+
	      "The items you collect and store in your bag can be sold at shops around\n"+
	      "the realm.  You can look for one in town after you are finished here.\n\n");

  guide->set_spoken("ns2a") ;
}

adv_skool() { return 1; }
