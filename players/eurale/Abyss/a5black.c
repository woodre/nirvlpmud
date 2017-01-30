#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";
object player;
string ans;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Abyss";
long_desc =
  "  You step out of the darkness into the only lighted area you've seen\n"+
  "so far.  Before you, on a raised dais, stands a huge oval door.  It\n"+
  "is ornamented and guarded by the heads of five dragons.  Their sin-\n"+
  "uous necks snaking up from the floor, the five heads faced inward,\n"+
  "five mouths open, screaming silent tribute to their Diva.\n";

items = ({
  "door","A polished black door of unknown substance that leads to the\n"+
	"Abyss Diva if you can but open it",
  "dragons","Five fearsome dragon heads of various colors",
  "heads","Five fearsome dragon heads of various colors",
});

dest_dir = ({
	"players/eurale/Abyss/a4.c","up",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("open","open");
}

open(str) {
if(!str) { write("Open what?\n"); return 1; }
if(str == "door") {
  write("The blackest dragon you've ever seen slowly opens its eyes.\n"+
	"It squints as it looks around the room.  'I assume you have\n"+
	"disturbed my sleep for a reason.  Let's hope you have what\n"+
	"I want to hear or you shall be eternally sorry', rasps the\n"+
	"ebony dragon....\n\n"+
	"Answer: ");
  input_to("check_black",0);  /* 0 echoes, 1 does not  */
  return 1; }
}

check_black(ans) {
if(ans == "from darkness to darkness my voice echoes in the abyss") {
  write("\nThe eyelids slowly close as the black dragon resumes his"+
	" slumber..\n");
  tp->move_player("blink#players/eurale/Abyss/a5green.c");
  return 1; }
else {
  write("\nThe dragons hisses, 'You have failed!'  It opens its mouth\n"+
	"and grabs you roughly and flys upward into the darkness..\n\n\n\n\n\n"+
	"and then it roughly shoves you out through the portal..\n");
  tp->move_player("walking#players/eurale/Abyss/entry2.c");
  return 1; }
}
