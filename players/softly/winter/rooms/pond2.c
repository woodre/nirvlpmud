#include "/players/softly/misc/ansi.h"

inherit "/room/room";
string iname;
int price;
object thing;

init() {
  ::init();
  add_action("cmd_read", "read");
  add_action("buything","buy");
  add_action("buything","purchase");
  add_action("buything","order");
  add_action("cmdSouth","south");
  add_action("buything","rent");

}    
reset(arg) {
  if(!present("bryant")) 
  move_object(clone_object("players/softly/winter/tbryant"),this_object());

  if(arg) return;
set_light(1);

short_desc = "A Cold Shack";
long_desc ="  A rough three sided shack stands to the south.  Tacked to\n"+
           "one of the upright braces is a hand made cardboard sign.\n"+
           "The narrow lakeside path continues to the east.  Westward a\n"+
           "large fire is visible.\n";

items = ({
  "skates","The skates, hanging on nails at the back of the\n\
shack, are worn but well sharpened",
  "bottles","The bottles contain brandy ready for warming",
  "shack", "The three sided shack is roughly made of wood.  A rough\n"+
           "sign is tacked to one board.  A few ice skates and other\n"+
           "items hang from nails.  A steaming pot and several bottles\n"+
           "sit on top of a hand made table",
  "table",     "The rough table holds a pot, bottles, and several cups",
  "pot",       "The pot is steaming",
  "path",      "The narrow lakeside path is very icy",
  "fire",      "The dancing red and gold of the fire seem out of place in\n"+
               "this desolate frozen landscape",
  "lake",      "The ice is quite thick covering the surface of the solidly\n"+
               "frozen lake. Looking closely there are a few small holes on\n"+
               "the surface",
  "sign",      "        >======================<\n"+
               "        |       Bryant's       |\n"+
               "        |                      |\n"+
               "        | Warm yourself        |\n"+
               "        |  Hot chocolate  625  |\n"+
               "        |  Marshmallows   625  |\n"+
               "        |  Brandy         720  |\n"+
               "        |                      |\n"+
               "        | Rentals              |\n"+
               "        |  Ice Skates      50  |\n"+
               "        >======================<",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond5.c","north",
  "/players/softly/winter/rooms/pond1.c","east",
  "/players/softly/winter/rooms/pond3.c","west",
  });
}

/* Did somebody kill Mr. Bryant ? */

buything(string str){ 
  if(!present("bryant", this_object())){
    write("Mr. Bryant isn't here right now.\n");
    return 1;
  }

/* What to buy */

  if(str == "brandy") {
    thing = clone_object("players/softly/winter/brandy.c");
    price=720;
    iname="brandy";
  }
  else if(str == "marshmallows" || str == "marshmallow" || str == "marshmellows") {
    thing = clone_object("players/softly/winter/marshm.c");
    price=625;
    iname="marshmallows";
  }
  else if(str == "chocolate" || str == "hot ch" || str == "hot chocolate") {
    thing = clone_object("players/softly/winter/hotchoc.c");
    price=625;
    iname="hot chocolate";
  }
  else if(str == "skates" || str == "ice skates") {
    thing = clone_object("players/softly/winter/skates.c");
    price=50;
    iname="ice skates";
  }
  else{
    write("Mr. Bryant says: I'm afraid I don't have that.\n"+
          "You can read the sign to see what I can offer you.\n");
    return 1;
  }

/* Enough money? */
  if(this_player()->query_money() <price) {
    write("Mr. Bryant says quietly: It seems you can't afford that.\n");
    return 1;
  }          

/* Can player carry it ? */

  if(!this_player()->add_weight(thing->query_weight())) {
    write("Mr. Bryant says: You can't carry that much.\n");
    destruct(thing);
    return 1; 
  } 
         
/* Then sell it to 'em */
  this_player()->add_money(-(price));
  move_object(thing,this_player());
  write("You bought " + iname + " for " + price + " coins.\n");
  say(capitalize(this_player()->query_real_name()) + " bought " + iname + ".\n");
  return 1;
}

cmdSouth()
{
    write("Mr. Bryant steps forward and says: May I help you?\n");
    return 1;
}

status cmd_read(string str) {
  if(!str)
    return (notify_fail("Read what?\n"), 0);
  if(str == "sign" || str == "the sign")
    return (long("sign"), 1);
  else
    return (notify_fail("You may only read the sign.\n"), 0);
}
