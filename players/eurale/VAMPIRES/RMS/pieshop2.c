#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if (arg) return;
if(!present("wilma")) {
  move_object(clone_object("/players/eurale/VAMPIRES/NPC/wilma2"),
  this_object()); }
set_light(1);

short_desc = "Wilma's Homemade Heals Shop";
long_desc =
  "The air is filled with the wonderful aromas of fresh baked pies.\n"+
  "A long display case follows the walls in an L-shaped fashion and\n"+
  "it is filled with delicious looking pies, hot out of the oven. A\n"+
  "neatly lettered sign hangs on the wall behind the case.\n";

items = ({
  "case","A wooden case with a glass front displaying the pies made\n"+
         "here in the pie shop",
  "pies","Beautiful, juicy pies with light brown crusts",
  "sign","A beatiful wooden sign with ornate edges carved to look\n"+
         "like the intertwining branches of a vine.  It looks readable",
    });

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/souvenir_shop","south",
});

}

init() {
  ::init();
  add_action("read_sign","read");
  add_action("Smell","smell");
}

read_sign(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") { write(
  "********************************************************\n"+
  "*                 Wilma's Homemade Pies                *\n"+
  "*                                                      *\n"+
  "*  All our pies are made fresh daily from the finest   *\n"+
  "*  ingredients. We guarantee their freshness and qual- *\n"+
  "*  ity to be of the highest standards.                 *\n"+
  "*                                                      *\n"+
  "*  Pie types:  apple       cherry       blueberry      *\n"+
  "*              chocolate cream      lemon custard      *\n"+
  "*                                                      *\n"+
  "*                Pie Cost......... 100 coins           *\n"+
  "*                                                      *\n"+
  "*         To order type:  'order <pie type> pie'       *\n"+
  "*                                                      *\n"+
  "********************************************************\n"+
  "\n");
  return 1; }
else {
  write("You look around but fail to find a "+str+" to read.\n");
  return 1; }
}

Smell() {
  write("You inhale deeply and close your eyes. The hot baked pies\n"+
        "smell like a mixture of fruits...it makes your mouth water.\n");
return 1;
}
