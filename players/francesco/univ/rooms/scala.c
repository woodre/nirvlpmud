#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;


set_light(1);

short_desc = "The main entrance stair" ;
long_desc =
  "   The building looms immediately in front of you.  A wide set\n"+
  "of stone steps leads in.  Two palm trees grow on either side of \n"+
  "the stair beneath your feet.  There is a plaque hanging on the\n"+
  "wall just to the right of the double gate.\n";

items = ({
   "building","The main building of the University is a three flats one,\n"+
              "of a pale brown color",
   "stair","The entrance stair of the University has been walked in the\n"+
           "past by several people: you have the urge to ponder about\n"+
           "the students who graduated here and then became great\n"+
           "professionals or important executives, or even famous\n"+
           "scientists",
  "steps","Wide granite steps, exceeding 15 feet, that have been worn\n"+
          "smooth by the shoes of countless numbers of students who\n"+
          "ascended and descended them in their pursuit of higher\n"+
          "education",
  "plaque","A bronze plaque with raised lettering for all who enter "+
           "to read",
  "trees","They are about 30 feet tall, with wide elongated leaves",
  "gate","The gate is made by diagonally crossed steel bars",
});

dest_dir = ({
  "/players/francesco/univ/rooms/main_entrance.c","ascend",
  "/players/francesco/univ/rooms/outside.c","exit",
});

}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "plaque") {
  write("The plaque reads:\n"+
        "Those who enter here choose to expand their minds,\n"+
        "   knowing that education is the true strength.\n");
  return 1; }
}
