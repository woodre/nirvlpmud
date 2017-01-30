#include <esc.h>
inherit "room/room";
reset(arg) {
   if(arg) return;
  set_light (1);
  short_desc = "The 51-room";
  long_desc = "In this room you see a table to play 51. It is\n"+
    "a very nice game, I can tell you that now. For more\n"+
    "information, it's the best to look at the table.\n";
  dest_dir=({"/players/hippo/rooms/nose","nose"});
  if(!present("51"))
  { move_object(clone_object("/players/hippo/games/fiftyone"),this_object());
    }
  if(!present("hoezullenwehemnoemen"))
{move_object(clone_object("/players/hippo/games/barman"),this_object());
}
  if(!present("bar"))
  {move_object(clone_object("/players/hippo/games/bar"),this_object());}
  }

realm(){return "NT";}
