/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIB+"Bakery"+NORM;
    long_desc =
    "This is the "+HIB+"Bakery"+NORM+" .  This is where all the tasy\n"+
    "treats and bread are kept.  There are cinnamon rolls here, loafs\n"+
    "of all sorts of breads, little cupcakes and a huge display of\n"+
    "expensive, not so tasty cakes.   There are doughnuts here sold\n"+
    "individually or by the dozen.  Feel free to grab a coffee if you\n"+
    "would like.  Back to the west are the checkstands and to the\n"+
    "north is aisle 12.\n";

    items =
    ({
    "coffee",
    "Espresso, coffee, latte, it's all the same drug",
    "doughnut",
    "These are yummy QFC doughnuts. You can get them"+
    "individually or by the dozen",
    "bread",
    "There is white bread, wheat bread, that bread with the grain stuff"+
    "in it.  There are ready to bake breads, there are long loafs"+
    "of bread, there is so much bread, you don't know what to"+
    "do with yourself",
    "cake",
    "The cakes look beautiful and are rather expensive",
    "cinnamon rolls",
    "Mmmmmmm, cinnamon rolls",
    "cupcakes",
    "Wonderful cupcakes, they look absolutely delicious",
    "aisle",
    "Looking down the aisle you see a young man throwing dairy onto"+
    "the shelf. The aisle is crowded with customers",
    });
    dest_dir =
    ({
    RPATH+"checkstand3",        "west",
    RPATH+"aisle12",        "north",
    });

    move_object(clone_object("players/humble/area1/mobs/amy.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/andrea.c"), this_object());
  }
}

