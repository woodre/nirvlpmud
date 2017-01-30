#include "defs.h"

inherit "/players/feldegast/std/generic_pub.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("p'lila"))
    move_object(clone_object(MON_PATH+"plila.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=MAG+"The Shady Place"+NORM;
  long_desc=
"  This is a cool place to hide from the desert heat.  Although it is\n\
somewhat dark in here, the proprietor has kept the place clean and\n\
neat anyway.  A few p'kalians sit at several benches scattered around\n\
the common room, hunched together in low conversation.  Several female\n\
p'kalians move among the tables carrying trays.  At the back of the\n\
bar is a curtained doorway leading into the kitchen.  Next to the door\n\
is a chalkboard with a menu of items.\n";
  items=({
    "p'kalians","The p'kalians glance at you out of the corner of their eyes.\n"+
                "Apparently they aren't used to strangers",
    "benches","The benches are made out of sandstone, as wood is too hard\n"+
              "to find here",
    "doorway","It leads into the kitchen",
    "chalkboard","It is in a script you understand.  You could probably read it",
    "board","It is in a script you understand.  You could probably read it",
    "menu","It is in a script you understand.  You could probably read it",
  });
  dest_dir=({
    PATH+"pwell.c","northwest",
    "nowhere","east",
  });
  add_item("Camel piss",({ "piss" }),
           "You order some camel's piss, but still you wonder: What's REALLY in this?\n",
           " orders a glass of camel's piss.\n",
           300,30,14,"soak");
  add_item("Water",({ "water" }),
           "You suspect this water was diluted with beer, but you decide\nnot to comment.\n",
           " orders a glass of water.\n",
           360,30,12,"soak");
  add_item("Goat milk",({ "milk", "goat milk" }),
           "You order goat milk.  Some of the p'kalians snicker into their qaz.\n",
           " orders milk.\n",
           640,40,8,"soak");
  add_item("Qaz",({ "qaz" }),           
           "Much to your surprise, you find that qaz is fermented goat's milk.\n"+
           "That must explain why it has so much kick.\n",
           " orders some qaz.\n",
           350,35,14,"intox");
  add_item("Rum",({ "rum" }),
           "This is quite possibly the worst rum you've ever had in your life,\n"+
           "with the possible exception of the stuff they sell at the coliseum.\n",
           " orders some rum.\n",
           450,45,14,"intox");
  add_item("Queensblood",({ "queensblood", "blood" }),
           "You feel a strange thrill in your veins after you've choked down\n"+
           "the strange mixture of myrmidar blood and fermented cactus juice.\n",
           " orders queensblood.\n",
           600,50,12,"intox");
  add_item("Pita bread",({ "pita", "bread" }),
           "The warm pita bread doesn't taste great, but at least it is filling.\n",
           " orders some pita bread.\n",
           420,35,12,"stuff");
  add_item("Cactus chips",({ "chips" }),
           "The cactus chips are sweet, sticky, and occasionally prickly.\n",
           " orders some cactus chips.\n",
           520,40,11,"stuff");
  add_item("Qadlfik",({ "qadlfik" }),
           "Having no idea what qadlfik is, you order it out of curiosity.  Even\n"+
           "after you've eaten it, you still have no idea what it is, but you now\n"+
           "know it is "+GRN+"poisonous"+NORM+" to non-p'kalians.\n",
           " orders qadlfik and then looks sick.\n",
           800,-15,20,"stuff");
}

void init() {
  ::init();
  add_action("cmd_east","east");
  add_action("cmd_read","read");
}

int cmd_east(string str) {
  write("You decide not to disturb the cook.\n");
  return 1;
}

int cmd_read(string str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str!="board" &&
     str!="sign" &&
     str!="chalkboard" &&
     str!="menu") {
    notify_fail("Read what?\n");
    return 0;
  }
  cmd_list(0);
  return 1;
}
