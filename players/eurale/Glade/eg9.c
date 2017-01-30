#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
int RC;

reset(arg) {
  if(arg) return;
set_light(1);
RC = 1;

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You stand beside a large rock, partially buried in the dirt.  It\n"+
  "is at least 28 feet in circumference.  The grass has grown up around\n"+
  "it and there are wildflowers, protected from the elements, growing\n"+
  "in its shade around the base.  You can see the trees off to the\n"+
  "west.\n";

items = ({
  "rock","A huge boulder, with streaks of color running through it",
  "grass","Sharp-edged grass, tall and green",
  "flowers","White, delicate trillium",
  "wildflowers","Small blue and white flowers",
  "trees","A stand of old hardwoods",
  "cracks","Very even, well-hidden cracks indicating some sort of\n"+
	"access or entry if you could pry it open",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
  add_action("pry","pry");
}

search(str) {
if(!str) {
  write("You search the area and find nothing special.\n");
  return 1; }
if(str == "rock") {
  write("You walk around the huge rock looking at it very carefully\n"+
	"and discover some interesting cracks.\n");
  return 1; }
}

north() {
  write("The ground feels soft and mushy and the grass is too thick\n"+
	"to make passage that way worth it.\n");
  return 1; }
south() {
  tp->move_player("into the grass#players/eurale/Glade/eg8.c");
  return 1; }
east() {
  tp->move_player("into the grass#players/eurale/Glade/eg10.c");
  return 1; }
west() {
  tp->move_player("into the grass#players/eurale/Glade/eg2.c");
  return 1; }

pry(str) {
if(!str) { write("Pry what?\n"); return 1; }
if(!present("metal tool",tp)) {
  write("You'll need something pretty sturdy for this job.\n");
  return 1; }
if(present("metal tool",tp) && str == "rock") {
  write("You wedge your metal tool into the crack and pry very hard .\n"+
	"All of a sudden...............\n\n");
  tp->move_player("into the rock#players/eurale/Glade/rock.c");
  call_out("rock",10);
  return 1; }
else {
  write("You pry away at the "+str+" with no success.\n");
  return 1; }
}

rock() {
object ob;
if(RC == 1) {
  ob = clone_object("players/eurale/Glade/NPC/crusher");
  move_object(ob,"players/eurale/Glade/rock.c");
  tell_room(environment(find_living("rock crusher")),
    "\n\nThe stone door quickly opens and shuts and a huge, gray,\n"+
    "stone-like figure enters.......\n\n");
  RC = 0;
  return 1; }
}
