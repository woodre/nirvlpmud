#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("blue")) {
  move_object(clone_object("/players/pestilence/blue/mob/blue.c"),
        this_object()); }
short_desc = ""+CYN+"Blue's Special Place"+NORM+"";
long_desc =
  "    This is the spot where Blue goes to sit alone to think, read and make\n"+
  "books.  There is a bookshelf that acts as a divider between this\n"+
  "place and Blue's bedroom.  There is a small dark blue chair against the\n"+
  "wall where Blue likes to rest.  A desk sits in the middle of this space.\n"+
  "A few pictures adorn the wall to add character.\n";
set_light(1);

items = ({
  "bookshelf","A few books that Blue has made herself, you can't quite understand the writing",
  "divider","This is the bookshelf holding Blue's books",
  "wall","A wall painted light blue",
  "chair","A small dark blue chair just right for a dog",
  "desk","This is the desk Blue uses to make books, there seems to be an open 'book' on it",
"book","This is a picture book, opened to the page of a picture of Blue's school maybe you could 'skidoo' there",
"books","There are a few books, some made by blue herself.  All seem to be paper backs.",
  "pictures","There are two different pictures of dogs playing poker",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/broom.c","east",
});
}

init() {
  ::init();
  add_action("skidoo","skidoo");
}

skidoo() {
  TP->move_player("skidoo#/players/pestilence/blue/rooms/school.c");
  return 1; }
