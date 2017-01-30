#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("shovel")) {
  move_object(clone_object("/players/pestilence/blue/mob/shovel.c"),
        this_object()); }
if (!present("pail")) {
  move_object(clone_object("/players/pestilence/blue/mob/pail.c"),
        this_object()); }

short_desc = "backyard";
long_desc =
  "    This is the big back yard where Blue and Steve come when they want to\n"+
  "play.  There is a swing set with a sliding board and a sandbox to play\n"+
  "with.  There is a large open space to play in and toys are scattered\n"+
  "all around.\n";
set_light(1);

items = ({
  "swing","A small white swing to sit in and swing",
  "swing set","A small white swing to sit in and swing",
  "set","A small white swing to sit in and swing",
  "board","A small metal slide, that is about six feet high",
  "sliding board","A small metal slide, that is about six feet high",
  "space","A big open area in the lawn, where the toys are scattered and there is room to play",
  "toys","Toy cars, trucks and stuffed animals are all around",
  "sandbox","A square sandbox filled with sand and toys",
  "yard","A long yard covered with grass, a slide and some toys",
  "grass","Plush green grass cover the yard",
  "sand","White granular sand that fills the sandbox",
  "slide","A small metal slide, that is about six feet high",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/kitchen.c","south",
});

}
