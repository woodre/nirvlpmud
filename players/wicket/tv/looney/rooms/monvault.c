inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("montana", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/montana.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = YEL+"Montana Max"+"\'"+YEL+"s"+HIY+" Personal "+HIG+"Money"+NORM+" Vault"+NORM;
  long_desc = " An enormus vault that is made of solid gold. The floor cannot even be\n\
  seen from the amounts of money and gold thats piled high. Gems and\n\
  jewels of all shapes and sizes are mixed in the mounds and mounds\n\
  shimmering gold. All the riches in this room could probably fill\n\
  an olympic size swimming pool. Even the locks and knobs are made of\n\
  gold. The ceiling of the vault has chandeliers that hang from it that\n\
  keep the room well lit.\n";
  items = 
  ({
    "gold",
    "Piles upon piles of gold coins and bars",
    "vault",
    "Montana Max\'s personal vault to keep all his money",
    "locks",
    "Sold gold locks to protect the money inside",
    "gems",
    "Glistening rare gems and jewels of all shapes and sizes",
    "chandeliers",
    "Fancy hanging chandeliers made of solid crystal and gold that give off a glowing light",
  });
   dest_dir=({
  "/players/wicket/tv/looney/rooms/montanamansion.c","north",
  });
  }