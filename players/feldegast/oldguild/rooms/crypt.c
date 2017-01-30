#include "defs.h"

inherit ROOM;

reset(arg){
  if(!present("irathus",this_object()))
    move_object(clone_object("/players/wocket/mages/npc/irathus.c"),this_object());

  if(arg) return;

  short_desc = BOLD+BLK+"Necromancer's Hall"+NORM;
  long_desc =
"  A pentagram, drawn on the stone floor with green, phosphorescent\n\
chalk and embellished with thin, spiraling designs takes up at least\n\
two thirds of this vaulted chamber.  Scented candles of red and black\n\
hue are placed at each of the design's intersections.  Outside of the\n\
circle, the paraphernalia of the necromancer, bones, skulls, fetishes,\n\
wax, candles, and spellbooks lie haphazardly on old cedar shelves and\n\
scarred workbenches.\n";
  set_light(1);
  items = ({
    "fetishes","A fetish is an item believed to be magical.  You see several\n"+
               "sitting around here",
    "pentagram","A pentagram, drawn on the stone floor with green, phosporescent\n"+
                "chalk and embellished with thin, spiraling designs takes up at least\n"+
                "two thirds of the chamber",
    "candles","Scented candles of red and black hue, placed at each of the\n"+
              "design's intersections",
    "paraphernalia","Bones, skulls, fetishes, wav, candles, and spellbooks",
    "bones","Bones from both animals and humanoids",
    "skulls","Human skulls lie with orc, troll, and animal skulls on one of the\n"+
             "cedar shelves, all equal in death",
    "spellbooks","You know better than to touch another sorceror's spellbooks, so\n"+
                 "you don't bother to look too closely at them",
    "shelves","Bookshelves, littered with magical paraphernalia, line the walls\n"+
              "of the chamber",
  });
  dest_dir = ({
    ROOMPATH+"tower3","leave",
  });
}


