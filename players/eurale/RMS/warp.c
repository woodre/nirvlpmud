/*  Eurale's time warp  */

inherit "/room/room";
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
if(!present("drucilla")) {
move_object(clone_object("players/eurale/NPC/drucilla"),TO); }
set_light(1);

short_desc = BOLD+"Time Warp"+NORM;
long_desc =
	"  You have stepped into a tear in time.  This quirk of nature \n"+
	"allows you to step off into other places from other times with \n"+
	"hardly a blink of your eye...  So step off, but travel wisely \n"+
	"my friend.... so you can return to travel again.  Oh, you can \n"+
	"also find out a little bit about each area by typing [info].\n"+
	"\n"+BOLD+"REALM EXITS:"+NORM+"\n"+
	HIY+"  gulch"+
	HIR+"  park"+
	HIC+"  phantasm"+
	HIM+"  fiendsville"+
	BOLD+"  keep"+
   HIK+"  c"+HIY+"h"+HIK+"e"+HIY+"s"+HIK+"s"+
	HIG+"  glade\n"+
	NORM+
	"\n";

items = ({
});

dest_dir = ({
  "/players/eurale/RMS/titles","north",
  "players/eurale/Lab/l1","down",
	"/room/forest10.c","out",
});

}

realm() { return "NM"; }

init() {
  ::init();
  add_action("info","info");
  add_action("gulch","gulch");
  add_action("park","park");
  add_action("phantasm","phantasm");
  add_action("fiendsville","fiendsville");
  add_action("keep","keep");
  add_action("glade","glade");
  add_action("Chess","chess");
}

gulch() {
  TP->move_player("Drygulch#players/eurale/Drygulch/dgs4.c");
return 1; }

park() {
  TP->move_player("Jurassic Park#players/eurale/Park/jp98.c");
return 1; }

phantasm() {
  TP->move_player("Phantasm#players/eurale/Dis/rooms/greet.c");
return 1; }

fiendsville() {
  TP->move_player("Fiendsville#players/eurale/Fiend/mm1.c");
return 1; }

keep() {
  TP->move_player("Keep#players/eurale/Keep/k1.c");
return 1; }

glade() {
  TP->move_player("glade#players/eurale/Glade/eg1.c");
return 1; }

Chess() {
  TP->move_player("chess board#players/eurale/Chess/d4.c");
  return 1; }

info(str) {
if(!str) {
  write(BOLD+"REALM INFORMATION:"+NORM);
  write("\nHere's the way to see the information about any given area.\n"+
      "Simply use 'info <area>'.  For example, 'info park'.  The\n"+
      "areas you can get information about are titled:\n"+
	BOLD+
    "abyss   deep space   fiendsville   glade   gulch\n"+
    "keep   labyrinth   park   phantasm\n"+
	NORM+
      "\n");
  return 1; }
if(str == "chess") {
  write(HIY+"Chessboard\n"+NORM+
  "  The classic battle between good and evil chess pieces.  They are\n"+
  "situated around the board.  Be warned that if you attack a piece of\n"+
  "either color, the rest of the pieces of that color will attack you on\n"+
  "sight.  If you are not familiar with the power of individual chess\n"+
  "pieces, it would behoove you to find out.  Warning:  Survival skills\n"+
  "may be tested here.\n");
  return 1; }
if(str == "labyrinth") {
  write(BOLD+"Labryinth"+NORM+"\n"+
  "Large underground cavern for high level players with better than\n"+
  "average exploration skills.\n\n");
  return 1; }
if(str == "gulch") {
  write("\n"+HIY+"Drygulch"+NORM+"\n"+
	"  Old west theme with lots of kills.  There's something there\n"+
	"for all levels, just look around.\n\n");
  return 1; }
if(str == "park") {
  write("\n"+HIR+"Jurassic Park:"+NORM+"\n"+
	"  A dangerous area for high level players with good skills.\n"+
	"WARNING!!  Dinosaurs are dangerous, be careful!\n\n");
  return 1; }
if(str == "phantasm") {
  write("\n"+HIC+"Phantasm:"+NORM+"\n"+
	"  A trip through your childhood fantasies and a chance to\n"+
	"get even with all those fairy tale characters.  There is\n"+
	"lots here for mid to high level players.\n\n");
  return 1; }
if(str == "fiendsville") {
  write("\n"+HIM+"Fiendsville:"+NORM+"\n"+
	"  Meet those classic monsters that have been a part of horror\n"+
	"movie history.  This high level area supplies good exp and\n"+
	"interesting loot but is very high vulnerability.\n\n");
  return 1; }
if(str == "keep") {
  write("\n"+BOLD+"Keep:"+NORM+"\n"+
	"  Bountiful monsters of many kinds.  Parties of mid level\n"+
	"players and high level players should enjoy exploring the\n"+
	"many nooks and crannies of this huge underground fortress.\n\n");
  return 1; }
if(str == "abyss") {
  write("\n"+BOLD+"Abyss:"+NORM+"\n"+
	"  Rumor has it that there is a well hidden portal that will\n"+
	"allow a single player to descend into the depths of the\n"+
	"abyss to meet its ruler.  The trip is fraught with danger\n"+
	"and returning is NOT an option once undertaken.\n\n");
  return 1; }
if(str == "glade") {
  write("\n"+HIG+"Enchanted Glade:"+NORM+"\n"+
	"  An interesting place to visit.  Mid to high level players\n"+
	"should enjoy this shady escape.  Unique items found through-\n"+
	"out Nirvana may be bartered away and it's even been rumored\n"+
	"that a player could wet his/her sexual appetite here if they\n"+
	"were so inclined (not confirmed).\n\n");
  return 1; }
if(str == "deep space") {
  write("\n"+BOLD+"Deep Space:"+NORM+"\n"+
   "  In the outer galaxy, there exists a place with uncommon\n"+
   "monsters.  Only by traveling in the pod found crashed some-\n"+
   "where in drygulch can one hope to find this place.  Take a\n"+
   "snack, the journey is a long one.\n");
  return 1; }
return 1;
}
