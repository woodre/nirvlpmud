#define tp this_player()
#define tpn this_player()->query_name()
#define TO this_object()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
int cln;  /* sign  0-dirty, 1-clean  */
int rip;
int ww;

reset(arg) {
ww = 1;
if(!present("questman")) {
  move_object(clone_object("players/eurale/Fiend/NPC/mess38.c"),TO); }
cln = 0;
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  You stand at the end of a wooden bridge which allows you to\n"+
	"cross over a very deep ravine.  It appears that this ravine \n"+
	"was dug as a barrier to prevent whatever was on this side from\n"+
	"escaping back to the main part of Fiendsville.  The foliage is\n"+
	"almost tropical here with huge ferns and tall palm trees.\n"+
	"Something just off this narrow path that runs north and south\n"+
	"has been completely overgrown with moss and creeping vines.\n"+
	"There are some very large indentations in the ground following\n"+
	"the path.\n";

items = ({
	"bridge","A narrow wooden bridge spanning the ravine",
	"ravine","A deep, vertical walled gash cut into the earth",
	"ferns","A large, leafy plant with glossy leaves",
	"trees","Large Royal palm trees with rock-hard trunks",
	"indentations","These look like HUGE animal tracks",
	"sign","You might try to read it",
	"moss","A lush thick covering, maybe you should search",
	"vines","Tangled and thick, maybe you should search",
	"well","A dark, stone well...",
});

dest_dir = ({
	"players/eurale/Fiend/mm39.c","north",
	"players/eurale/Fiend/mm40.c","south",
	"players/eurale/Fiend/mm30.c","cross",
});

}
init() {
  ::init();
  add_action("search","search");
  add_action("clean","clean");
  add_action("read","read");
  add_action("wish","wish");
  tp->set_fight_area();
}

search() {
  write("You move the vines and moss aside to discover a small stone\n");
  write("well with a crusty, dirty sign attached.\n");
  say(tpn+" searches through the moss and vines.....\n");
  return 1; }

clean(str) {
  if(!str) { write("What are you trying to clean?\n"); return 1; }
  if(str == "sign" && cln == 1) {
    write("Someone has already cleaned the sign off.\n"); return 1; }
  if(str == "sign" && cln == 0) {
    write("You scrub away at the crusty dirt and clean off the sign.\n");
    say(tpn+" seems to be doing something....\n");
    cln = 1;
    return 1; }
}

read(str) {
if(!str) { write("What would you like to read?\n"); return 1; }
if(str == "sign" && cln == 0) {
  write("You try to read the sign but there's just too much dirt.\n");
  write("You really need to clean it off to be able to read it.\n");
  return 1; }
if(str == "sign" && cln == 1) {
  write("The worn and dirty old sign says: Wishing Well - 5 coins\n");
  return 1; }
}

wish(str) {
rip = (115+random(10));
if(!str) {
  write("You need to think of a wish and type 'wish well'.\n"); return 1; }
if(str == "well") {
  write("A whispering voice from down in the well says......\n\n");
  write("A fool and his money are soon parted..... Wishing will not\n");
  write("get the job done... hard work is the answer.....\n\n");
  write("And with a high-pitched laugh the voice fades....\n");
  this_player()->add_money(-rip);
  return 1; }
}
