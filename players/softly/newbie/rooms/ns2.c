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
    if(!guide->query_spoken("ns2")) delay((object)guide->query_whoisnewbie());
  }
  add_action("get_bag","search");
}    

reset(arg) {
  if(!present("bug")) {
    for(i=0;i<4;i++) {
      move_object(clone_object("players/softly/newbie/mobs/bug.c"),this_object());
    }
  }

  if(arg) return;
  set_chance(2);
  add_msg("A cool breeze wafts through the forest....");
  add_msg("A butterfly lands on your arm....");
  add_msg("hoooooo .... hoooooooo ....");
  add_msg("Chatter..Chatter..Chatter");
  add_msg("Suddenly there is a faint scream in the distance....");
  add_msg("meeEE ..  meeEE ..");
  add_msg("Crickets chirp in the distance....");

  set_light(1);

  short_desc = "Adventurer's School";
  long_desc =
    "  A broad stone path passes through brightly lit open forest.\n"+
    "A profusion of flowers edge the path.  Sunlight abounds and\n"+
    "the sounds of wildlife are everywhere.  The path continues to\n"+
    "north and to the south a shimmering open archway through which\n"+
    "a room with white stone walls can be seen.\n"; 

  items = ({
    "leaves",
    "The forest floor is covered with leaves.  If you\n"+
    "'search leaves' you might find something",
    "trees",
    "Tall and stately, they group to form a dense forest",
    "mist",
    "Swirls of grey and silver cover the archway",
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
    "A profusion of trillium, laurel, and other woodland flowers\n\
line the path and are scattered through the forest",
    "sunlight",
    "Streaming through the trees, the golden sunlight brings\n\
life to the forest",
    "sounds",
    "Distant sounds that may be animals or insects can be heard",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ns3.c","north",
    "/players/softly/newbie/rooms/ns2a.c","west",
    "/players/softly/newbie/rooms/ns2b.c","east",   
    "/players/softly/newbie/rooms/ns1.c","south",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  if(!newbie) return;
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" declares:\n"+ 
	      " Here are some monsters that you may fight.  Remember to type 'mon' so\n"+
	      "that you can check your health.  If your hp gets low, go south.  These\n"+
	      "monsters will not follow you.  Your hp will slowly recover.  Type 'mon'\n"+
	      "from time to time to see how you are doing.\n\n"+
	      " There is information about the things I am showing you in Nirvana's 'help'\n"+
	      "files.  To access information about hitpoints, type 'help hitpoints'.  You\n"+
	      "can do the same thing with many other commands.  Just typing 'help' will\n"+
	      "guide you to a lot of basic information.\n\n");

  call_out("teach2",14,newbie);
}

void teach2(object newbie){
  if(!newbie) return;
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" goes on:\n"+ 
	      " After killing a monster look to see if it left anything by typing 'l'.\n"+
	      "Also type 'get all from corpse' to retrieve any loot.  Coins will be added\n"+
	      "to your total.  You can see how many coins you have by typing 'sc'.  You\n"+
	      "must carry other items.  It might be useful to have a bag to put them in.\n"+
	      "As a matter of fact, I think I noticed one under the leaves.  If you type\n"+
	      "'search leaves' you might find it.\n\n");
   if(guide)
  guide->set_spoken("ns2");
}

status get_bag() {
  if(!present("bag", this_player())) {
    if(this_player()->add_weight(1)) {
      move_object(clone_object("players/sandman/NEWBIE/newbie_bag.c"), this_player());
      write("You found a bag hiding under the leaves!\n");
    } 
    else write("You found a bag, but you are carrying too much already.\n");
    return 1;
  }
}

adv_skool() { return 1; }

