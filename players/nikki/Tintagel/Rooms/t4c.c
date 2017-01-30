#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIW+"Quaisoir's Chamber"+NORM;
long_desc = HIW+
 "   Even from the inside of this upper level room the enormity of the tower\n"+
 "is overwhelming.  The torches on the walls blaze brightly.  The colour\n"+
 "illuminates the chamber from the flecks within the stone walls, causing an\n"+
 "euphoric effect to linger with in the room.  The air is painfully cold as\n"+
 "it drifts around close to the floor in a thick mist.  A full length mirror\n"+
 "of immense proportions hangs on the wall across from the entrance.  In the\n"+
 "center of the room is a large bed covered in white gauze like curtains and\n"+
 "alabaster coloured, silk sheets.\n"+NORM;

items = ({
  "room",HIW+"The room is very beautiful with the rainbow effect from the lit torches"+NORM,
  "chamber",HIW+"Although it is very large it has a feeling of intimacy imminating from it"+NORM,
  "walls",HIW+"The walls swirl with a prism of colours"+NORM,
  "center",WHT+"A large bed sits in the center with tousled pillows and sheets laying across it"+NORM,
  "entrance","The entrance allows access into this enormous room",
  "torches","The torches burn brightly along the walls",
  "flecks","The flecks are a granite like substance that put off a prism of\n"+
           "colour from the moisture",
  "mist",HIW+"The white mist sways around the room gently",
  "mirror","The mirror looks like silver liquid encased within a platinum frame",
  "frame","The frame is platinum which is intricately braided into celtic love knots",
  "curtains",HIW+"The curtains are made from a shimmery gauze material",
  "sheets",HIW+"The sheets are strewn across the bed in disarray",
  "pillows",HIW+"The pillows are covered in white silk cases",
  "bed",HIW+"The bed seems to be floating ontop of the cold mist",

});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/t4b.c", "down",
   
});
}}

init() {
  ::init();
  add_action("feel","feel");
}

feel(str) {
  if(str != "walls") {
     write("What are you trying to feel?\n");
     return 1;
      }    
  if(str == "walls") {
     write("\nThey are very cold to the touch.\n\n");
     return 1;
     }
  }

realm() { return "NT"; }