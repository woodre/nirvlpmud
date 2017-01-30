#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";
int P;  /*  to allow only 1 player into the abyss  */

reset(arg) {
  P = 0;
  if(arg) return;
set_light(1);

short_desc = "Dark dusty closet";
long_desc =
  "  You stand behind the hanging clothes and find yourself before\n"+
  "a large shimmering oval portal that takes up most of the rear wall\n"+
  "of the closet.  The green-grey surface reflects the outside light\n"+
  "much like the tinsel on a Christmas tree.  Someone has tacked an\n"+
  "old faded note to the wall beside the portal.  It almost sounds as\n"+
  "if you can hear faint screaming coming from the portal..\n";

items = ({
  "portal","A shimmering oval portal, too dark to see into",
  "note","A faded old note with scribbling.  Maybe you could read it",
});

dest_dir = ({
	"players/eurale/Abyss/entry1.c","back",
});

}

init() {
  ::init();
  add_action("read","read");
  add_action("enter","enter");
}

read(str) {
if(!str) { write("What should we read?\n"); return 1; }
if(str == "note") {
  write("The note is written in long hand.  It was done by a very un-\n"+
	"steady hand and reads........\n\n"+
	"Be it known....\n"+
	"  Who-so-ever shall enter this portal will have entered the\n"+
  "abyss ruled by Despoina, the Abyss Diva and her Guardians.  You\n"+
	"must face them alone with no chance of escape but to return\n"+
	"through this portal....  No man, woman or child should ever\n"+
	"have to endure what I've seen......\n"+
	"          The signature is unreadable\n");
  say(tpn+" studies the note on the wall.\n");
  return 1; }
}

enter(str) {
if(!str) { write("What are you trying to enter?\n"); return 1; }
if(str == "portal" && P != 1) {
  tp->move_player("steps into the portal#players/eurale/Abyss/a1.c");
  P = 1;
  return 1; }
else {
  write("A voice from the dark behind the portal whispers, 'One has\n"+
	"entered before you and thus the portal is closed...\n");
  return 1; }
}
