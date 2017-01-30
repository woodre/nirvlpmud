#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "     Floating high above Nirvana, this magnificent city bursts\n"+
    "with activity.  A golden cobblestone pathway leads its way around \n"+
    "many shops and tall buildings.  Soft cloud formations drift as far\n"+
    "as the eye can see.  A small group of children sit on the corner \n"+
    "playing jacks while their parents do their shopping.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c103.c","north",
    PATH+"c108.c","northeast",
    PATH+"c117.c","northwest",
    PATH+"entrance.c","south",
});

}
