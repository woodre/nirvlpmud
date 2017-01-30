#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
int have_read;

reset(arg) {
  if(arg) return;
set_light(1);
have_read = 0;

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You follow the path and it gets rockier and rockier... looks like\n"+
  "it used to be a river long ago.  The sides have gotten higher and\n"+
  "higher until they are over your head.  As you stand at the end of\n"+
  "the hollowed out ravine, you notice an opening in one side.  Oddly\n"+
  "enough, there is a small "+BOLD+"sign"+NORM+" stuck into the "+
      "dirt beside the dark\n"+
  "opening.\n";

items = ({
  "sides","Dirt and stone walls, cut away by some natural force",
  "opening","A small cave, large enough to enter",
  "sign","A small wooden sign with lettering you SHOULD read",
});

dest_dir = ({
  "players/eurale/Glade/eg20.c","north",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("read","read");
  add_action("enter","enter");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") {
  write("The roughly lettered sign reads:\n\n"+BOLD+
	"	Enchanted Glade Cave of Pleasure\n\n"+
	"  Entering the cave attests and agrees to the following:\n"+
	"	* You are 18 years old or older\n"+
	"	* Sexually explicit material is legal where you are\n"+
	"	* You are not offended by explicit sexual content\n"+
	"	* You will hold no one associated with this game\n"+
	"            liable for the content\n"+
	"	* You enter freely and voluntarily\n"+
	"	* You have read and agree to the above"+NORM+"\n\n");
	have_read = 1;
  return 1; }
}

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "cave" || str == "opening") {
  if(have_read == 0) {
    write("You better take a look at the sign first!\n");
    return 1; }
  else {
    tp->move_player("into the cave#players/eurale/Glade/eg23.c");
    have_read = 0;
    return 1; }
return 1; }
}
