#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = "Closet";
long_desc =
  "    A closet where Steve stores some of his clothes.  There are five\n"+
  "dark green shirts with light green stripes.  Also this is where he\n"+
  "keeps all the articles of footwear he owns.  These include three pairs\n"+
 "of shoes, three pairs of sneakers, and his three favorite pairs of bunny\n"+
  "slippers.\n";
set_light(1);

items = ({
  "shirts","Five shirts that are dark green with light green stripes",
  "shoes","Three identical pairs of black shoes",
  "sneakers","Three identical pairs of Rebook 5000 sneakers",
  "bunny slippers","Three pair of pink slippers with bunny heads at the toe",
  "closet","You can just type look to see this",
  "slippers","Three pair of slippers with bunny heads at the toe",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/sroom.c","north",

});

}
