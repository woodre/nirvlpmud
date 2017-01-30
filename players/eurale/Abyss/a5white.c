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
  write("Snarling, the dragon the color of new fallen snow springs to\n"+
	"life.  It's gelatinus eyes would appear to be sightless but\n"+
 	"there's no mistaking it's deadly fangs.  The head, without\n"+
	"seeming to know exactly where you stand speaks, 'You must\n"+
	"have a message for me in order for me to stand aside... what\n"+
	"is it?\n\n"+
	"Message: ");
  input_to("check_white",0);  /* 0 echoes, 1 does not  */
  return 1; }
}

check_white(ans) {
if(ans == "from this world to the next my voice cries out for life") {
  write("\nThe sightless white head smiles and resumes its place..\n\n");
  tp->move_player("blink#players/eurale/Abyss/a5black.c");
  return 1; }
else {
  write("\nThe dragons hisses, 'You have failed!'  It opens its mouth\n"+
	"and grabs you roughly and flys upward into the darkness..\n\n\n\n\n\n"+
	"and then it spits you out through the portal..\n");
  tp->move_player("walking#players/eurale/Abyss/entry2.c");
  return 1; }
}
