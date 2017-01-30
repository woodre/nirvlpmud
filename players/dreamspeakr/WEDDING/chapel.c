#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/WEDDING/"

inherit "room/room";

reset(arg) {
  if(arg) return;
     move_object(clone_object("/players/dreamspeakr/WEDDING/NPC/hera.c"), this_object());
set_light(1);

short_desc = HIR+"Chapel of Love"+NORM;
long_desc =
    "\n"+
    "     Lush red carpet cushions the floor through the center \n"+
    "isle between the pews in this large chapel.  At the end of \n"+
    "the isle, high above a marble podium, a pair of golden cherubs \n"+
    "hang upon the wall.  The chapel is filled with the sound of \n"+
    "a harp playing in the background.  Overflowing with rose \n"+
    "bouquets, this chapel appears to be ready for the celebration \n"+
    "of love.  \n"
;

items = ({
    "carpet","Thick carpet lay underfoot making it a very cozy place",
    "floor","Covered in carpet decorated with small golden cherubs",
    "isle","A long carpeted pathway through the center of the chapel",
    "pews","Heavy marble pews covered in plush red cushions, man \n"+
           "they look comfortable",
    "chapel","Filled with flowers it appears there is a celebration\n"+
           "about to begin",
    "podium","A large marble podium where hera stands to perform her\n"+
           "ceremony",
    "cherubs","Two cherubs that appear to be made of solid gold",
    "wall","Made of marble, reflections of the candles flickering in \n"+
           "the background",
    "harp","A golden harp sits in the corner.  It appears to be \n"+
           "playing all by itself!",
    "bouquets","The smell of these rose bouquets fill the room",
});

dest_dir = ({
    PATH+"garden.c","leave",
});

}

query_no_fight() { return 1; }

realm() { return "NM"; }
