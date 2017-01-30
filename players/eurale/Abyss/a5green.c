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
  write("The largest and most colorful of all the heads turns to\n"+
	"face you.  The light glistens off the emerald green skin of\n"+
	"this fearsome looking creature.  As the big head peers dir-\n"+
	"rectly into your eyes, you notice that the pupils of its\n"+
	"eyes are shaped like hourglasses.  With a wisp of steam es-\n"+
	"caping its nostrils, the dragon slowly murmurs.... 'Should\n"+
	"you know what I want to hear, I will let you pass and bow\n"+
	"before the lady Despoina, my Abyss Diva.  Once you enter her\n"+
	"hallowed hall, know full well that you may never come back\n"+
	"out alive.  Now, what is it I want to hear from you?'\n\n"+
	"Answer: ");
  input_to("check_green",0);  /* 0 echoes, 1 does not  */
  return 1; }
}

check_green(ans) {
if(ans == "weep ye all with me as the gods are cast down to their fate") {
  write("\nYou hear a faint 'click'.  The dragon murmurs 'well done,\n"+
	"now enter and bow before the mighty Despoina'..... and with\n"+
	"that a silent force ushers you through the open door into\n"+
	"the Diva's chambers...\n\n");
  tp->move_player("blink#players/eurale/Abyss/q_room.c");
  return 1; }
else {
  write("\nThe dragons hisses, 'You have failed!'  It opens its mouth\n"+
	"and grabs you roughly and flys upward into the darkness..\n\n\n\n\n\n"+
	"and then it throws you out through the portal..\n");
  tp->move_player("walking#players/eurale/Abyss/entry2.c");
  return 1; }
}
