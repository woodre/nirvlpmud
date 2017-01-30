inherit"/room/room";
#include <ansi.h>
#include "../def.h";

reset(arg)
{
::reset(arg);
  if(!present("hamton"))
    move_object(clone_object(MOB+"hamton.c"),this_object());
  if(!present("byron"))
    move_object(clone_object(MOB+"byron.c"),this_object());
if(arg)return;
  set_light(1);
  short_desc = HIM+"Hamton J"+NORM+"."+HIM+" Pig"+NORM+"\'"+HIM+"s"+NORM+" House"+NORM;
  long_desc = " A small hut built out of brick. The roof is made with small twigs that\n\
  are tied together. A small table sits across the corner from the entrance\n\
  of the door. The fireplace is lit and warming this small hut. Pictures of\n\
  Hampton\'s family are all around the room on the walls. A self portrait hangs\n\
  above the fireplace. An odd tv chair is sitting in front of a small tv with\n\
  the channel on. Food is thrown about all over the place. Straw is arranged\n\
  in a small bundle next to the window for a bed. A pillow and blanket are just\n\
  thrown on top of the bed.\n";
  items = 
  ({
    "bed",
    "A small bed made of straw", 
    "fireplace",
    "A stone fireplace with a small fire burning inside",
    "table",
    "A small wooden table with food stains all over it",
    "roof",
    "A small roof made of twigs that are tied together for protection from the elements",
    "portrait",
    "A family picture of Hampton\'s family",
    "tv",
    "A small television that has nothing on it but a fuzzy picture",
    "chair",
    "A small comfortable chair set in front of the tv to sit on",
    "straw",
    "A bundle of straw arranged in a pile to make a bed",
    "bed",
    "A bundle of straw arranged in a pile to make a bed",
    "food",
    "Food that his been thrown all over the house and made a mess",
    "pillow",
    "A small comfortable pillow used to sleep on the bed",
    "blanket",
    "A small blanket on the bed used to keep warm at night",
    
  });
    dest_dir=({
      ROOM+"toonroad3.c","east"
  });
  }