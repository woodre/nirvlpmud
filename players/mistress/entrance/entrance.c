#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

object sign;

extra_init() {
  if (!present ("sign")) {sign = clone_object("players/mistress/closed/sign");
  transfer(sign,this_object());
  sign->set_long(" \n" +
    "Welcome to the library.\n" +
    "Just a little hint before you enter...  You may find it wise to bring in\n" +
    "your own light source (or buy one from the magic section in the lobby),  not\n" +
    "all the lights work in the rooms.  There is an aid station and a magic shop\n" +
    "in the lobby for your convenience.  The children's section is pretty much\n" +
    "designed for the less experienced.  The science fiction area is for the  \n" +
    "more adventurous.  Enjoy your visit. \n\n"); }
}

TWO_EXIT("players/mistress/entrance/ent1.c","north",
         "players/mistress/path/up.c","south",
   "Entrance",
   "\n" +
   "You pass under a great stone archway leading into the library.\n" +
   "It is difficult to discern the nature of the library from the outside\n" +
   "due the ancient designs.  It looks interesting enough,  though.\n",1)
