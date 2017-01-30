#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("mailbox")) {
  move_object(clone_object("/players/pestilence/blue/mob/mailbox.c"),
        this_object()); }
short_desc = ""+CYN+"Front lawn"+NORM+"";
long_desc =
  "    A large tree grows here.  Hanging from a lower branch of the tree is an\n"+
  "old tire swing.  In the higher branches sits a birdhouse.  Around the base\n"+
  "of the tree grows a bunch of wild flowers.  To the west leads back to the\n"+
  "walkway leading to Blue's and Steve's house.\n";

set_light(1);

items = ({
  "tree","A large apple tree",
  "tire","An old tire hanging from a tree often used as a swing",
  "branches","Some branches coming from the tree with a few apples on them",
  "flowers","Some pretty white and yellow flowers",
  "birdhouse","A small yellow birdhouse where a pair of bluejays live",
  "wild flowers","Some pretty white and yellow flowers",
  "tire swing","An old tire hanging from a tree often used as a swing",
  "swing","An old tire hanging from a tree often used as a swing",
  "branch","A branch coming from the tree with a few apples on it",
  "apples","Small green apples, that aren't quite ripe yet",
  "base","This is a large trunk of the tree surrounded with flowers",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/front.c","west",

});

}
