inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(!present("Anne Lindsey",this_object()))
    move_object(clone_object(HMON+"anne"),this_object());
  if(arg) return;

  set_light(1);
  short_desc="A loft apartment";
  long_desc=
"You stand in what is undeniably a loft, but your immediate surroundings are\n"+
"so nice, it's hard to believe.  A plush carpet underfoot supports two chairs\n"+
"and a couch facing each other across a coffee table.  To the west, a large\n"+
"liquor cabinet sits between two windows, and a large set of shelves rests\n"+
"against the east wall.  Further to the south is a large bed, and to the\n"+
"north are the entrance and a kitchen.\n";

  items= ({
    "loft","Yes, it really is a loft, but the decor could almost fool you",
    "carpet","Fancy, good quality, and probably an antique",
    "couch","Black, and overstuffed, and though not an antique, high quality",
    "table","A long low table with some nice carvings on the legs.  A\n"+
            "chessboard sits atop it",
    "chessboard","It looks as though someone is in the middle of a game. A\n"+
                 "few pieces have been taken, but the sides look evenly\n"+
                 "matched.  A knight removed from the board catches your eye",
    "knight","A black knight...  you think that if you "+BLD("pause")+"d,\n"+
             "You could remember something about a black knight...",
    "cabinet","The cabinet is well stocked, and both it and its stock are\n"+
              "well aged",
    "windows","Framed glass, with curtains, overlooking an alley",
    "shelves","A few old books, and countless other items, on simple wood\n"+
              "shelves, carefully arranged but it no order you can decipher",
    "bed","A king sized bed occupies the north end of the loft",
    "kitchen","It looks to be clean and well-stocked",
    "entrance","An out of order elevator and a door",
  });
  dest_dir= ({
    HROOM+"lbed","south",
    HROOM+"loftent","north",
  });
}

void init() {
  ::init();
  add_action("cmd_pause","pause");
}

status cmd_pause() {
  write("You pause to think about black knights, and find yourself elsewhere!\n");
  TP->move_player("into a memory#"+HROOM+"battlefield");
  return 1;
}
