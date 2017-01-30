#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("takhisis")) {
move_object(clone_object("players/eurale/Abyss/despoina.c"),this_object()); }
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  You stand in a space of pearlescent darkness.  A pleasant aroma\n"+
  "greets your nostrils.  Other than that, the only thing you see,\n"+
  "feel or touch here is the most intense fear of your life.  Quickly\n"+
  "looking back you see that the doorway has disappeared and there is\n"+
  "no means of escape.  You've entered Despoina's personal space and\n"+
  "you realize that the only way out will be a fight to the death\n"+
  "of one of you.....\n";

items = ({
});

dest_dir = ({
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("ascend","ascend");
  add_action("smell","smell");
  add_action("search","search");
}

ascend() {
if(!present("despoina")) {
  tp->move_player("darkness#players/eurale/Abyss/a5red.c");
  return 1; }
else {
  write("The power of the Abyss Diva prevents you from leaving!\n");
  return 1; }
}

smell(str) {
if(!str || str == "aroma") {
  write("The crisp, cool, clean air like right after a springtime rain.\n");
  return 1; }
}

search() {
if(present("takhisis")) {
  write("The GLARE of Despoina, the Abyss Diva freezes you!\n");
  return 1; }
else {
  write("You grope around in the darkness and discover a narrow, well-\n"+
	"hidden stairway that you could probably 'ascend'.\n");
  return 1; }
}
