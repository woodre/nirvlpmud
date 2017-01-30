#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  
if(!present("wizard",this_object()))
   move_object(clone_object("/players/wocket/turtleville/NPC/wizard.c"),this_object());

  if(arg) return;

  short_desc = HIG+"The Magus Tower"+NORM;
  long_desc = "   "+
              "  This is a circular room with stairs leading down.  There is a small\n"+
              "pedestal offset from the stairs.  Many potions and books line the shelves\n"+
              "along the walls.  Test tubes and viles fill cluttered space.  A fire burns\n"+
              "in a small nook of the room, with a dark kettle above it.  The air reaks\n"+
              "of some foul smelling odor.\n";

  set_light(1);
items = ({
    "pedestal","A 3 foot high pedegast with a slanted top for holding ancient books",
    "potions","They fume white steam lining the bookshelves.  They are\nmany different colors",
    "books","They are old and tattatered.  They line the bookshelves",
    "test tubes","They hold many different colored concoctions",
    "tubes","They are long and thin holding many different colored concoctions",
    "nook","A cut out of the wall with a passage up to let smoke out",
    "fire","It glows an errie green as it heats up the kettle",
    "kettle","It is a dark black with pruple fumes raising from it",
    "viles","Long thin tubes that hold many different colored concoctions",
    "stairs","They spiral lead down through the floor",
    "shelves","They are wooden and filled with potions and books",
    "bookshelves","They are wooden and filled with potions and books",
});
listens = ({
    "You hear soft chanting in the background.\nYou can't find a source",
 
});
smells = ({
    "default","You smell rotten eggs",
    "air","The room stinks of rotten eggs.  It seems to emminate from the kettle",
    "odor","It smells very similar to rotten eggs",
});

   dest_dir = ({
    PATH+"/tville_tower.c","down",
  });
}

