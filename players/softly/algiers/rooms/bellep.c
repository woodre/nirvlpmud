#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("Belle")){ 
    move_object(clone_object("players/softly/algiers/mobs/belle.c"),this_object());
  }
  if(!present("Peacie")){ 
    move_object(clone_object("players/softly/algiers/mobs/peacie.c"),this_object());
  }
 if(!present("Charisse")){ 
    move_object(clone_object("players/softly/algiers/mobs/charisse.c"),this_object());
  }

  if(arg) return;
  set_light(1);
  add_smell("room","The scent of perfume hangs in the air.");
  short_desc = "Belle's Parlor";
  long_desc ="\n"+
"  The open room is papered in gold and red flocked wallpaper.\n\
A dark red velvet sofa with a dark wood frame is flanked by\n\
two matching red velvet chairs.  Window shades and drapes are\n\
drawn over the windows.  The east side of the room holds a\n\
sideboard centered with a vase filled with seasonal flowers.\n\
A plush oriental carpet lines the floor.\n";

  items = ({
    "flowers", 
    "Showy seasonal flowers fill a crystal vase to overflowing",
    "floor", 
    "The edges of the polished wooden floor show around\n\
the oriental carpet",
    "carpet",
    "A thick oriental carpet of red and black covers the floor",
    "room",
    "An ornate plushly furnished room with comfortable seating",
    "wallpaper",
    "The wallpaper has a large pattern of red and gold flocking",
    "sofa",
    "A high backed sofa with a mahogony carved wooden frame is\n\
upholstered in red velvet.  It looks deep and comfortable",
    "chairs",
    "The two wood framed chairs are plushly covered with\n\
dark red velvet.  They look inviting",
    "shades",
    "White window shades block any outside view of the room",
    "drapes",
    "Opulent white satin drapes frame the windows",
    "windows",
    "The windows are covered with white",
    "sideboard",
    "A mahogony cabinet is polished to a high gloss.  It\n\
holds a crystal vase filled with flowers",
    "vase",
    "A large cut glass vase is filled to overflowing with an\n\
assortment of seasonal flowers",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road14.c","west",
  });
}
