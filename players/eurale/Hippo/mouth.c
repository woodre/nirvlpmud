inherit "room/room";
int i;

reset(arg) {
  if(arg) return;
set_light(1);
if(!present("tooth")) { for(i=0;i<2;i++) {
  move_object(clone_object("players/hippo/c/tooth.c"),this_object()); }}
if(!present("molar")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/molar.c"),this_object()); }}

short_desc = "An enormous mouth";

long_desc =
  "  A cold breeze from the one side is alternated by a warmer one coming from\n"+
  "the opposite direction.  Judging by the smell, the warmer breeze originates\n"+
  "from deep within the body.  Overhead is a large, dark hole bringing in the\n"+
  "cold air.  Underfoot is a large, red moving thing.\n";

items = ({
  "hole","The orafice would appear to lead to the nose holes",
  "thing","The tongue of Hippo",
});

dest_dir = ({
  "/room/jetty2","push",
  "/players/eurale/Hippo/throat","down",
});

}

init() {
  ::init();
  add_action("Smell","smell");
}

Smell(str) {
if(!str || str == "breeze") {
  write("It smells like digesting food and kind of rotten.\n");
  return 1; }
}
