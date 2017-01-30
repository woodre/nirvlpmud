#include "/players/softly/closed/ansi.h"
#include "/players/softly/newbie/define.h"
inherit "/players/softly/closed/std/room.c";

int i;
object newbie, guide;
mapping spoken;
string ons6;

init() {
  ::init();
  if(this_player() && this_player()->id("Newbie Guide")){
    guide = this_player();
    if(!guide->query_spoken("ons6")) delay((object)guide->query_whoisnewbie());
  }
}    

reset(arg) {  
  if(!present("student")) {
    move_object(clone_object("players/softly/newbie/mobs/gstdnt.c"),this_object());
  }
  if(arg) return;

  set_light(0);

  short_desc = "Adventurer's School";
  long_desc =
    "  Three small desks with attached chairs lie around the\n"+
    "room.  A large map is tacked to the wall behind a much\n"+
    "larger desk.  The tiny window has been painted over.  On\n"+
    "the north wall of the room is a narrow staircase.\n"; 

  items = ({
    "desks",
    "Student desks with a slot to contain paper and an attached chair",
    "map",
    "\n"+BOLD+
    "             ~*~ Nirvana Town Center ~*~\n"+NORM+
    "\n"+BLK+BOLD+                                      
    "    N\n"+NORM+
    "    |                                        Day   Weapon-\n"+
    " "+BLK+BOLD+" W"+NORM+"-o-"+BLK+BOLD+"E"+NORM+"                                     Care +  smith\n"+
    "    |                                            | \n"+BLK+BOLD+
    "    S"+NORM+"                      Chapel          Magic + Hotel\n"+
    "                             |                   | \n"+BOLD+
    "  ENTRY-->"+NORM+" Church       Yard + Pub  Shop   Armor + Bank\n"+
    "             |               |       |           |\n"+
    "  Bridge -"+HIG+" Green"+NORM+" - Track - Road -  Road   -    Clock - "+RED+"Pizza\n"+NORM+
    "                 |    |      |                 Tower   "+RED+" Hut\n"+NORM+
    "               Alley    Adventurers\n"+
    "                      |    Guild\n"+
    "                    Post\n"+
    "                   Office\n\n"+
    "  The"+HIB+" Hall of the Apprentices"+NORM+" is in the Village Green\n\n",
    "desk",
    "A large teacher's desk stands in front of the map",
    "window",
    "The window, crafted of some unknown material, has\n\
been painted black",
    "staircase",
    "A rickety staircase hugging the wall leads down",
    "wall",
    "The aged wall is covered with a large map",
  });

  dest_dir = ({
    "/players/softly/newbie/rooms/ons2.c","west",
    "/players/softly/newbie/rooms/ons8.c","down",
  });
}

void delay(object newbie){
  call_out("teach",4,newbie);
}

void teach(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" states:\n"+ 
	      " Nirvana is a community.  To help us all get along we try to live by some\n"+
	      "simple rules.  The most important is 'be polite'.  Treat others as you wish\n"+
	      "to be treated.  If you need help ask.  Most often people are ready and willing\n"+
	      "to help you.  If, however, no one can help you when you ask, don't insist.  If\n"+
	      "you do, you may gain a reputation that will not serve you well in the future.\n"+
	      "Read the help files.  People are more likely to help when you have done your\n"+
	      "share.\n\n");
  call_out("teach2",14,newbie);
}

void teach2(object newbie){
  tell_object(newbie, "\n"+HIR+"Drag'oman"+NORM+" explains:\n"+ 
	      " Do not ask immortals (wizards) for playing help.  They may not provide such\n"+
	      "help.  They will help if you have an unusual problem or something does not work\n"+
	      "as it should.  Try to appreciate the effort that wizards put into their job and\n"+
	      "be courteous.  Saying 'thank you' never hurts either.\n\n");
  guide->set_spoken("ons6");
}

adv_skool() { return 1; }

